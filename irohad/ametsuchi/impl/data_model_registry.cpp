/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "ametsuchi/impl/data_model_registry.hpp"

namespace iroha{
    namespace ametsuchi{
        void DataModelRegistry::registerModule(std::unique_ptr<DataModelModule> register){
            module_type_registry_.emplace(std::make_pair(register->getName,register->getVersion),*registry);
            module_registry_.emplace_back(std::move(registry));
        }
    }
}