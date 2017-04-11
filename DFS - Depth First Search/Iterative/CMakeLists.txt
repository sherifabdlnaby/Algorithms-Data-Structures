cmake_minimum_required(VERSION 3.6)
project(DFS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.cpp Graph.h DFS.h)
add_executable(DFS ${SOURCE_FILES})