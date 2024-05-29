cmake_minimum_required(VERSION 3.28)
project(homelib C)

set(CMAKE_C_STANDARD 11)

add_library(homelib STATIC library.c
        src/array.c
        src/map.c
        test/test_homelib.c
        test/test_homelib.h
        src/unordered_map.c
        include/unordered_map.h
        include/stack.h
        src/stack.c
        include/queue.h
        src/queue.c
        include/set.h
        src/set.c
)
