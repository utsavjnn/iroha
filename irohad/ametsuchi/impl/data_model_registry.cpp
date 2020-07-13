/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */



namespace iroha{
    namespace ametsuchi{
        void DataModelRegistry::registerModule(std::unique_ptr<DataModelId> register){
            //module_type_registry_.emplace(std::make_pair(register->getName,register->getVersion),*registry);
            module_registry_.emplace_back(std::move(registry));
        }
    }
}