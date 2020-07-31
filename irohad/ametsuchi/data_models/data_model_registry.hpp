/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_AMETSUCHI_DATA_MODEL_REGISTRY_HPP
#define IROHA_AMETSUCHI_DATA_MODEL_REGISTRY_HPP

#include <functional>
#include <unordered_map>
#include <vector>

#include "ametsuchi/command_executor.hpp"
#include "backend/protobuf/commands/proto_call_model.hpp"
#include "interfaces/common_objects/data_model_id.hpp"

namespace iroha::ametsuchi {
  class DataModel;

  class DataModelRegistry {
   public:
    void registerModule(std::unique_ptr<DataModel> dm_module);

    CommandResult execute(shared_model::proto::CallModel const &command);

    void rollbackBlock();

    void rollbackTransaction();

    void commitBlock();

    void commitTransaction();

    void resetState();
   private:
    std::unordered_map<shared_model::interface::DataModelId,
                       std::reference_wrapper<DataModel>,
                       shared_model::interface::DataModelId::Hasher>
        module_by_dm_id_;
    std::vector<std::unique_ptr<DataModel>> modules_;
  };
}  // namespace iroha::ametsuchi

#endif  // IROHA_AMETSUCHI_DATA_MODEL_REGISTRY_HPP
