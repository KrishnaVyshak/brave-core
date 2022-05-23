/* Copyright 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_BRAVE_TALK_BRAVE_TALK_SERVICE_H_
#define BRAVE_BROWSER_BRAVE_TALK_BRAVE_TALK_SERVICE_H_

#include <string>

#include "base/callback_forward.h"
#include "components/keyed_service/core/keyed_service.h"
#include "content/public/browser/render_frame_host.h"
#include "content/public/browser/web_contents_observer.h"

namespace content {
class WebContents;
}

namespace brave_talk {
class BraveTalkService : public KeyedService, content::WebContentsObserver {
 public:
  BraveTalkService();
  BraveTalkService(const BraveTalkService&) = delete;
  BraveTalkService& operator=(const BraveTalkService&) = delete;
  ~BraveTalkService() override;

  void GetDeviceID(content::WebContents* contents,
                   int owning_process_id,
                   int owning_frame_id,
                   base::OnceCallback<void(const std::string&)> callback);
  void OnGetDeviceIDRequestedForTesting(
      base::OnceCallback<void()> callback_for_testing);

  void DidStartNavigation(content::NavigationHandle* handle) override;

  void ShareTab(content::WebContents* target_contents);

  bool is_requesting_tab() { return !on_received_device_id_.is_null(); }

 private:
  void StartObserving(content::WebContents* contents);
  void StopObserving();

  int owning_render_frame_id_;
  int owning_render_process_id_;
  base::OnceCallback<void(const std::string&)> on_received_device_id_;
  base::OnceCallback<void()> on_get_device_id_requested_for_testing_;
};
}  // namespace brave_talk

#endif  // BRAVE_BROWSER_BRAVE_TALK_BRAVE_TALK_SERVICE_H_
