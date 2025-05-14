cmake_minimum_required(VERSION 3.27)
project(Test_1B_b)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test_1B_b main.cpp
        MonetaryUnit.h
        MonetaryUnit.cpp
        BillRepository.h
        BillRepository.cpp)
