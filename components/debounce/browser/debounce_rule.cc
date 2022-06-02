/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/debounce/browser/debounce_rule.h"

#include <memory>
#include <utility>
#include <vector>

#include "base/base64url.h"
#include "base/strings/stringprintf.h"
#include "components/prefs/pref_service.h"
#include "content/public/browser/browser_thread.h"
#include "extensions/common/url_pattern.h"
#include "net/base/url_util.h"
#include "third_party/re2/src/re2/re2.h"
#include "url/gurl.h"
#include "url/origin.h"
#include "url/url_constants.h"

namespace {
// debounce.json keys
const char kInclude[] = "include";
const char kExclude[] = "exclude";
const char kAction[] = "action";
const char kPrependScheme[] = "prepend_scheme";
const char kParam[] = "param";
const char kPref[] = "pref";
}  // namespace

namespace debounce {

DebounceRule::DebounceRule()
    : action_(kDebounceNoAction), prepend_scheme_(kDebounceNoSchemePrepend) {}

DebounceRule::~DebounceRule() = default;

// static
bool DebounceRule::ParseDebounceAction(base::StringPiece value,
                                       DebounceAction* field) {
  if (value == "redirect") {
    *field = kDebounceRedirectToParam;
  } else if (value == "base64,redirect") {
    *field = kDebounceBase64DecodeAndRedirectToParam;
  } else if (value == "regex-path") {
    *field = kDebounceRegexPath;
  } else {
    LOG(WARNING) << "Found unknown debouncing action: " << value;
    return false;
  }
  return true;
}

// static
bool DebounceRule::ParsePrependScheme(base::StringPiece value,
                                      DebouncePrependScheme* field) {
  if (value == "http") {
    *field = kDebounceSchemePrependHttp;
  } else if (value == "https") {
    *field = kDebounceSchemePrependHttps;
  } else {
    LOG(WARNING) << "Found unknown scheme: " << value;
    return false;
  }
  return true;
}

// static
bool DebounceRule::GetURLPatternSetFromValue(
    const base::Value* value,
    extensions::URLPatternSet* result) {
  if (!value->is_list())
    return false;
  // Debouncing only affects HTTP or HTTPS URLs, regardless of how the rules are
  // written. (Also, don't write rules for other URL schemes, because they won't
  // work and you're just wasting everyone's time.)
  std::string error;
  bool valid = result->Populate(
      base::Value::AsListValue(*value),
      URLPattern::SCHEME_HTTP | URLPattern::SCHEME_HTTPS, false, &error);
  if (!valid)
    LOG(WARNING) << error;
  return valid;
}

// static
void DebounceRule::RegisterJSONConverter(
    base::JSONValueConverter<DebounceRule>* converter) {
  converter->RegisterCustomValueField<extensions::URLPatternSet>(
      kInclude, &DebounceRule::include_pattern_set_, GetURLPatternSetFromValue);
  converter->RegisterCustomValueField<extensions::URLPatternSet>(
      kExclude, &DebounceRule::exclude_pattern_set_, GetURLPatternSetFromValue);
  converter->RegisterCustomField<DebounceAction>(
      kAction, &DebounceRule::action_, &ParseDebounceAction);
  converter->RegisterCustomField<DebouncePrependScheme>(
      kPrependScheme, &DebounceRule::prepend_scheme_, &ParsePrependScheme);
  converter->RegisterStringField(kParam, &DebounceRule::param_);
  converter->RegisterStringField(kPref, &DebounceRule::pref_);
}

// static
const std::string DebounceRule::GetETLDForDebounce(const std::string& host) {
  return net::registry_controlled_domains::GetDomainAndRegistry(
      host, net::registry_controlled_domains::PrivateRegistryFilter::
                EXCLUDE_PRIVATE_REGISTRIES);
}

// static
void DebounceRule::ParseRules(base::Value::List root,
                              std::vector<std::unique_ptr<DebounceRule>>* rules,
                              base::flat_set<std::string>* host_cache) {
  DCHECK(!content::BrowserThread::CurrentlyOn(content::BrowserThread::UI));
  std::vector<std::string> hosts;
  base::JSONValueConverter<DebounceRule> converter;
  for (base::Value& it : root) {
    std::unique_ptr<DebounceRule> rule = std::make_unique<DebounceRule>();
    if (!converter.Convert(it, rule.get()))
      continue;
    for (const URLPattern& pattern : rule->include_pattern_set()) {
      if (!pattern.host().empty()) {
        const std::string etldp1 =
            DebounceRule::GetETLDForDebounce(pattern.host());
        if (!etldp1.empty())
          hosts.push_back(std::move(etldp1));
      }
    }
    rules->push_back(std::move(rule));
  }
  *host_cache = std::move(hosts);
}

bool DebounceRule::CheckPrefForRule(const PrefService* prefs) const {
  // Check pref specified in rules, if any
  if (!pref_.empty()) {
    auto* pref = prefs->FindPreference(pref_);
    if (!pref) {
      LOG(WARNING) << "Pref specified in debounce.json not valid: " << pref_;
      return false;
    }
    if (!pref->GetValue()->GetBool()) {
      LOG(INFO) << "Pref " << pref->name()
                << " specified in debounce.json is false";
      return false;
    }
  }
  return true;
}

bool DebounceRule::Apply(const GURL& original_url,
                         GURL* final_url,
                         const PrefService* prefs) const {
  // Unknown actions always return false, to allow for future updates to the
  // rules file which may be pushed to users before a new version of the code
  // that parses it.
  if (action_ != kDebounceRedirectToParam &&
      action_ != kDebounceBase64DecodeAndRedirectToParam &&
      action_ != kDebounceRegexPath)
    return false;
  // If URL matches an explicitly excluded pattern, this rule does not apply.
  if (exclude_pattern_set_.MatchesURL(original_url))
    return false;
  // If URL does not match an explicitly included pattern, this rule does not
  // apply.
  if (!include_pattern_set_.MatchesURL(original_url))
    return false;

  if (!DebounceRule::CheckPrefForRule(prefs)) {
    return false;
  }

  std::string unescaped_value;

  if (action_ == kDebounceRegexPath) {
    // Important: Apply param regex to ONLY the path of original URL.
    auto path = original_url.path();
    const re2::RE2 pattern_regex(param_);
    if (!pattern_regex.ok()) {
      LOG(WARNING) << "Debounce rule has param: " << param_
                   << " which is an invalid regex pattern";
      return false;
    }
    if (pattern_regex.NumberOfCapturingGroups() != 1) {
      LOG(WARNING) << "Debounce rule has param: " << param_
                   << " which captures != 1 groups";
      return false;
    }
    if (!RE2::PartialMatch(path, pattern_regex, &unescaped_value)) {
      LOG(INFO) << "Debounce rule with param: " << param_
                << " was unable to capture string despite match";
      return false;
    }

    // unescaped_value now has a string; we will check if the captured value is
    // a valid URL down below
  } else {
    if (!net::GetValueForKeyInQuery(original_url, param_, &unescaped_value))
      return false;
    if ((action_ == kDebounceBase64DecodeAndRedirectToParam) &&
        (!base::Base64UrlDecode(unescaped_value,
                                base::Base64UrlDecodePolicy::IGNORE_PADDING,
                                &unescaped_value))) {
      return false;
    }
  }

  GURL new_url(unescaped_value);
  // Important: If there is a prepend_scheme in the rule BUT the URL is already
  // valid i.e. has a scheme, we treat this as an erroneous rule and do not
  // apply it.
  if (prepend_scheme_ && new_url.is_valid()) {
    LOG(WARNING) << "Debounce rule with param: " << param_
                 << " and prepend scheme " << prepend_scheme_
                 << " got a valid URL, treating as erroneous rule";
    return false;
  }
  // If there is a prepend_scheme specified AND the URL is not valid, prepend
  // the specified scheme and try again
  if (prepend_scheme_ && !new_url.is_valid()) {
    std::string scheme = (prepend_scheme_ == kDebounceSchemePrependHttp)
                             ? url::kHttpScheme
                             : url::kHttpsScheme;
    auto new_url_spec =
        base::StringPrintf("%s://%s", scheme.c_str(), unescaped_value.c_str());
    new_url = GURL(new_url_spec);
  }

  // Failsafe: ensure we got a valid URL out of the param.
  if (!new_url.is_valid() || !new_url.SchemeIsHTTPOrHTTPS())
    return false;

  // Failsafe: never redirect to the same site.
  if (url::IsSameOriginWith(original_url, new_url))
    return false;

  *final_url = new_url;
  return true;
}

}  // namespace debounce
