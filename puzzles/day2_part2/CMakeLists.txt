add_executable(day2_part2 main.c)
target_link_libraries(day2_part2
    INTERFACE
        compile_options
    PRIVATE
        aoc23
)


add_custom_target(copy_input_d2_p2
    ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/puzzles/day2_part2/inputs
        ${PROJECT_BINARY_DIR}/puzzles/day2_part2
        COMMENT "Copying puzzle input to binary dir"
)

add_dependencies(day2_part2 copy_input_d2_p2)