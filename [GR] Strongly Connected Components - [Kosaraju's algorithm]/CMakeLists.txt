cmake_minimum_required(VERSION 3.6)
project(SCC)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.h SCC.h)
add_executable(SCC ${SOURCE_FILES})