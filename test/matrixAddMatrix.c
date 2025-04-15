#include "matrix.h"
#include <assert.h>

int main()
{
    matrix test0;
    matrix* mI0 = &test0;
    
    matrix test1;
    matrix* mI1 = &test1;
    //give wired example to test scalability
    char mS0[100] = "[[ 1     ,2, 3 ],[ 2, 4,6   ]]";
    char mS1[100] = "[[12, 32,    4], [  9,  2, 11  ]]";
    assert(readMatrix(mI0, mS0) == 0);
    assert(readMatrix(mI1, mS1) == 0);
    
    matrix* res = addMatrix(mI0, mI1);
    assert(res != NULL);
    showDigitsArray(&res->m);
    ziArray resComp;
    initArray(&resComp, 8);
    int resI[6] = {13,34,7,11,6,17};
    for(int i = 0 ; i < 6; i++)
    {
        pushArray(&resComp, &resI[i]);
    }
    assert(checkIdentityArray(&res->m, &resComp) == 0);
}