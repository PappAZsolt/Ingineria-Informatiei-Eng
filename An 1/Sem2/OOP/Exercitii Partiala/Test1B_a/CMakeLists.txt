cmake_minimum_required(VERSION 3.27)
project(Test1B_a)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test1B_a main.cpp
        volume.h
        volume.cpp
        BottleRepository.h
        BottleRepository.cpp)
