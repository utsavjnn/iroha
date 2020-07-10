/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_DATA_MODEL_MODULE_HPP
#define IROHA_DATA_MODEL_MODULE_HPP

#include<string>

namespace iroha{
    namespace ametsuchi
    {
        class DataModelModule{
            public:
                explicit DataModelModule(std::string &name,std::string &version);

                const std::string &getName() const;

                const std::string &getVersion() const;

            
            private:
                const std::string &name_;
                const std::string &version_;

        };
    } // namespace ametsuchi
} //namespace iroha