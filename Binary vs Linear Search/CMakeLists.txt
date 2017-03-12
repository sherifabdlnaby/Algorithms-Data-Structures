cmake_minimum_required(VERSION 3.6)
project(Binary_vs_Linear_Search)

set(CMAKE_CXX_STANDARD 11)

add_executable(Linear-Single Linear.cpp BinaryLinearSearchLibrary.h)
add_executable(Binary-Vs-Linear Binary-Vs-Linear.cpp BinaryLinearSearchLibrary.h)
add_executable(Binary-single Binary.cpp BinaryLinearSearchLibrary.h)