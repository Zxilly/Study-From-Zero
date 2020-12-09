cmake_minimum_required(VERSION 3.17)
project(C C)

set(CMAKE_C_STANDARD 11)

add_executable(C main.c)
add_executable(ll1 datastruct/list/linked_list/ll1.c)
add_executable(sl1 datastruct/list/sequence_list/sl1.c)
add_executable(stack datastruct/stack/stack.c)
add_executable(queue datastruct/queue/queue.c)
add_executable(baseConversation datastruct/stack/baseConversation.c)
add_executable(a experiment/a.c)
add_executable(string datastruct/string/string.c)