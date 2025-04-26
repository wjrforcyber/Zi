include_directories(${CMAKE_SOURCE_DIR}/array)

add_executable(arrayInitAndClear arrayInitAndClear.c)
target_link_libraries(arrayInitAndClear ziArray)
add_test(NAME ArrayTestsInitAndClear COMMAND arrayInitAndClear)

add_executable(arrayGrow arrayGrow.c)
target_link_libraries(arrayGrow ziArray)
add_test(NAME ArrayTestsGrow COMMAND arrayGrow)

add_executable(arrayPush arrayPush.c)
target_link_libraries(arrayPush ziArray)
add_test(NAME ArrayTestsPush COMMAND arrayPush)

add_executable(arrayDeleteIndex arrayDeleteIndex.c)
target_link_libraries(arrayDeleteIndex ziArray)
add_test(NAME ArrayTestsDeleteIndex COMMAND arrayDeleteIndex)

add_executable(arraySetIndex arraySetIndex.c)
target_link_libraries(arraySetIndex ziArray)
add_test(NAME ArrayTestsSetIndex COMMAND arraySetIndex)

add_executable(arrayInsertIndex arrayInsertIndex.c)
target_link_libraries(arrayInsertIndex ziArray)
add_test(NAME ArrayTestsInsertIndex COMMAND arrayInsertIndex)

add_executable(arrayChangeIndex arrayChangeIndex.c)
target_link_libraries(arrayChangeIndex ziArray)
add_test(NAME ArrayTestsChangeIndex COMMAND arrayChangeIndex)

add_executable(arrayCheckIdentity arrayCheckIdentity.c)
target_link_libraries(arrayCheckIdentity ziArray)
add_test(NAME ArrayTestsCheckIdentity COMMAND arrayCheckIdentity)

add_executable(arrayShowDigits arrayShowDigits.c)
target_link_libraries(arrayShowDigits ziArray)
add_test(NAME ArrayTestsShowDigits COMMAND arrayShowDigits)

add_executable(arrayProductIntArray arrayProductIntArray.c)
target_link_libraries(arrayProductIntArray ziArray)
add_test(NAME ArrayTestsProductIntArray COMMAND arrayProductIntArray)