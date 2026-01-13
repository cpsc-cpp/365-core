cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(CPSC365 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(Basics)
add_subdirectory(STL)
add_subdirectory(Classes)
add_subdirectory(Templates)
add_subdirectory(Other)


