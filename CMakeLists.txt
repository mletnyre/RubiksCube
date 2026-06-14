cmake_minimum_required(VERSION 3.10)

project(Cube C)

set(CMAKE_C_STANDARD 99)

add_executable(cube
    src/main.c
    src/Cubie.c
    src/RubiksCube.c
    src/solver.c
)

target_include_directories(cube PRIVATE include)

find_package(raylib REQUIRED)

target_link_libraries(cube PRIVATE raylib)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(cube PRIVATE
        -fsanitize=address
        -fno-omit-frame-pointer
        -g
    )

    target_link_options(cube PRIVATE
        -fsanitize=address
    )
endif()