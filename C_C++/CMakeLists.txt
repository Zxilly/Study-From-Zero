cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 14)




add_executable(b homework/experiment/b.c)
add_executable(qsort logic/algorithm/sort/qsort.c)
add_executable(ctype_test grammar/c/ctype_test.c)

add_executable(arg_test grammar/c/arg_test.c)
add_executable(const_test grammar/c/const_test.c)
add_executable(mem_test grammar/c/memory/mem_test.c)
add_executable(main main.c)
add_executable(kmp logic/algorithm/kmp/kmp.c)