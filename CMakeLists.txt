cmake_minimum_required(VERSION 3.31.6)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Rat VERSION 1.0)
#configure_file(RatConfig.h.in Rat.h)
#project(Rat LANGUAGES C)

add_compile_options(-W -Wall -Wextra)
#add_executable(Rat array/array.c)

# array lib
ADD_LIBRARY( ziArray STATIC array/array.c )
include_directories(array)

include(CTest)
add_subdirectory(test)