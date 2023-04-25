cmake_minimum_required(VERSION 3.5)

project(Bf4_syscalls LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bf4_syscalls
  main.cpp
  types.hpp
  win32Utils.hpp
  memory.hpp
)

install(TARGETS Bf4_syscalls
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
