/* Copyright (c) 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_PRIVATE_NEW_TAB_UI_COMMON_PREF_NAMES_H_
#define BRAVE_COMPONENTS_BRAVE_PRIVATE_NEW_TAB_UI_COMMON_PREF_NAMES_H_

class PrefRegistrySimple;

namespace brave_private_new_tab::prefs {

constexpr char kBravePrivateWindowDisclaimer[] =
    "brave.brave_private_new_tab.has_seen_disclaimer";
constexpr char kBraveTorWindowDisclaimer[] =
    "brave.brave_private_new_tab.has_seen_disclaimer_tor";

void RegisterProfilePrefs(PrefRegistrySimple* registry);

}  // namespace brave_private_new_tab::prefs

#endif  // BRAVE_COMPONENTS_BRAVE_PRIVATE_NEW_TAB_UI_COMMON_PREF_NAMES_H_
