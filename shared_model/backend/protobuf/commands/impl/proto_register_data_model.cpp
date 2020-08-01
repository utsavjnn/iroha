/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "backend/protobuf/commands/proto_register_data_model.hpp"
#include "commands.pb.h"

namespace shared_model {
  namespace proto {

    RegisterDataModel::RegisterDataModel(iroha::protocol::Command &command)
        : register_data_model_{command.register_data_model()} {}

    RegisterDataModel::~RegisterDataModel() = default;

    const iroha::protocol::RegisterDataModel &RegisterDataModel::getTransport() const {
      return register_data_model_;
    }

  }  // namespace proto
}  // namespace shared_model