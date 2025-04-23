cmake_minimum_required(VERSION 3.27)
project(IndexedList_SLLA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(IndexedList_SLLA
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IndexedList.cpp
        IndexedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
