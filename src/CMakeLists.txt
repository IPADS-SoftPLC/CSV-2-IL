cmake_minimum_required(VERSION 3.10)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src main.cpp Component.cpp Component.h Instruction.cpp Instruction.h )