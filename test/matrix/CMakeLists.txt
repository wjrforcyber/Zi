set(MLIBS ziMatrix ziArray ziUtil)

add_executable(matrixRead matrixRead.c)
target_link_libraries(matrixRead ${MLIBS})
add_test(NAME MatrixTestsMatrixRead COMMAND matrixRead)

add_executable(matrixFetchMatrixRowCol matrixFetchMatrixRowCol.c)
target_link_libraries(matrixFetchMatrixRowCol ${MLIBS})
add_test(NAME MatrixTestsMatrixFetchMatrixRowCol COMMAND matrixFetchMatrixRowCol)

add_executable(matrixAddMatrix matrixAddMatrix.c)
target_link_libraries(matrixAddMatrix ${MLIBS})
add_test(NAME MatrixTestsMatrixAddMatrix COMMAND matrixAddMatrix)

add_executable(matrixProductMatrix matrixProductMatrix.c)
target_link_libraries(matrixProductMatrix ${MLIBS})
add_test(NAME MatrixTestsMatrixProductMatrix COMMAND matrixProductMatrix)

add_executable(matrixConcatMatrixLROutPlace matrixConcatMatrixLROutPlace.c)
target_link_libraries(matrixConcatMatrixLROutPlace ${MLIBS})
add_test(NAME MatrixTestsMatrixConcatMatrixLROutPlace COMMAND matrixConcatMatrixLROutPlace)

add_executable(matrixConcatMatrixUDOutPlace matrixConcatMatrixUDOutPlace.c)
target_link_libraries(matrixConcatMatrixUDOutPlace ${MLIBS})
add_test(NAME MatrixTestsMatrixConcatMatrixUDOutPlace COMMAND matrixConcatMatrixUDOutPlace)

add_executable(matrixNtimesMatrixOutplace matrixNtimesMatrixOutplace.c)
target_link_libraries(matrixNtimesMatrixOutplace ${MLIBS})
add_test(NAME MatrixTestsMatrixNtimesMatrixOutplace COMMAND matrixNtimesMatrixOutplace)

add_executable(matrixKProductMatrix matrixKProductMatrix.c)
target_link_libraries(matrixKProductMatrix ${MLIBS})
add_test(NAME MatrixTestsMatrixKProductMatrix COMMAND matrixKProductMatrix)

add_executable(matrixCreateIdentityMatrix matrixCreateIdentityMatrix.c)
target_link_libraries(matrixCreateIdentityMatrix ${MLIBS})
add_test(NAME MatrixTestsMatrixCreateIdentityMatrix COMMAND matrixCreateIdentityMatrix)

add_executable(matrixStpMatrix matrixStpMatrix.c)
target_link_libraries(matrixStpMatrix ${MLIBS})
add_test(NAME MatrixTestsStpMatrix COMMAND matrixStpMatrix)

add_executable(matrixNotMatrix matrixNotMatrix.c)
target_link_libraries(matrixNotMatrix ${MLIBS})
add_test(NAME MatrixTestsNotMatrix COMMAND matrixNotMatrix)

add_executable(matrixEqMatrix matrixEqMatrix.c)
target_link_libraries(matrixEqMatrix ${MLIBS})
add_test(NAME MatrixTestsEqMatrix COMMAND matrixEqMatrix)

add_executable(matrixAndMatrix matrixAndMatrix.c)
target_link_libraries(matrixAndMatrix ${MLIBS})
add_test(NAME MatrixTestsAndMatrix COMMAND matrixAndMatrix)

add_executable(matrixAndNMatrix matrixAndNMatrix.c)
target_link_libraries(matrixAndNMatrix ${MLIBS})
add_test(NAME MatrixTestsAndNMatrix COMMAND matrixAndNMatrix)

add_executable(matrixOrNMatrix matrixOrNMatrix.c)
target_link_libraries(matrixOrNMatrix ${MLIBS})
add_test(NAME MatrixTestsOrNMatrix COMMAND matrixOrNMatrix)

add_executable(matrixTMatrix matrixTMatrix.c)
target_link_libraries(matrixTMatrix ${MLIBS})
add_test(NAME MatrixTestsTMatrix COMMAND matrixTMatrix)

add_executable(matrixStpTwoTMatrix matrixStpTwoTMatrix.c)
target_link_libraries(matrixStpTwoTMatrix ${MLIBS})
add_test(NAME MatrixTestsStpTwoTMatrix COMMAND matrixStpTwoTMatrix)

add_executable(matrixSwapMatrix matrixSwapMatrix.c)
target_link_libraries(matrixSwapMatrix ${MLIBS})
add_test(NAME MatrixSwapMatrix COMMAND matrixSwapMatrix)

add_executable(matrixGetConstMatrix matrixGetConstMatrix.c)
target_link_libraries(matrixGetConstMatrix ${MLIBS})
add_test(NAME MatrixGetConstMatrix COMMAND matrixGetConstMatrix)

add_executable(matrixShowDigitsMatrix matrixShowDigitsMatrix.c)
target_link_libraries(matrixShowDigitsMatrix ${MLIBS})
add_test(NAME MatrixTestsShowDigitsMatrix COMMAND matrixShowDigitsMatrix)
