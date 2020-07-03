find_package(Python3 REQUIRED COMPONENTS Interpreter)

set(PYBIND11_PYTHON_VERSION 3)
set(PYTHON_EXECUTABLE:FILEPATH ${Python3_EXECUTABLE})

find_package(pybind11 CONFIG REQUIRED)

add_library(data_model_adapter_python data_model_python.cpp)

target_compile_options(data_model_adapter_python
  PRIVATE
    -fsized-deallocation
  )

target_link_libraries(data_model_adapter_python
  pybind11::embed
  )

