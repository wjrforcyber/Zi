#include "matrix.h"
#include <assert.h>
#include <stdio.h>

int main()
{
    matrix test0;
    matrix* mI0 = &test0;
    matrix test1;
    matrix* mI1 = &test1;
    matrix test2;
    matrix* mI2 = &test2;
    matrix test3;
    matrix* mI3 = &test3;
    matrix testRes0;
    matrix* mRes0 = &testRes0;
    matrix testRes1;
    matrix* mRes1 = &testRes1;

    char tt0[100] = "[[0],[1]]";
    char tt1[100] = "[[0],[1]]";
    char tt2[100] = "[[1],[0]]";
    char tt3[100] = "[[0],[1]]";
    // True & True & False
    char orRes0[100] = "[[1],[0]]";
    char orRes1[100] = "[[0],[1]]";
    assert(readMatrix(mI0, tt0) == 0);
    assert(readMatrix(mI1, tt1) == 0);
    assert(readMatrix(mI2, tt2) == 0);
    assert(readMatrix(mI3, tt3) == 0);

    assert(readMatrix(mRes0, orRes0) == 0);
    assert(readMatrix(mRes1, orRes1) == 0);
    
    matrix *or = orNMatrix(3);
    matrix *kPro_or_a = stpMatrix(or, mI0);
    matrix *kPro_or_a_b = stpMatrix(kPro_or_a, mI1);
    //1
    matrix *res0_or_a_b_c = stpMatrix(kPro_or_a_b, mI2);
    //0
    matrix *res1_or_a_b_c = stpMatrix(kPro_or_a_b, mI3);

    showDigitsMatrix(res0_or_a_b_c);
    showDigitsMatrix(res1_or_a_b_c);

    assert(checkIdentityMatrix(mRes0, res0_or_a_b_c) == 0);
    assert(checkIdentityMatrix(mRes1, res1_or_a_b_c) == 0);

    assert(clearMatrix(mI0) == 0);
    assert(clearMatrix(mI1) == 0);
    assert(clearMatrix(mI2) == 0);
    assert(clearMatrix(mI3) == 0);
    assert(clearMatrix(mRes0) == 0);
    assert(clearMatrix(mRes1) == 0);
    assert(clearMatrix(or) == 0);
    free(or);
    assert(clearMatrix(kPro_or_a) == 0);
    free(kPro_or_a);
    assert(clearMatrix(kPro_or_a_b) == 0);
    free(kPro_or_a_b);
    assert(clearMatrix(res0_or_a_b_c) == 0);
    free(res0_or_a_b_c);
    assert(clearMatrix(res1_or_a_b_c) == 0);
    free(res1_or_a_b_c);
    return 0;
}