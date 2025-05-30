#include "matrix.h"

#include <assert.h>
#include <stdlib.h>

int main() {
    char* eqRes = "[[1,0,0,0,0,0,0,1][0,1,1,1,1,1,1,0]]";
    matrix eqResM;
    matrix* eqComp = &eqResM;
    readMatrix(eqComp, eqRes);
    matrix* eqM = eqMatrix(3);
    assert(checkIdentityMatrix(eqM, eqComp));
    clearMatrix(eqM);
    free(eqM);
    clearMatrix(eqComp);
    return 0;
}