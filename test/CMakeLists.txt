project(puzzle_tests)

include_directories(${TEST_SOURCE_DIR}/src)

add_executable(state_test1 test_state_1.c)
add_executable(state_test2 test_state_2.c)
add_executable(state_test3 test_state_3.c)
target_link_libraries(state_test1 puzzle_lib)
target_link_libraries(state_test2 puzzle_lib)
target_link_libraries(state_test3 puzzle_lib)

add_test(NAME "State_compare" COMMAND state_test1)
add_test(NAME "State_move" COMMAND state_test2)
add_test(NAME "State_cost" COMMAND state_test3)

add_executable(node_test1 test_node_1.c)
target_link_libraries(node_test1 puzzle_lib)

add_test(NAME "Node_cost" COMMAND node_test1)
