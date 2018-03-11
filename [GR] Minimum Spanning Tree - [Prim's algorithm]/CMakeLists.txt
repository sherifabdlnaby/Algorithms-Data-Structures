cmake_minimum_required(VERSION 3.6)
project(Prim)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp prim.h graph.h disjointsets.h)
add_executable(Prim ${SOURCE_FILES})