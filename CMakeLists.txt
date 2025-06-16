cmake_minimum_required(VERSION 3.31.6)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Rat VERSION 1.0)

add_compile_options(-W -Wall -Wextra -fsanitize=address -g)

add_link_options(-fsanitize=address)

# array lib
add_subdirectory(array)
include_directories(array)

# util lib
add_subdirectory(util)
include_directories(util)

# matrix lib
add_subdirectory(matrix)
include_directories(matrix)

# tree lib
add_subdirectory(tree)
include_directories(tree/bst)

# set lib
add_subdirectory(set)
include_directories(set)

if(ZI_TEST)
    include(CTest)
    add_subdirectory(test)
endif()