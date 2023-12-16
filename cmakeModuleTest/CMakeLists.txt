cmake_minimum_required(VERSION 3.28)

project(moduleTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(foo)

target_sources(foo
  PUBLIC
    FILE_SET CXX_MODULES FILES
      foo.cxx
)

add_library(bar)

target_sources(bar
  PUBLIC
    FILE_SET CXX_MODULES FILES
      bar.cxx
)

add_executable(moduleTest main.cpp)

target_link_libraries(moduleTest foo bar)

include(GNUInstallDirs)
install(TARGETS moduleTest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
