cmake_minimum_required(VERSION 3.5)

project(LogTable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LogTable main.cpp)

install(TARGETS LogTable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
