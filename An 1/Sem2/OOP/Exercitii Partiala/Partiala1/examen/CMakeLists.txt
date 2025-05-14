cmake_minimum_required(VERSION 3.27)
project(examen)

set(CMAKE_CXX_STANDARD 17)

add_executable(examen main.cpp
        Power.h
        Power.cpp
        InvoiceRepository.h
        InvoiceRepository.cpp)
