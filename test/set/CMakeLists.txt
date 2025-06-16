set(SLIBS ziSet ziArray)

add_executable(setInit setInit.c)
target_link_libraries(setInit ${SLIBS})
add_test(NAME SetTestsSetInit COMMAND setInit)