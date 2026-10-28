cmake_minimum_required(VERSION 4.2)
project(deque C)

set(CMAKE_C_STANDARD 11)

add_executable(deque main.c deque_on_list.c linked_list.c)
