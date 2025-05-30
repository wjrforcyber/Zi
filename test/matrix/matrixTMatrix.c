#include "matrix.h"

#include <assert.h>
#include <stdlib.h>

int main() {
    matrix test;
    matrix* mI = &test;
    matrix res;
    matrix* mRes = &res;
    // give wired example to test scalability
    char mS[100] = "[[ 1     ,2, 3 ],[ 2, 4,6   ]]";
    char mR[100] = "[[ 1     ,2 ],[ 2, 4],[  3,6   ]]";
    assert(readMatrix(mI, mS) == 0);
    assert(readMatrix(mRes, mR) == 0);
    matrix* tM = tMatrix(mI);
    showDigitsMatrix(tM);
    assert(checkIdentityMatrix(tM, mRes) == 0);
    clearMatrix(tM);
    free(tM);
    clearMatrix(mI);
    clearMatrix(mRes);
    return 0;
}