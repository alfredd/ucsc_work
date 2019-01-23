cmake_minimum_required(VERSION 2.8)
project(cmps101)

set(CMAKE_CXX_STANDARD 17)
include(ExternalProject)
enable_testing()


add_executable(sorttester SortTester.cpp)
