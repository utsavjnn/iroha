/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_SHARED_MODEL_PROTO_REGISTER_DATA_MODEL_HPP
#define IROHA_SHARED_MODEL_PROTO_REGISTER_DATA_MODEL_HPP

#include "interfaces/commands/register_data_model.hpp"

#include "commands.pb.h"

namespace shared_model::proto {
  class RegisterDataModel : public shared_model::interface::RegisterDataModel {
   public:
    explicit RegisterDataModel(iroha::protocol::Command &command);

    virtual ~RegisterDataModel();

    const iroha::protocol::RegisterDataModel &getTransport() const;

   private:
    const iroha::protocol::RegisterDataModel &register_data_model_;
  };
}  // namespace shared_model::proto

#endif