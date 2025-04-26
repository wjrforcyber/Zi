#include "matrix.h"
#include <assert.h>

int main()
{
    matrix test0;
    matrix* mI0 = &test0;
    
    matrix test1;
    matrix* mI1 = &test1;
    
    matrix testRes;
    matrix* mRes = &testRes;
    //give wired example to test scalability
    char mS0[100] = "[[1,2],[3,4]]";
    char mS1[100] = "[[12, 32,    4], [  9,  2, 11  ], [3,7,4]]";
    char mSRes[500] = "[[12,32,4,24,64,8],[9,2,11,18,4,22],[3,7,4,6,14,8],[36,96,12,48,128,16],[27,6,33,36,8,44],[9,21,12,12,28,16]]";
    assert(readMatrix(mI0, mS0) == 0);
    assert(readMatrix(mI1, mS1) == 0);
    assert(readMatrix(mRes, mSRes) == 0);
    matrix* res = kProductMatrix(mI0, mI1);
    assert(checkIdentityMatrix(res, mRes) == 0);
    assert(clearMatrix(res) == 0);
}