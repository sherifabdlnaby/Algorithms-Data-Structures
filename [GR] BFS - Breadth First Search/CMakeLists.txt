cmake_minimum_required(VERSION 3.6)
project(BFS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.cpp Graph.h BFS.h)
add_executable(BFS ${SOURCE_FILES})