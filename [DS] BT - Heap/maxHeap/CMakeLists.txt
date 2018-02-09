cmake_minimum_required(VERSION 3.6)
project(Heap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp heap.h)
add_executable(Heap ${SOURCE_FILES})