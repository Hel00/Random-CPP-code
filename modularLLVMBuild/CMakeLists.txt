cmake_minimum_required(VERSION 3.15)
project(TinyAsmParser LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

set(LLVM_DIR "/home/hel/Documents/Dev/llvm-project/build/lib/cmake/llvm")
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

add_executable(main main.cpp)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

target_link_libraries(main
  PRIVATE
    LLVMAsmParser
    LLVMSupport
)
