project(puzzle_solver)

add_library(puzzle_lib io.c
                       state.c
                       node.c
                       list.c)

target_include_directories(puzzle_lib PUBLIC "${8-Puzzle_SOURCE_DIR}/include")

add_executable(puzzle_solver main.c)  

target_link_libraries(puzzle_solver puzzle_lib)
