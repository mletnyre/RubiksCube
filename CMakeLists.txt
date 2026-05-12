# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Cube)

# Add an executable target
add_executable(cube main.c Cubie.c TwoByTwo.c)

# If you have header files in an 'include/' directory, specify the include path
target_include_directories(cube PRIVATE include)

# To link a library (e.g., pthread), use:
# target_link_libraries(myapp pthread)   