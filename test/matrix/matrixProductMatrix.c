#include "matrix.h"
#include <assert.h>
int main()
{
    int i;
    int resCheck;
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
    ziArray * p1 = &pRes->m;
    ziArray* p2 = &resA;
    ArraryCheckIndentity(p1, p2, int *, i, &resCheck);
    assert(resCheck == 0);
    assert(clearArray(&resA) == 0);
    assert(clearMatrix(mIL) == 0);
    assert(clearMatrix(mIR) == 0);
    assert(clearMatrix(mIWrong) == 0);
    assert(clearMatrix(pRes) == 0);
    free(pRes);
    return 0;
}