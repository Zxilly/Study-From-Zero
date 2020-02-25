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
add_executable(file_test grammar/file_test.cpp)
add_executable(function_test grammar/function_test.cpp)
add_executable(input_test grammar/input_test.cpp)
add_executable(pointer_test grammar/pointer_test.cpp)
add_executable(array_test grammar/array_test.c)