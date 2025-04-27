#include "matrix.h"
#include <assert.h>
int main()
{
    matrix test;
    matrix* mI = &test;
    //give wired example to test scalability
    char mS[100] = "[[ 1     ,0, 0 ],[ 0, 1,0   ],[0,0,1]]";
    assert(readMatrix(mI, mS) == 0);
    
    matrix* id = createIdentityMatrix(3);
    assert(checkIdentityMatrix(mI, id) == 0);
    
    clearMatrix(mI);
    clearMatrix(id);
    free(id);
}