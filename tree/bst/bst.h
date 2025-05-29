#include "array.h"
typedef struct bstNode_ bstNode;
typedef struct bstTree_ bstTree;

struct bstNode_
{
    int isNil;
    bstNode* lBstNode;
    bstNode* rBstNode;
    void* pData;
};

/*
BST structure, only one NIL node exists in the tree structure, and always in the first position of the pAllNodes
*/
struct bstTree_
{
    int nHight;
    bstNode* pRoot;
    bstNode* pNil;
    ziArray* pAllNodes; //contains all bstNodes other than any other datatype
};
int isNilBstNode( bstNode * pNode );
bstNode* getNilNode( bstTree * pTree);
bstTree* initBstTree( ziArray * data );
void clearBstTree( bstTree* pTree );
void inOrderBstTree( bstTree* pTree, ziArray* pArray );
bstNode* searchBstTreeRec( bstNode* pRoot,int* pTarget );
bstNode* searchBstTreeIter( bstNode* pRoot, int* pTarget );

#define bstNodeCompare( a, b, ItemType, res) \
    if(*(ItemType)(a->pData) >= *(ItemType)(b->pData)) {*res = 1;} \
    else {*res = 0;}