cmake_minimum_required(VERSION 3.3)
project(GraphAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp dfs.cpp dfs.h)
add_executable(GraphAlgorithms ${SOURCE_FILES})