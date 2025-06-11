cmake_minimum_required(VERSION 3.31.6)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Rat VERSION 1.0)

add_compile_options(-W -Wall -Wextra -fsanitize=address -g)

add_link_options(-fsanitize=address)

# array lib
ADD_LIBRARY( ziArray STATIC array/array.c )
include_directories(array)

# util lib
ADD_LIBRARY( ziUtil STATIC util/utilMatrix.c)
include_directories(util)

# matrix lib
ADD_LIBRARY( ziMatrix STATIC matrix/matrix.c matrix/matrixCal.c array/array.c util/utilMatrix.c)
include_directories(matrix)

# tree lib
ADD_LIBRARY( ziTree STATIC tree/bst/bst.c array/array.c)
include_directories(tree/bst)

# set lib
ADD_LIBRARY( ziSet STATIC set/set.c array/array.c)
include_directories(set)

include(CTest)
add_subdirectory(test)