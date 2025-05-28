#include "bst.h"
#include <assert.h>

int main()
{
    int data[] = { 3, 5, 10, 6 ,1, 2};
    ziArray a;
    ziArray *pA = &a;
    ziArray b;
    ziArray *res = &b;
    initArray(pA, 10);
    for(int i = 0; i < 6; i++)
    {
        pushArray(pA, &data[i]);
    }
    bstTree * tree = initBstTree(pA);
    inOrderBstTree(tree, res);
    
    int target[] = {1,2,3,5,6,10};
    ziArray tar;
    ziArray *tarRes = &tar;
    initArray(tarRes, 10);
    for(int i = 0; i < 6; i++)
    {
        pushArray(tarRes, &target[i]);
    }

    ziArray* p1 = tarRes;
    ziArray* p2 = res;
    int i, resCheck;
    ArraryCheckIndentity(p1, p2, int *, i, &resCheck);
    assert(resCheck == 0);
    
    clearBstTree(tree);
    clearArray(pA);
    clearArray(res);
    clearArray(tarRes);
    return 0;
}