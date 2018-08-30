# cmake_minimum_required(VERSION <specify CMake version here>)
project(Circular_Buffer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Circular_Buffer
        .gitignore
        circularbuffer.c
        circularbuffer.h
        LICENSE.md
        main.c
        makefile
        README.md)
