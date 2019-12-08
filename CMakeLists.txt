cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c print.c print.h input.h input.c data.c data.h signIn.c signIn.h)