/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "ametsuchi/impl/data_model_registry.hpp"

namespace iroha{
    namespace ametsuchi{
        void DataModelRegistry::registerModule(std::unique_ptr<DataModel> dm_module){
            for (auto const &dm_id : dm_module->getSupportedDmIds()) {
                module_by_dm_id_.emplace_back(dm_id, *dm_module);
                }
            modules_.emplace_back(std::move(dm_module));
        }

        CommandResult DataModelRegistry::execute(shared_model::proto::CallModel &command)const{
            auto it = executors.find(cmd.getTransport().dm_id());
            if (it == executors.end()) {
                return makeError("unknown data model");
            }
            return it->second->execute(cmd);
        }

        void DataModelRegistry::rollback_block(){
            return modules_[modules_.size()-1]->rollback_block();
        }

        void DataModelRegistry::rollback_transaction(){
            return modules_[modules_.size()-1]->rollback_transaction();
        }

        void DataModelRegistry::commit_block(){
            return modules_[modules_.size()-1]->commit_block();
        }

        void DataModelRegistry::commit_transaction(){
            return modules_[modules_.size()-1]->commit_transaction();
        }

    }
}