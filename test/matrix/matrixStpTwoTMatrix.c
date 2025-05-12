#include "matrix.h"
#include <assert.h>
#include <stdlib.h>

int main()
{
    matrix m0;
    matrix* mL = &m0;
    matrix m1;
    matrix* mR = &m1;
    //give wired example to test scalability
    char mLR[100] = "[[ 1     ,2, 3 ],[ 2, 4,6   ]]";
    char mRR[100] = "[[ 1     ,2 ],[ 2, 4],[  3,6   ]]";
    assert(readMatrix(mL, mLR) == 0);
    assert(readMatrix(mR, mRR) == 0);
    matrix* tML = tMatrix(mL);
    matrix* tMR = tMatrix(mR);

    matrix* stpTwo = stpMatrix(mL, mR);
    matrix* tStpTwo = tMatrix(stpTwo);

    matrix* twoStpT = stpMatrix(tMR, tML);

    assert(checkIdentityMatrix(twoStpT, tStpTwo) == 0);
    clearMatrix(tML);
    free(tML);
    clearMatrix(mR);
    free(tMR);
    clearMatrix(stpTwo);
    free(stpTwo);
    clearMatrix(tStpTwo);
    free(tStpTwo);
    clearMatrix(twoStpT);
    free(twoStpT);
    return 0;
}