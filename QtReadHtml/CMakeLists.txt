cmake_minimum_required(VERSION 3.14)

project(webReadTest LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(webReadTest
  main.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Network)
target_link_libraries(webReadTest Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)

install(TARGETS webReadTest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
