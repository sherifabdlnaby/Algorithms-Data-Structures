cmake_minimum_required(VERSION 3.6)
project(asfsd)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp node.cpp node.h node.cpp node.h)
add_executable(asfsd ${SOURCE_FILES})
add_executable(fip fip.cpp)