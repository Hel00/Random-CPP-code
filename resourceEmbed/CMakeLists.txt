cmake_minimum_required(VERSION 3.5)

project(resourceEmbed LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(resourceEmbed main.cpp)

include(GNUInstallDirs)
install(TARGETS resourceEmbed
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
