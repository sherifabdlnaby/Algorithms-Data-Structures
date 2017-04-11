cmake_minimum_required(VERSION 3.6)
project(BFS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.h UDCC.h)
add_executable(BFS ${SOURCE_FILES})