cmake_minimum_required(VERSION 3.3)
project(Sorting)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sort.h sort.cpp sort.h)
add_executable(Sorting ${SOURCE_FILES} sort.h)