cmake_minimum_required(VERSION 3.6)
project(linked-List)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES linkedList.cpp node.cpp node.h)
add_executable(Linked-List ${SOURCE_FILES})