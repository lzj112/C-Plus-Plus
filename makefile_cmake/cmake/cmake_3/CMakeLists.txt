cmake_minimum_required (VERSION 3.0)
project (test_3)

add_subdirectory(src)

add_definitions("-g -Wall -std=c++11")

add_executable(main main.cpp)
target_link_libraries(main TEST3)
