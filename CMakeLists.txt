cmake_minimum_required(VERSION 3.13)

project(puzzle)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  set (warnings "-Wall -g")
endif()

add_subdirectory(src)
add_subdirectory(test)
