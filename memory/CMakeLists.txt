cmake_minimum_required(VERSION 3.5)

project(memory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(memory
  main.cpp
  memory.h
)

install(TARGETS memory
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
