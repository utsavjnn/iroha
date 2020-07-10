/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "ametsuchi/impl/data_model_registry.hpp"


namespace iroha{
    namespace ametsuchi{
        DataModelModule::DataModelModule(std::string &name,std::string &version)
            : name_{name},version_{version} {}

        const std::string &DataModelModule::getName() const {
            return name_;
        }

        const std::string &DataModelModule::getVersion() const {
            return version_;
        }
    }
}
