cmake_minimum_required(VERSION 3.29)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(algorithm
    test/sol.cc
    head.h)
