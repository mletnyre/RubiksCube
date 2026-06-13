cmake_minimum_required(VERSION 3.10)

project(Cube C)

set(CMAKE_C_STANDARD 99)

add_executable(cube
    src/main.c
    src/Cubie.c
    src/RubiksCube.c
)

target_include_directories(cube PRIVATE include)

find_package(raylib REQUIRED)

target_link_libraries(cube PRIVATE raylib)