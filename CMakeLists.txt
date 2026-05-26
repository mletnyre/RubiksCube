cmake_minimum_required(VERSION 3.10)
project(Cube C)

add_executable(cube
    src/main.c
    src/Cubie.c
    src/RubiksCube.c
)

target_include_directories(cube PRIVATE include)

# Link raylib everywhere
target_link_libraries(cube PRIVATE raylib)

# Platform-specific libraries
if(WIN32)

    target_link_libraries(cube PRIVATE
        winmm
        gdi32
    )

elseif(UNIX AND NOT APPLE)

    target_link_libraries(cube PRIVATE
        m
        pthread
        dl
        rt
        X11
    )

endif()