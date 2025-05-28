include_directories(${CMAKE_SOURCE_DIR}/tree/bst)

add_executable(bstInitBstTree bstInitBstTree.c)
target_link_libraries(bstInitBstTree ziTree)
add_test(NAME BstTestsInitBstTree COMMAND bstInitBstTree)