/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_PROTO_QUERY_MODEL_H
#define IROHA_PROTO_QUERY_MODEL_H

#include "interfaces/queries/query_model.hpp"

#include "queries.pb.h"

namespace shared_model {
  namespace proto {
    class QueryModel : public interface::QueryModel {
     public:
        explicit QueryModel(iroha::protocol::QueryModel &query);

        virtual ~QueryModel();

        const std::string &name() const ;

        const std::string &version() const ;

        const iroha::protocol::QueryModel &getQueryModel() const;

        bool operator==(const QueryModel &rhs) const;

     private:
      // ------------------------------| fields |-------------------------------
      const iroha::protocol::QueryModel &query_model_;
    };

  }  // namespace proto
}  // namespace shared_model

#endif 
