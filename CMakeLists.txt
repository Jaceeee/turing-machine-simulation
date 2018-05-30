cmake_minimum_required(VERSION 3.8)
project(turing_machine_simulation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cell.h
        main.cpp
        renderer.h
        turing_machine.h)

add_executable(turing_machine_simulation ${SOURCE_FILES})