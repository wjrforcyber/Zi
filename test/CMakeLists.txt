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