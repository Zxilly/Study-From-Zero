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
add_executable(scope_test grammar/c/memory/scope_test.c)
add_executable(static_in_function_test grammar/c/memory/static_in_function_test.c)
add_executable(auto_test "grammar/c/memory/auto(c)_test.c")
add_executable(register grammar/c/memory/register.c)
add_executable(extern_test grammar/c/memory/extern_test.c)
add_executable(static_test grammar/c/memory/static_test.c)
add_executable(ansi_type_restrict grammar/c/memory/ansi_type_restrict.c)
add_executable(restrict_test grammar/c/memory/restrict_test.c)
add_executable(atomic_test grammar/c/memory/atomic_test.c)
add_executable(p1042 contest/Luogu/p1042.cpp)