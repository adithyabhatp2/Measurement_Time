cmake_minimum_required(VERSION 3.6)
project(time_measurement)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES gettime_overhead.c gettime_overhead_raw.c)
add_executable(gettime_overhead gettime_overhead.c)
add_executable(gettime_overhead_raw gettime_overhead_raw.c)