cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 14)


add_executable(string_test Grammar/C/string_test.cpp)
add_executable(var_test Grammar/C/var_test.cpp)
add_executable(size_test grammar/C/size_test.cpp)
add_executable(modifier_test Grammar/C/modifier_test.cpp)
add_executable(priority_test Grammar/C/priority_test.cpp)
add_executable(operator Grammar/C/operator_test.cpp)
add_executable(logical_test Grammar/C/logical_test.cpp)
add_executable(control_test Grammar/C/control_test.cpp)
add_executable(file_test Grammar/C/file_test.cpp)
add_executable(function_test Grammar/C/function_test.cpp)
add_executable(input_test Grammar/C/input_test.cpp)
add_executable(pointer_test Grammar/C/pointer_test.cpp)
add_executable(array_test Grammar/C/array_test.c)
#add_executable(a Work/3.25/a.cpp)
#add_executable(b Work/3.25/b.cpp)


add_executable(LQ_4.18_A Contest/LQ/4.18/LQ_4.18_A.cpp)
add_executable(LQ_4.18_B Contest/LQ/4.18/LQ_4.18_B.cpp)
add_executable(LQ_4.18_C Contest/LQ/4.18/LQ_4.18_C.cpp)
add_executable(LQ_4.18_D Contest/LQ/4.18/LQ_4.18_D.cpp)

add_executable(output_test grammar/C/output_test.c)
add_executable(const_test Grammar/C/const_test.c)