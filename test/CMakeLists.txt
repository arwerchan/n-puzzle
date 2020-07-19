project(puzzle_tests)

include_directories(${TEST_SOURCE_DIR}/src)

add_executable(test1 test_state_1.c)
add_executable(test2 test_state_2.c)
add_executable(test3 test_state_3.c)
target_link_libraries(test1 puzzle_lib)
target_link_libraries(test2 puzzle_lib)
target_link_libraries(test3 puzzle_lib)

add_test(NAME "State_compare" COMMAND test1)
add_test(NAME "State_move" COMMAND test2)
add_test(NAME "State_cost" COMMAND test3)
