#include <assert.h>

#include "bst.h"

int main() {
    int data[] = {3, 5, 10, 6, 1, 2};
    ziArray a;
    ziArray* pA = &a;
    initArray(pA, 10);
    for (int i = 0; i < 6; i++) {
        pushArray(pA, &data[i]);
    }
    bstTree* tree = initBstTree(pA);

    bstNode* nMax = getMaxMinMaxNodeBstTree(tree->pRoot, 1);
    assert(*(int*)nMax->pData == 10);
    bstNode* nMin = getMaxMinMaxNodeBstTree(tree->pRoot, 0);
    assert(*(int*)nMin->pData == 1);

    clearBstTree(tree);
    clearArray(pA);
    return 0;
}
