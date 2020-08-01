/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "backend/protobuf/queries/proto_query_model.hpp"

namespace shared_model {
    namespace proto {
        QueryModel::QueryModel(iroha::protocol::QueryModel &query)
                : query_model_{query} {}
        
        QueryModel::~QueryModel() = default;

        const std::string &QueryModel::name() const {
            const iroha::protocol::DataModelId &dm_id = query_model_.dm_id();
            return dm_id.name();
        }

        const std::string &QueryModel::version() const {
            const iroha::protocol::DataModelId &dm_id = query_model_.dm_id();
            return dm_id.version();
        }

        const iroha::protocol::QueryModel &QueryModel::getQueryModel() const {
            return query_model_;
        }

        bool QueryModel::operator==(const QueryModel &rhs) const {
            return (name() == rhs.name() && version() == rhs.version());
        }
        
    }  // namespace proto
}  // namespace shared_model
