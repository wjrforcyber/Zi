#include "matrix.h"
#include <assert.h>
#include <stdio.h>

int main()
{
    matrix test0;
    matrix* mI0 = &test0;
    matrix test1;
    matrix* mI1 = &test1;
    matrix testRes;
    matrix* mRes = &testRes;
    //f_tt0 = [[1],[0]] True
    char tt0[100] = "[[1],[0]]";
    //f_tt1 = [[0],[1]] False
    char tt1[100] = "[[0],[1]]";
    // True & False
    char andRes[100] = "[[0],[1]]";
    assert(readMatrix(mI0, tt0) == 0);
    assert(readMatrix(mI1, tt1) == 0);
    assert(readMatrix(mRes, andRes) == 0);
    matrix *and = andMatrix();
    matrix *kPro_and_a = stpMatrix(and, mI0);
    matrix *res_and_a_b = stpMatrix(kPro_and_a, mI1);
    matrix *kPro_and_b = stpMatrix(and, mI1);
    matrix *res_and_b_a = stpMatrix(kPro_and_b, mI0);

    showDigitsMatrix(res_and_a_b);
    assert(checkIdentityMatrix(res_and_a_b, res_and_b_a) == 0);
    assert(checkIdentityMatrix(mRes, res_and_b_a) == 0);
    assert(clearMatrix(mI0) == 0);
    assert(clearMatrix(mI1) == 0);
    assert(clearMatrix(mRes) == 0);
    assert(clearMatrix(and) == 0);
    free(and);
    assert(clearMatrix(kPro_and_a) == 0);
    free(kPro_and_a);
    assert(clearMatrix(res_and_a_b) == 0);
    free(res_and_a_b);
    assert(clearMatrix(kPro_and_b) == 0);
    free(kPro_and_b);
    assert(clearMatrix(res_and_b_a) == 0);
    free(res_and_b_a);
    return 0;
}