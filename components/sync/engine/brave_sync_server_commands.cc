/* Copyright (c) 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/sync/engine/brave_sync_server_commands.h"

#include "base/callback.h"
#include "base/logging.h"
#include "base/sequence_checker.h"
#include "components/sync/engine/syncer_proto_util.h"
#include "components/sync/protocol/sync.pb.h"

namespace syncer {

namespace {

void InitClearServerDataContext(SyncCycle* cycle,
                                sync_pb::ClientToServerMessage* message) {
  message->set_share(cycle->context()->account_name());
  message->set_message_contents(
      sync_pb::ClientToServerMessage::CLEAR_SERVER_DATA);
  sync_pb::ClearServerDataMessage* clear_server_data =
      message->mutable_clear_server_data();
  clear_server_data->set_disable_sync_chain(true);
}

}  // namespace

void BraveSyncServerCommands::PermanentlyDeleteAccount(
    SyncCycle* cycle,
    base::OnceClosure callback) {
  sync_pb::ClientToServerMessage message;
  InitClearServerDataContext(cycle, &message);
  SyncerProtoUtil::AddRequiredFieldsToClientToServerMessage(cycle, &message);

  sync_pb::ClientToServerResponse response;
  const SyncerError post_result = SyncerProtoUtil::PostClientToServerMessage(
      message, &response, cycle, nullptr);

  if (post_result.value() != SyncerError::SYNCER_OK) {
    LOG(WARNING) << "Post ClearServerData failed post_result.value()="
                 << post_result.value();
  }

  if (response.has_error_code()) {
    LOG(WARNING) << "[BraveSync] " << __func__
                 << " response.error_code()=" << response.error_code();
  } else {
    LOG(WARNING) << "[BraveSync] " << __func__ << " no response.error_code()";
  }

  if (response.has_error_message()) {
    LOG(WARNING) << "[BraveSync] " << __func__
                 << " response.error_message()=" << response.error_message();
  } else {
    LOG(WARNING) << "[BraveSync] " << __func__
                 << " no response.error_message()";
  }

  std::move(callback).Run();
}

}  // namespace syncer
