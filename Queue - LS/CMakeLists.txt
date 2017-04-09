cmake_minimum_required(VERSION 3.6)
project(Queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp node.h queue.h)
add_executable(Queue ${SOURCE_FILES})