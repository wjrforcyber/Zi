include_directories(${CMAKE_SOURCE_DIR}/set)

add_executable(setInit setInit.c)
target_link_libraries(setInit ziSet)
add_test(NAME SetTestsSetInit COMMAND setInit)