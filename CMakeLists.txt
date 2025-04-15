cmake_minimum_required(VERSION 3.31.6)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Rat VERSION 1.0)

add_compile_options(-W -Wall -Wextra)

# array lib
ADD_LIBRARY( ziArray STATIC array/array.c )
include_directories(array)

# array lib
ADD_LIBRARY( ziMatrix STATIC matrix/matrix.c matrix/matrixCal.c array/array.c)
include_directories(matrix)

include(CTest)
add_subdirectory(test)