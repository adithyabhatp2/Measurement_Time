cmake_minimum_required(VERSION 3.6)
project(time_measurement)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES gettime_overhead.c)
add_executable(time_measurement ${SOURCE_FILES})