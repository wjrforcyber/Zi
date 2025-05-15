#include "matrix.h"
#include <assert.h>
#include <stdlib.h>

int main()
{
    int m = 2;
    int n = 3;
    matrix res;
    matrix * mI = &res;
    char resComp[] = "[[1,0,0,0 , 0, 0], [ 0, 0,  0, 1,0,0], [0,1,0,0,0,0],[0,0,0,0,1,0],[0,0,1,0,0,0],[0,0,0,0,0,1]]";
    assert(readMatrix(mI, resComp) == 0);
    
    matrix* swapM = swapMatrix(m, n);
    showDigitsMatrix(swapM);
    assert(checkIdentityMatrix(swapM, mI) == 0);
    clearMatrix(swapM);
    free(swapM);
    clearMatrix(mI);
    return 0;
}