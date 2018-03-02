cmake_minimum_required(VERSION 3.6)
project(Graph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.h)
add_executable(main ${SOURCE_FILES})