cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 14)


add_executable(string_test grammar/string_test.cpp)
add_executable(var_test grammar/var_test.cpp)
add_executable(size_test grammar/size_test.cpp)
add_executable(modifier_test grammar/modifier_test.cpp)
add_executable(priority_test grammar/priority_test.cpp)
add_executable(operator grammar/operator_test.cpp)
add_executable(logical_test grammar/logical_test.cpp)
add_executable(control_test grammar/control_test.cpp)