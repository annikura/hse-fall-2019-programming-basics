cmake_minimum_required(VERSION 3.9)
project(c_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -g -fsanitize=thread")

add_executable(c_example main.cpp)