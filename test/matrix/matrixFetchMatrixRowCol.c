#include "matrix.h"
#include <assert.h>

int main()
{
    int resCheck,i;
    matrix test;
    matrix* mI = &test;
    //give wired example to test scalability
    char mS[100] = "[[ 1     ,2, 3 ],[ 2, 4,6   ]]";
    assert(readMatrix(mI, mS) == 0);
    int aComp0[3] = {1,2,3};
    int aComp1[3] = {2,4,6};
    
    int aOriCol0[2] = {1,2};
    int aOriCol2[2] = {3,6};
    
    ziArray originCheck0;
    initArray(&originCheck0, 8);
    ziArray originCheck1;
    initArray(&originCheck1, 8);
    for(int i = 0; i < 3; i++)
    {
        pushArray(&originCheck0, &aComp0[i]);
        pushArray(&originCheck1, &aComp1[i]);
    }
    
    ziArray originCheckCol0;
    initArray(&originCheckCol0, 8);
    ziArray originCheckCol2;
    initArray(&originCheckCol2, 8);
    for(int j = 0; j < 2; j++)
    {
        pushArray(&originCheckCol0, &aOriCol0[j]);
        pushArray(&originCheckCol2, &aOriCol2[j]);
    }
    
    
    ziArray row0;
    initArray(&row0, 8);
    ziArray row1;
    initArray(&row1, 8);
    ziArray col0;
    initArray(&col0, 8);
    ziArray col2;
    initArray(&col2, 8);
    assert(fetchMatrixRow(mI, 0, &row0) == 0 );
    assert(fetchMatrixRow(mI, 1, &row1) == 0 );
    ziArray * p1 = &row0;
    ziArray* p2 = &originCheck0;
    ArraryCheckIndentity(p1, p2, int *, i, &resCheck);
    assert(resCheck == 0);
    p1 = &row1;
    p2 = &originCheck1;
    ArraryCheckIndentity(p1, p2, int *, i, &resCheck);
    assert(resCheck == 0);
    
    assert(fetchMatrixCol(mI, 0, &col0) == 0 );
    assert(fetchMatrixCol(mI, 2, &col2) == 0 );
    p1 = &col0;
    p2 = &originCheckCol0;
    ArraryCheckIndentity(p1, p2, int *, i, &resCheck);
    assert(resCheck == 0);
    p1 = &col2;
    p2 = &originCheckCol2;
    ArraryCheckIndentity(p1, p2, int *, i, &resCheck);
    assert(resCheck == 0);

    
    clearArray(&row0);
    clearArray(&row1);
    clearArray(&col0);
    clearArray(&col2);
    clearArray(&originCheck0);
    clearArray(&originCheck1);
    clearArray(&originCheckCol0);
    clearArray(&originCheckCol2);
    clearMatrix(mI);
    return 0;
}