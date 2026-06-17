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
find_library(CUNIT_LIB cunit REQUIRED)

target_link_libraries(cube PRIVATE 
    raylib
)

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

add_executable(cube_tests
    test/test.c        
    src/Cubie.c
    src/RubiksCube.c
    src/solver.c
)

target_include_directories(cube_tests PRIVATE include)
target_link_libraries(cube_tests PRIVATE raylib ${CUNIT_LIB})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(cube_tests PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
    target_link_options(cube_tests PRIVATE -fsanitize=address)
endif()

add_custom_command(TARGET cube_tests POST_BUILD
    COMMAND $<TARGET_FILE:cube_tests>
    COMMENT "Running CUnit test suite..."
)
add_dependencies(cube cube_tests)