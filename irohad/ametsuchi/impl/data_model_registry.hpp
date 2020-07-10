/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_DATA_MODEL_REGISTRY_HPP
#define IROHA_DATA_MODEL_REGISTRY_HPP

#include <map>
#include <string>
#include <pair>
#include <vector>
#include <functional>

#include "ametsuchi/command_executor.hpp"
#include "shared_model/backend/protobuf/commands/impl/proto_call_model.hpp"

namespace iroha{
    namespace ametsuchi {
        class DataModelRegistry {
            public:
                void registerModule(std::unique_ptr<DataModelModule> register);

                CommandResult execute(shared_model::proto::CallModel &command)const; 
                

            private:
                std::map<std::pair<std::string,string::string>,std::reference_wrapper<DataModelModule>> module_type_registry_;
                std::vector<std::unique_ptr<DataModelModule>> module_registry_;
        };
    }
}

#endif