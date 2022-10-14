cmake_minimum_required(VERSION 3.5)

project(Bf4_lessenedRecoil LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bf4_lessenedRecoil main.cpp)

install(TARGETS Bf4_lessenedRecoil
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
