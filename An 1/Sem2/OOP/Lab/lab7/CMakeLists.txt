cmake_minimum_required(VERSION 3.27)
project(lab7)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab7 main.cpp
        Vehicle.h
        Vehicle.cpp
        Car.h
        Car.cpp
        Truck.h
        Truck.cpp
        Garage.h
        Garage.cpp)
