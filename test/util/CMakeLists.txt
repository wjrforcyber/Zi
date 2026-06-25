add_executable(utilMatrix utilMatrix.c)
target_link_libraries(utilMatrix ziUtil)
add_test(NAME UtilTestsUtilMatrix COMMAND utilMatrix)

add_executable(utilFile utilFile.c)
target_link_libraries(utilFile ziUtil ziArray)
add_test(NAME UtilTestsUtilFile COMMAND utilFile)