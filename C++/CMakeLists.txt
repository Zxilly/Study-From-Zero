cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 14)


add_executable(string_test grammar/string_test.cpp)
add_executable(var_test grammar/var_test.cpp)
add_executable(size_test grammar/size_test.cpp)
add_executable(modifier_test grammar/modifier_test.cpp)