cmake_minimum_required(VERSION 3.6)
project(Kruskal)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp kruskal.h graph.h disjointsets.h)
add_executable(Kruskal ${SOURCE_FILES})