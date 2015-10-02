cmake_minimum_required(VERSION 3.3)
project(Soj)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 1007.cpp)
add_executable(Soj ${SOURCE_FILES})