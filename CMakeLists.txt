cmake_minimum_required(VERSION 3.6)
project(majasdarbs3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MenuItem.cpp MenuItem.h MenuController.cpp MenuController.h)
add_executable(majasdarbs3 ${SOURCE_FILES})