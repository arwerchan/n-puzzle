project(puzzle_tests)

include_directories(${TEST_SOURCE_DIR}/src)

add_executable(test1 test_state.c)
target_link_libraries(test1 puzzle_lib)
add_test("${PROJECT_NAME}" test1)
