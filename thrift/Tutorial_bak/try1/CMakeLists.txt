cmake_minimum_required(VERSION 3.6)
project(try1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp tutorial_cpp_CppClient.cpp tutorial_cpp_CppServer.cpp)
add_executable(try1 ${SOURCE_FILES})