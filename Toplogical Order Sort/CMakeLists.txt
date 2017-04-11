cmake_minimum_required(VERSION 3.6)
project(ToplogicalOrder)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.h ToplogicalOrder.h)
add_executable(ToplogicalOrder ${SOURCE_FILES})