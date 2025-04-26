#include "matrix.h"
#include <assert.h>
#include <stdio.h>

int main()
{
    matrix test0;
    matrix* mI0 = &test0;
    
    matrix testRes;
    matrix* mRes = &testRes;
    //give wired example to test scalability
    char mS0[100] = "[[ 1     ,2, 3 ],[ 2, 4,6   ]]";
    char mSRes[100] = "[[3,6,9],[6,12,18]]";
    assert(readMatrix(mI0, mS0) == 0);
    assert(readMatrix(mRes, mSRes) == 0);
    matrix* res = nTimesMatrixOutplace(mI0, 3);
    assert(checkIdentityMatrix(res, mRes) == 0);
    assert(clearMatrix(res) == 0);
}