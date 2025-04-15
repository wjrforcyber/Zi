#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

//add matrix
int addCheck(matrix* m0, matrix* m1)
{
    if(m0->dim != m1->dim)
    {
        printf("Dims are not identical.\n");
        return 1;
    }
    if(m0->col != m1->col && m0->row != m1->row)
    {
        printf("Columns/Rows are not identical.\n");
        return 1;
    }
    return 0;
}
matrix* addMatrix(matrix* m0, matrix* m1)
{
    matrix* mR = (matrix *)malloc(sizeof(matrix));
    if(initMatrix(mR) == 1)
    {
        free(mR);
        return NULL;
    }
    if(addCheck(m0, m1) == 1)
    {
        free(mR);
        return NULL;
    }
    mR->dim = m0->dim;
    mR->row = m0->row;
    mR->col = m0->col;
    for(int r = 0; r < m0->row; r++)
    {
        ziArray r0;
        initArray(&r0, 8);
        ziArray r1;
        initArray(&r1, 8);
        fetchMatrixRow(m0, r, &r0);
        fetchMatrixRow(m1, r, &r1);
        ziArray *addRow = addArray(&r0, &r1);
        extendArray(&mR->m, addRow);
        clearArray(&r0);
        clearArray(&r1);
    }
    return mR;
}