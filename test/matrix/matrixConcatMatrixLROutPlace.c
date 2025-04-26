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
    char mS0[100] = "[[ 1     ,2, 3 ],[ 2, 4,6   ]]";
    char mS1[100] = "[[12, 32,    4], [  9,  2, 11  ]]";
    char mSRes[100] = "[[ 1,2,3, 12, 32,    4], [  2,4, 6,9,  2, 11  ]]";
    assert(readMatrix(mI0, mS0) == 0);
    assert(readMatrix(mI1, mS1) == 0);
    assert(readMatrix(mRes, mSRes) == 0);
    matrix* res = concatMatrixLROutPlace(mI0, mI1);
    assert(checkIdentityMatrix(res, mRes) == 0);
    assert(clearMatrix(res) == 0);
}