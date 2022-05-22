/* Copyright (c) 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_talk/browser/brave_talk_frame_host.h"

#include <string>
#include <utility>

#include "absl/types/optional.h"
#include "base/bind.h"
#include "base/logging.h"
#include "brave/browser/brave_talk/brave_talk_service.h"
#include "brave/browser/brave_talk/brave_talk_service_factory.h"
#include "brave/components/brave_search/browser/brave_search_default_host.h"
#include "brave/components/brave_talk/common/features.h"
#include "build/build_config.h"
#include "chrome/browser/bad_message.h"
#include "components/prefs/pref_registry_simple.h"
#include "components/prefs/pref_service.h"
#include "content/browser/bad_message.h"
#include "content/browser/renderer_host/frame_tree_node.h"
#include "content/browser/renderer_host/render_frame_host_impl.h"
#include "content/public/browser/browser_context.h"
#include "content/public/browser/render_frame_host.h"
#include "content/public/browser/web_contents.h"
#include "third_party/blink/public/common/tokens/tokens.h"

namespace brave_talk {

BraveTalkFrameHost::BraveTalkFrameHost(content::WebContents* contents,
                                       const std::string& host)
    : contents_(contents), host_(host) {}

BraveTalkFrameHost::~BraveTalkFrameHost() = default;

void BraveTalkFrameHost::BeginAdvertiseShareDisplayMedia(
    const absl::optional<::blink::FrameToken>& frame_token,
    BeginAdvertiseShareDisplayMediaCallback callback) {
  auto* service =
      BraveTalkServiceFactory::GetForContext(contents_->GetBrowserContext());

  auto* frame = FindFrameForToken(frame_token);
  if (!frame) {
    std::move(callback).Run("");
    return;
  }

  service->GetDeviceID(contents_, frame->GetProcess()->GetID(),
                       frame->GetRoutingID(), std::move(callback));
}

content::RenderFrameHost* BraveTalkFrameHost::FindFrameForToken(
    const absl::optional<::blink::FrameToken>& frame_token) {
  auto* main_frame =
      static_cast<content::RenderFrameHostImpl*>(contents_->GetMainFrame());
  if (!frame_token)
    return main_frame;

  auto* frame_tree_node = main_frame->FindAndVerifyChild(frame_token.value(), content::bad_message::BadMessageReason::RWH_INVALID_FRAME_TOKEN);
  if (!frame_tree_node)
    return nullptr;

  return frame_tree_node->current_frame_host();
}

}  // namespace brave_talk
