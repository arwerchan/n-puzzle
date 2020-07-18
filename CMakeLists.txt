cmake_minimum_required(VERSION 3.13)

project(8-Puzzle)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/test)

add_compile_options(-Wall -g)

add_executable(${PROJECT_NAME} src/main.c
                               src/io.c
                               include/io.h
                               include/state.h)

# enable testing and create test cases
enable_testing()
# test functions related to State
add_executable(${PROJECT_NAME}_Test_State test/test1.c
                                          src/state.c
                                          include/state.h)                             
add_test("State_Compare_fn" ${PROJECT_NAME}_Test_State)
