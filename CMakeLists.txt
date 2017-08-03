cmake_minimum_required(VERSION 3.8)
project(car)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Screen.cpp Screen.h Car.cpp Car.h Movable_object.h test.h Movable_object_container.cpp Movable_object_container.h Movable_object.cpp)
add_executable(car ${SOURCE_FILES})