cmake_minimum_required(VERSION 3.20)

add_executable(test
  main.cpp
  )

# target_link_directories("${CMAKE_CURRENT_SOURCE_DIR}\\lib")
# then
# target_link_libraries(test PUBLIC ${EXTRA_LIBS})
# or
# add_library(someLib SHARED IMPORTED) # or STATIC instead of SHARED

target_include_directories(test PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}\\include"
  )
