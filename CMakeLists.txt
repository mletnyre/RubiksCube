cmake_minimum_required(VERSION 3.10)
project(Cube)

add_executable(cube src/main.c src/Cubie.c src/TwoByTwo.c)

target_include_directories(cube PRIVATE include)

target_link_libraries(cube raylib m pthread dl rt X11)