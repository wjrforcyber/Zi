cmake_minimum_required(VERSION 3.31.6)
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()
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


#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  URL "/Users/jingrenwang/Downloads/Github/googletest-1.16.0.zip"
#)
#FetchContent_MakeAvailable(googletest)

#enable_testing()
#add_executable(
#  rat_array_test
#  test/arrayTest.c
#)
#target_link_libraries(
#  rat_array_test
#  ziArray
#  gtest_main
#)

#include(GoogleTest)
#gtest_discover_tests(rat_array_test)

# hash map lib

# utils algorithm lib

#target_include_directories(Rat PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/array")
#add_subdirectory(lib)
#target_link_libraries(EasySyn PRIVATE json)
#target_include_directories(EasySyn PRIVATE "${PROJECT_BINARY_DIR}")