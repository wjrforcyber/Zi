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

//product precheck
int productCheck(matrix* m0, matrix* m1)
{
    if(m0->col != m1->row)
    {
        printf("Can't perform product due to wrong dimension.\n");
        return 1;
    }
    return 0;
}
//matrix product
matrix* productMatrix(matrix* m0, matrix* m1)
{
    int i = 0;
    int j = 0;
    matrix* mR = (matrix *)malloc(sizeof(matrix));
    if(initMatrixAttri(mR, 2, m0->row, m1->col) == 1)
    {
        free(mR);
        return NULL;
    }
    if(productCheck(m0, m1) == 1)
    {
        free(mR);
        return NULL;
    }
    int *res = malloc(sizeof(int) * (mR->row & mR->col));
    MatrixForEachItem(mR, i, j)
    {
        ziArray r0;
        initArray(&r0, 8);
        ziArray r1;
        initArray(&r1, 8);
        fetchMatrixRow(m0, i, &r0);
        fetchMatrixCol(m1, j, &r1);
        res[i * mR->row + j] = productIntArray(&r0, &r1);
        clearArray(&r0);
        clearArray(&r1);
    }
    MatrixForEachItem(mR, i, j)
    {
        pushArray(&mR->m, &res[i * mR->row + j]);
    }
    return mR;
}

//fetch the item on row and col
int *getMatrixItemIndex(matrix* m0, int row ,int col)
{
    return fetchIndexArray(&m0->m, row * m0->col + col);
}
//n times matrix
void nTimesMatrixInplace(matrix* m0, int n)
{
    int i = 0;
    int j = 0;
    MatrixForEachItem(m0, i, j)
    {
        *getMatrixItemIndex(m0, i, j) = n * (*getMatrixItemIndex(m0, i, j));
    }
}

//n times matrix
matrix* nTimesMatrixOutplace(matrix* m0, int n)
{
    int i = 0;
    int j = 0;
    matrix * res = (matrix *)malloc(sizeof(matrix));
    initMatrix(res);
    int *resArray = malloc(sizeof(int) * (m0->m.size));
    MatrixForEachItem(m0, i, j)
    {
        resArray[i*m0->col + j] = n * (*getMatrixItemIndex(m0, i, j));
    }
    MatrixForEachItem(m0, i, j)
    {
        pushArray(&res->m, &resArray[i*m0->col + j]);
    }
    return 0;
}

int checkConcatLRValidity(matrix* m0, matrix* m1)
{
    //check both matrix has same row number
    if(m0->row != m1->row)
    {
        printf("Two matrix has different number of row number");
        return 1;
    }
    return 0;
}
matrix* concatMatrixLROutPlace(matrix* m0, matrix* m1)
{
    int i = 0;
    int j = 0;
    int new_col = m0->col + m1->col;
    int new_row = m0->row;
    if(checkConcatLRValidity(m0, m1) != 0)
    {
        return NULL;
    }
    matrix * res = (matrix *)malloc(sizeof(matrix));
    initMatrixAttri(res, 2, new_row, new_col);
    int *resArray = malloc(sizeof(int) * (new_row * new_col));
    for(i = 0; i < new_row; i++)
    {
        for(j = 0; j < m0->col; j++)
        {
            resArray[i * new_col + j] = *getMatrixItemIndex(m0, i, j);
        }
        for(j = m0->col; j < new_col; j++)
        {
            resArray[i * new_col + j] = *getMatrixItemIndex(m0, i, j - m0->col);
        }
    }
    MatrixForEachItem(res, i, j)
    {
        pushArray(&res->m, &resArray[i * new_col + j]);
    }
    return res;
}

//check matix identity
int checkIdentityMatrix(matrix* m0, matrix* m1)
{
    if(m0->dim != m1->dim || m0->row != m1->row || m0->col != m1->col)
    {
        printf("Dimension or attributes are not identical.\n");
        return 1;
    }
    return 0;
}