cmake_minimum_required(VERSION 3.27)
project(ADT_Set_with_DLL)

set(CMAKE_CXX_STANDARD 17)

add_executable(ADT_Set_with_DLL main.cpp
        ExtendedTest.cpp
        Set.cpp
        SetIterator.cpp
        ShortTest.cpp)
