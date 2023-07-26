cmake_minimum_required(VERSION 3.5)

project(bootloaderTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bootloaderTest
  main.cpp
  start.s
  link.ld

  include/screen.h
  include/string.h
  include/system.h
  include/types.h
)



install(TARGETS bootloaderTest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
