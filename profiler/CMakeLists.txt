cmake_minimum_required(VERSION 3.13)
project(profiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(profiler main.cpp profiler.h range.h)