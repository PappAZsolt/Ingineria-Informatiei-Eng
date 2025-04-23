cmake_minimum_required(VERSION 3.27)
project(lab8)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab8 main.cpp
        Garage.h
        Garage.cpp
        Truck.cpp
        Car.cpp)
