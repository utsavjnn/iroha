/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_DATA_MODEL_REGISTRY_HPP
#define IROHA_DATA_MODEL_REGISTRY_HPP

#include <unordered_map>
#include <string>
#include <vector>
#include <functional>

#include "ametsuchi/command_executor.hpp"
#include "shared_model/backend/protobuf/commands/impl/proto_call_model.hpp"
#include "shared_model/interfaces/common_objects/data_model_id.hpp"

namespace iroha{
    namespace ametsuchi {
        class DataModelRegistry {
            public:
                void registerModule(std::unique_ptr<DataModel> dm_module);

                CommandResult execute(shared_model::proto::CallModel &command)const; 
                
                void rollback_block();

                void rollback_transaction();

                void commit_block();

                void commit_transaction();
            private:
                std::unordered_map<DataModelId,std::reference_wrapper<DataModel>> module_by_dm_id_;
                std::vector<std::unique_ptr<DataModel>> modules_;
        };
    }
}

#endif