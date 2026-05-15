cmake_minimum_required(VERSION 3.10)
project(Cube)

add_executable(cube main.c Cubie.c TwoByTwo.c)

target_include_directories(cube PRIVATE include)

target_link_libraries(cube raylib opengl32 gdi32 winmm)