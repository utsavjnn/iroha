/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "ametsuchi/data_models/data_model_registry.hpp"

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
            for(auto it=modules_.begin();it!=modules_.end();it++)
                it->rollback_block();
        }

        void DataModelRegistry::rollback_transaction(){
            for(auto it=modules_.begin();it!=modules_.end();it++)
                it->rollback_transaction();
        }

        void DataModelRegistry::commit_block(){
            for(auto it=modules_.begin();it!=modules_.end();it++)
                it->commit_block();
        }

        void DataModelRegistry::commit_transaction(){
            for(auto it=modules_.begin();it!=modules_.end();it++)
                it->commit_transaction();
        }

    }
}