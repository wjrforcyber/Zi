#include "matrix.h"

#include <assert.h>
#include <stdlib.h>

int main() {
    matrix test1;
    matrix* mI1 = &test1;
    // give wired example to test scalability
    char mS1[100] = "[[ 1     ,1, 1,1 ],[ 0, 0,0,0   ]]";
    char mS0[100] = "[[ 0,0, 0, 0,0,0,0,0 ],[ 1, 1,1,   1,1,1,1,1  ]]";
    char mS[100] = "[[ 1     ,0, 0,1 ],[ 0, 1,1,0   ]]";
    matrix test0;
    matrix* mI0 = &test0;
    matrix test;
    matrix* mI = &test;

    assert(readMatrix(mI1, mS1) == 0);
    assert(readMatrix(mI0, mS0) == 0);
    assert(readMatrix(mI, mS) == 0);
    matrix* const1 = getConst1(2);
    matrix* const0 = getConst0(3);

    assert(checkIdentityMatrix(const1, mI1) == 0);
    assert(checkIdentityMatrix(const0, mI0) == 0);

    clearMatrix(const0);
    free(const0);
    clearMatrix(const1);
    free(const1);
    clearMatrix(mI1);
    clearMatrix(mI0);
    clearMatrix(mI);
    return 0;
}