cmake_minimum_required(VERSION 3.27)
project(lab9)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab9 main.cpp
        song.h
        song.cpp
        SongContainer.h
        SongContainer.cpp
)
