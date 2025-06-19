set(MLIBS ziMap)

add_executable(mapOp mapOp.c)
target_link_libraries(mapOp ${MLIBS})
add_test(NAME mapOp COMMAND mapOp)