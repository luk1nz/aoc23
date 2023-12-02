cmake_minimum_required(VERSION 3.26)
project(aoc23 C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)

add_library(compile_options INTERFACE)
target_compile_options(compile_options
    INTERFACE
        # CLANG
        $<$<C_COMPILER_ID:Clang,AppleClang>:
            -Werror
            -Wall
            -Wextra
            -Wshadow
            -Wformat=2
            -Wunused
            -pedantic
            -Wno-c11-extensions
        >
)

add_library(aoc23
    STATIC
        src/io.c
)
target_include_directories(aoc23
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(aoc23
    INTERFACE
        compile_options
)

add_subdirectory(puzzles/day1_part1)
add_subdirectory(puzzles/day1_part2)

