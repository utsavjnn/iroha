/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "backend/protobuf/query_responses/proto_query_model_response.hpp"

namespace shared_model {
  namespace proto {

    QueryModelResponse::QueryModelResponse(iroha::protocol::QueryResponse &query_response)
        : query_model_response_{query_response.query_model_response()} {}

    const iroha::protocol::QueryModelResponse &QueryModelResponse::getTransport() const{
        return query_model_response_;
    }

    

  }  // namespace proto
}  // namespace shared_model
