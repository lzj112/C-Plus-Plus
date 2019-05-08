
cmake_minimum_required(VERSION 3.0)
project(test_2)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_definitions("-g -Wall -std=c++11")

add_executable(test_print
               ${PROJECT_SOURCE_DIR}/src/main.cpp 
               ${PROJECT_SOURCE_DIR}/src/person.cc)