cmake_minimum_required(VERSION 3.8)
project(car)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Screen.cpp Screen.h Car.cpp Car.h Object_movable.h test.h)
add_executable(car ${SOURCE_FILES})