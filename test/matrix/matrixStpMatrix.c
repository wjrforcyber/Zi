#include "matrix.h"

#include <assert.h>

int main() {
    matrix test0;
    matrix* mI0 = &test0;

    matrix test1;
    matrix* mI1 = &test1;

    matrix testRes;
    matrix* mRes = &testRes;
    // give wired example to test scalability
    char mS0[100] = "[[1,0,0,0],[0,1,1,1]]";
    char mS1[100] = "[[1,1,0,1],[0,0,1,0]]";
    char mSRes[500] = "[[1,0,1,0,0,0,1,0],[0,1,0,1,1,1,0,1]]";
    assert(readMatrix(mI0, mS0) == 0);
    assert(readMatrix(mI1, mS1) == 0);
    assert(readMatrix(mRes, mSRes) == 0);
    matrix* res = stpMatrix(mI0, mI1);
    assert(checkIdentityMatrix(res, mRes) == 0);
    assert(clearMatrix(mI0) == 0);
    assert(clearMatrix(mI1) == 0);
    assert(clearMatrix(mRes) == 0);
    assert(clearMatrix(res) == 0);
    free(res);
}