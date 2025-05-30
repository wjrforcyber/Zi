#include "matrix.h"

#include <assert.h>
#include <stdio.h>

int main() {
    matrix test0;
    matrix* mI0 = &test0;
    matrix test1;
    matrix* mI1 = &test1;
    matrix test2;
    matrix* mI2 = &test2;
    matrix testRes;
    matrix* mRes = &testRes;

    char tt0[100] = "[[1],[0]]";
    char tt1[100] = "[[1],[0]]";
    char tt2[100] = "[[0],[1]]";
    // True & True & False
    char andRes[100] = "[[0],[1]]";
    assert(readMatrix(mI0, tt0) == 0);
    assert(readMatrix(mI1, tt1) == 0);
    assert(readMatrix(mI2, tt2) == 0);
    assert(readMatrix(mRes, andRes) == 0);
    matrix*and = andNMatrix(3);
    matrix* kPro_and_a = stpMatrix(and, mI0);
    matrix* kPro_and_a_b = stpMatrix(kPro_and_a, mI1);
    matrix* res_and_a_b_c = stpMatrix(kPro_and_a_b, mI2);

    showDigitsMatrix(res_and_a_b_c);
    assert(checkIdentityMatrix(mRes, res_and_a_b_c) == 0);
    assert(clearMatrix(mI0) == 0);
    assert(clearMatrix(mI1) == 0);
    assert(clearMatrix(mI2) == 0);
    assert(clearMatrix(mRes) == 0);
    assert(clearMatrix(and) == 0);
    free(and);
    assert(clearMatrix(kPro_and_a) == 0);
    free(kPro_and_a);
    assert(clearMatrix(kPro_and_a_b) == 0);
    free(kPro_and_a_b);
    assert(clearMatrix(res_and_a_b_c) == 0);
    free(res_and_a_b_c);
    return 0;
}