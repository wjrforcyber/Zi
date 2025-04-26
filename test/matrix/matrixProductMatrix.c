#include "matrix.h"
#include <assert.h>
int main()
{
    char mL[100] = "[[ 1     ,2, 3 ],[ 2, 4,6   ]]";
    char mR[100] = "[[ 1     ,2], [3 , 4],[ 5 ,6   ]]";
    char mWrong[100] = "[[ 1     ,2, 3 ],[ 2, 4,6   ]]";
    int res[] = {22,28, 44, 56};
    ziArray resA;
    initArray(&resA, 8);
    for(int i = 0; i < 4; i++)
    {
        pushArray(&resA, &res[i]);
    }
    
    matrix testL;
    matrix* mIL = &testL;
    
    matrix testR;
    matrix* mIR = &testR;
    
    matrix testWrong;
    matrix* mIWrong = &testWrong;
    assert(readMatrix(mIL, mL) == 0);
    assert(readMatrix(mIR, mR) == 0);
    assert(readMatrix(mIWrong, mWrong) == 0);
    assert(productMatrix(mIL, mIWrong) == NULL);
    matrix * pRes = productMatrix(mIL, mIR);
    assert(checkIdentityArray(&pRes->m, &resA) == 0);
    clearArray(&resA);
    free(pRes);
    return 0;
}