#include "matrix.h"
#include <assert.h>

int main()
{
    matrix test;
    matrix* mI = &test;
    //give wired example to test scalability
    char mS[100] = "[[ 1     ,2, 3 ],[ 2, 4,6   ]]";
    char *mtest = &mS[0];
    assert(readMatrix(mI, mtest) == 0);
    assert(mI->dim == 2);
    assert(mI->row == 2);
    assert(mI->col == 3);
    return 0;
}