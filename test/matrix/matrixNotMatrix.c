#include "matrix.h"
#include <assert.h>

int main()
{
    matrix test0;
    matrix* mI0 = &test0;
    matrix testRes;
    matrix* mRes = &testRes;
    //give wired example to test scalability
    char mS0[100] = "[[1,0,0,0],[0,1,1,1]]";
    char mSRes[500] = "[[0,1,1,1],[1,0,0,0]]";
    assert(readMatrix(mI0, mS0) == 0);
    assert(readMatrix(mRes, mSRes) == 0);
    matrix *not = notMatrix();
    matrix *res = productMatrix(not, mI0);
    showDigitsArray(&res->m);
    assert(checkIdentityMatrix(res, mRes) == 0);
    assert(clearMatrix(mI0) == 0);
    assert(clearMatrix(mRes) == 0);
    assert(clearMatrix(res) == 0);
    free(res);
    assert(clearMatrix(not) == 0);
    free(not);
    return 0;
}