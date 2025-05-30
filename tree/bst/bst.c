#include "bst.h"

#include <stdlib.h>

void assertBstTree(bstTree* pTree, bstNode* pItem) {
    // empty tree
    if (pTree->pRoot == NULL) {
        pTree->pRoot = pItem;
        pItem->lBstNode = getNilNode(pTree);
        pItem->rBstNode = getNilNode(pTree);
    }

    // non-empty tree
    int res;
    int isLeft;
    bstNode* pToComp = pTree->pRoot;
    bstNode* preStep = pTree->pRoot;

    /*Terminate condition
    Meet the NIL node, mark left and right child as NIL node, naturally attached
    to the tree
    */
    while (isNilBstNode(pToComp) != 1) {
        isLeft = -1;
        bstNodeCompare(pItem, pToComp, int*, &res);
        preStep = pToComp;

        if (res > 0) {
            pToComp = pToComp->rBstNode;
            isLeft = 0;
        } else {
            pToComp = pToComp->lBstNode;
            isLeft = 1;
        }
    }
    isLeft == 1 ? (preStep->lBstNode = pItem) : (preStep->rBstNode = pItem);
    pItem->lBstNode = getNilNode(pTree);
    pItem->rBstNode = getNilNode(pTree);
}

// retrieve the NIL node
bstNode* getNilNode(bstTree* pTree) {
    if (pTree->pAllNodes->size != 0) {
        return fetchIndexArray(pTree->pAllNodes, 0);
    }
    return NULL;
}

// check if it is the terminate node
int isNilBstNode(bstNode* pNode) {
    if (pNode->isNil == 1) {
        return 1;
    } else {
        return 0;
    }
}

// initialize the NIL node
void initNilNode(bstNode* pNode) {
    pNode->isNil = 1;
    pNode->lBstNode = NULL;
    pNode->rBstNode = NULL;
    pNode->pData = NULL;
}

// initialize the bst tree
bstTree* initBstTree(ziArray* data) {
    int i;
    bstTree* pTree = (bstTree*)malloc(sizeof(bstTree));
    pTree->pRoot = NULL;
    pTree->nHight = 0;
    pTree->pAllNodes = (ziArray*)malloc(sizeof(ziArray));
    initArray(pTree->pAllNodes, 100);

    // init NIL node
    bstNode* pNode = (bstNode*)malloc(sizeof(bstNode));
    initNilNode(pNode);
    pTree->pNil = pNode;
    pushArray(pTree->pAllNodes, pNode);

    ArrayForEachItem(data, i) {
        bstNode* pNodeEach = (bstNode*)malloc(sizeof(bstNode));
        pNodeEach->isNil = 0;
        pNodeEach->lBstNode = NULL;
        pNodeEach->rBstNode = NULL;
        pNodeEach->pData = fetchIndexArray(data, i);
        assertBstTree(pTree, pNodeEach);
        pushArray(pTree->pAllNodes, pNodeEach);
    }
    return pTree;
}

// clear the bst tree
void clearBstTree(bstTree* pTree) {
    clearEachEntryArray(pTree->pAllNodes);
    free(pTree->pAllNodes);
    free(pTree);
}

// show the bst tree in inorder(For n node tree, takes Theta(n) time -
// Theorem 12.1)
void collectInOrder(bstNode* pRoot, ziArray* pArray) {
    if (isNilBstNode(pRoot) != 1) {
        collectInOrder(pRoot->lBstNode, pArray);
        pushArray(pArray, pRoot);
        collectInOrder(pRoot->rBstNode, pArray);
    }
}

// show digits array
int showDigitsArrayBstNode(ziArray* a) {
    if (a->size == 0) {
        printf("Array size is 0, nothing to print.\n");
        return 1;
    }
    printf("Warning: Only proper on int type.\n");
    int index = 0;
    printf("Array contains:\n");
    for (index = 0; index < a->size; index++) {
        if (index == a->size - 1) {
            printf("%d\n", *(int*)(*(bstNode*)fetchIndexArray(a, index)).pData);
        } else {
            printf("%d ", *(int*)(*(bstNode*)fetchIndexArray(a, index)).pData);
        }
    }
    return 0;
}

void inOrderBstTree(bstTree* pTree, ziArray* pArray) {
    initArray(pArray, 100);
    collectInOrder(pTree->pRoot, pArray);
    showDigitsArrayBstNode(pArray);
}

// tree search node, if return NIL(Not found), else found.
bstNode* searchBstTreeRec(bstNode* pRoot, int* pTarget) {
    if (isNilBstNode(pRoot) || *(int*)pRoot->pData == *pTarget) {
        return pRoot;
    }
    if (*pTarget <= *(int*)pRoot->pData) {
        return searchBstTreeRec(pRoot->lBstNode, pTarget);
    } else {
        return searchBstTreeRec(pRoot->rBstNode, pTarget);
    }
}
// expose the unrolled iterative way, which is more efficient than the recursive
// method above. (O(h))
bstNode* searchBstTreeIter(bstNode* pRoot, int* pTarget) {
    while (!isNilBstNode(pRoot) && (*pTarget != *(int*)pRoot->pData)) {
        if (*pTarget <= *(int*)pRoot->pData) {
            pRoot = pRoot->lBstNode;
        } else {
            pRoot = pRoot->rBstNode;
        }
    }
    return pRoot;
}

// get the maximum/minimum node
bstNode* getMaxMinMaxNodeBstTree(bstNode* pRoot, int max) {
    if (max == 1) {
        while (isNilBstNode(pRoot->rBstNode) == 0) {
            pRoot = pRoot->rBstNode;
        }
    } else {
        while (isNilBstNode(pRoot->lBstNode) == 0) {
            pRoot = pRoot->lBstNode;
        }
    }
    return pRoot;
}