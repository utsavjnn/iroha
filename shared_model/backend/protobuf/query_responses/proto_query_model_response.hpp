/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_SHARED_MODEL_PROTO_QUERY_MODEL_RESPONSE_HPP
#define IROHA_SHARED_MODEL_PROTO_QUERY_MODEL_RESPONSE_HPP

#include "interfaces/query_responses/query_model_response.hpp"

#include "qry_responses.pb.h"

namespace shared_model {
  namespace proto {
    class QueryModelResponse : public interface::QueryModelResponse {
     public:

      using TransportType = iroha::protocol::QueryResponse;

      explicit QueryModelResponse(TransportType &proto);

      const iroha::protocol::QueryModelResponse &getTransport() const;

     private:
      const iroha::protocol::QueryModelResponse &query_model_response_;
    };
  }  // namespace proto
}  // namespace shared_model

#endif  
