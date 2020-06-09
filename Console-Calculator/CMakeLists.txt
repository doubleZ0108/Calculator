cmake_minimum_required(VERSION 3.15)
project(Console_Calculator)

set(CMAKE_CXX_STANDARD 11)

add_executable(Console_Calculator src/main.c src/header/interface.h src/header/calculator.h src/header/util.h src/header/calculator_stack.h)