cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 14)



add_executable(const_test grammar/c/const_test.c)
add_executable(size_test grammar/cpp/size_test.cpp)
add_executable(align "res/C++PrimerPlus/Appendix E/align.cpp")
add_executable(rain res/CPrimerPlus/Ch10/rain.c)
add_executable(array2d res/CPrimerPlus/Ch10/array2d.c)
add_executable(multidimensional_array_announce grammar/c/multidimensional_array_announce_test.c)
add_executable(vararr2d res/CPrimerPlus/Ch10/vararr2d.c)
add_executable(pointer_test grammar/c/pointer_test.cpp)
add_executable(mem_test grammar/c/mem_test.c)