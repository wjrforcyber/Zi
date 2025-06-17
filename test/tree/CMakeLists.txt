set(TLIBS ziTree ziArray)

add_executable(bstInitBstTree bstInitBstTree.c)
target_link_libraries(bstInitBstTree ${TLIBS})
add_test(NAME BstTestsInitBstTree COMMAND bstInitBstTree)

add_executable(bstSearchBstTree bstSearchBstTree.c)
target_link_libraries(bstSearchBstTree ${TLIBS})
add_test(NAME BstTestsSearchBstTree COMMAND bstSearchBstTree)

add_executable(bstGetMinMaxNodeBstTree bstGetMinMaxNodeBstTree.c)
target_link_libraries(bstGetMinMaxNodeBstTree ${TLIBS})
add_test(NAME BstGetMinMaxNodeBstTree COMMAND bstGetMinMaxNodeBstTree)

add_executable(bstGetSucPreNodeBstTree bstGetSucPreNodeBstTree.c)
target_link_libraries(bstGetSucPreNodeBstTree ${TLIBS})
add_test(NAME BstGetSucPreNodeBstTree COMMAND bstGetSucPreNodeBstTree)

add_executable(rbtMap rbtMap.c)
target_link_libraries(rbtMap ${TLIBS})
add_test(NAME rbtMap COMMAND rbtMap)