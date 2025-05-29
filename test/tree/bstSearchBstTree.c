#include "bst.h"
#include <assert.h>

int main()
{
    int data[] = { 3, 5, 10, 6 ,1, 2};
    ziArray a;
    ziArray *pA = &a;
    initArray(pA, 10);
    for(int i = 0; i < 6; i++)
    {
        pushArray(pA, &data[i]);
    }
    bstTree * tree = initBstTree(pA);

    int tVal = 5;
    int *target = &tVal;
    bstNode * res = searchBstTreeRec(tree->pRoot, target);
    assert(isNilBstNode(res) == 0);

    int tVal0 = 7;
    target = &tVal0;
    bstNode * resNULL = searchBstTreeRec(tree->pRoot, target);
    assert(resNULL->pData == NULL);
    assert(isNilBstNode(resNULL) == 1);

    clearBstTree(tree);
    clearArray(pA);
    return 0;
}