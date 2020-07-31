/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "ametsuchi/data_models/data_model_registry.hpp"

#include "ametsuchi/data_models/data_model.hpp"

using namespace iroha::ametsuchi;

namespace {
  void executeForEach(std::vector<std::unique_ptr<DataModel>> &modules,
                      void (DataModel::*func)()) {
    for (auto &module : modules) {
      (module.get()->*func)();
    }
  }
}  // namespace

void DataModelRegistry::resetState(){
            executeForEach(modules_, &DataModel::resetState);
        }

void DataModelRegistry::registerModule(std::unique_ptr<DataModel> dm_module) {
  for (auto const &dm_id : dm_module->getSupportedDataModelIds()) {
    module_by_dm_id_.emplace(dm_id, *dm_module);
  }
  modules_.emplace_back(std::move(dm_module));
}

CommandResult DataModelRegistry::execute(
    shared_model::proto::CallModel const &command) {
  shared_model::interface::DataModelId id{command.name(), command.version()};
  auto it = module_by_dm_id_.find(id);
  if (it == module_by_dm_id_.end()) {
    return iroha::expected::makeError(
        iroha::ametsuchi::CommandError{"CallModel", 1, "unknown data model"});
  }
  return it->second.get().execute(command);
}



void DataModelRegistry::rollbackBlock() {
  executeForEach(modules_, &DataModel::rollbackBlock);
}

void DataModelRegistry::rollbackTransaction() {
  executeForEach(modules_, &DataModel::rollbackTransaction);
}

void DataModelRegistry::commitBlock() {
  executeForEach(modules_, &DataModel::commitBlock);
}

void DataModelRegistry::commitTransaction() {
  executeForEach(modules_, &DataModel::commitTransaction);
}
