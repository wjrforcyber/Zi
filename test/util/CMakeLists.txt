add_executable(utilMatrix utilMatrix.c)
target_link_libraries(utilMatrix ziUtil)
add_test(NAME UtilTestsUtilMatrix COMMAND utilMatrix)