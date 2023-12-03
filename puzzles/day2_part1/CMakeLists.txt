add_executable(day2_part1 main.c)
target_link_libraries(day2_part1
    INTERFACE
        compile_options
    PRIVATE
        aoc23
)


add_custom_target(copy_input_d2_p1
    ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/puzzles/day2_part1/inputs
        ${PROJECT_BINARY_DIR}/puzzles/day2_part1
        COMMENT "Copying puzzle input to binary dir"
)

add_dependencies(day2_part1 copy_input_d2_p1)