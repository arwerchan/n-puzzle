cmake_minimum_required(VERSION 3.13)

project(8-puzzle)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} src/main.c)
