cmake_minimum_required(VERSION 3.27)
project(S3)

set(CMAKE_CXX_STANDARD 17)

add_executable(S3 main.cpp
        sounds_vector.h
        sounds_vector.cpp
        Wave.h
        Wave.cpp)
