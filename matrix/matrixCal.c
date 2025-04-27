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
    int i = 0;
    int j = 0;
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
    //mR->row_sep = 1;
    int *restruct = (int *)malloc(sizeof(int) * m0->row * m0->col);
    for(int r = 0; r < m0->row; r++)
    {
        ziArray r0;
        initArray(&r0, 8);
        ziArray r1;
        initArray(&r1, 8);
        fetchMatrixRow(m0, r, &r0);
        fetchMatrixRow(m1, r, &r1);
        ziArray *addRow = addArray(&r0, &r1);
        //extendArray(&mR->m, addRow);
        for(int k = 0; k < addRow->size; k++)
        {
            restruct[r * m0->col + k] = *fetchIndexArray(addRow, k);
        }
        clearArray(&r0);
        clearArray(&r1);
        free(fetchIndexArray(addRow, 0));
        clearArray(addRow);
        free(addRow);
    }
    MatrixForEachItem(mR, i , j)
    {
        pushArray(&mR->m, &restruct[i * mR->col + j]);
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
        clearArray(&mR->m);
        free(mR);
        return NULL;
    }
    if(productCheck(m0, m1) == 1)
    {
        clearArray(&mR->m);
        free(mR);
        return NULL;
    }
    int *res = malloc(sizeof(int) * (mR->row * mR->col));
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
    if(initMatrixAttri(res, 2, m0->row, m0->col) != 0)
    {
        free(res);
        return NULL;
    }
    int *resArray = malloc(sizeof(int) * (m0->row * m0->col));
    MatrixForEachItem(m0, i, j)
    {
        resArray[i*m0->col + j] = n * (*getMatrixItemIndex(m0, i, j));
    }
    MatrixForEachItem(m0, i, j)
    {
        pushArray(&res->m, &resArray[i*m0->col + j]);
    }
    return res;
}

//check if two matrix can be concatenate left and right
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
//concatenate left and right matrix
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
    if(initMatrixAttri(res, 2, new_row, new_col) != 0)
    {
        free(res);
        return NULL;
    }
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

//check if two matrix can be concatenate up and down
int checkConcatUDValidity(matrix* m0, matrix* m1)
{
    //check both matrix has same row number
    if(m0->col != m1->col)
    {
        printf("Two matrix has different number of col number");
        return 1;
    }
    return 0;
}
//concatenate left and right matrix
matrix* concatMatrixUDOutPlace(matrix* m0, matrix* m1)
{
    int i = 0;
    int j = 0;
    int new_col = m0->col;
    int new_row = m0->row + m1->row;
    if(checkConcatUDValidity(m0, m1) != 0)
    {
        return NULL;
    }
    matrix * res = (matrix *)malloc(sizeof(matrix));
    if(initMatrixAttri(res, 2, new_row, new_col)!=0)
    {
        free(res);
        return NULL;
    }
    int *resArray = malloc(sizeof(int) * (new_row * new_col));
    for(i = 0; i < m0->row; i++)
    {
        for(j = 0; j < new_col; j++)
        {
            resArray[i * new_col + j] = *getMatrixItemIndex(m0, i, j);
        }
    }
    for(i = m0->row; i < new_row; i++)
    {
        for(j = 0; j < new_col; j++)
        {
            resArray[i * new_col + j] = *getMatrixItemIndex(m0, i - m0->row, j);
        }
    }
    MatrixForEachItem(res, i, j)
    {
        pushArray(&res->m, &resArray[i * new_col + j]);
    }
    return res;
}

//Kronecker product
matrix* kProductMatrix(matrix* m0, matrix* m1)
{
    int i = 0;
    int j = 0;
    matrix ** m_res = malloc(sizeof(matrix *) * (m0->row * m0->col));
    MatrixForEachItem(m0, i, j)
    {
        int n = *getMatrixItemIndex(m0, i ,j);
        matrix *nEach = nTimesMatrixOutplace(m1, n);
        m_res[i * m0->col + j] = nEach;
    }
    
    matrix ** m_rows = malloc(sizeof(matrix *) * m0->row);
    
    for(i = 0; i < m0->row; i++)
    {
        matrix * nEach = m_res[i * m0->col];
        for(j = 1; j < m0->col; j++)
        {
            matrix* mR = m_res[i * m0->col + j];
            nEach = concatMatrixLROutPlace(nEach, mR);
        }
        m_rows[i] = nEach;
    }
    //free the m_res
    for(int i = 0; i < m0->row * m0->col; i++)
    {
        clearMatrix(m_res[i]);
        free(m_res[i]);
    }
    free(m_res);
    matrix * k_res = m_rows[0];
    for(i = 1; i < m0->row; i++)
    {
        k_res = concatMatrixUDOutPlace(k_res, m_rows[i]);
    }
    //free the m_rows
    for(int i = 0; i < m0->row; i++)
    {
        clearMatrix(m_rows[i]);
        free(m_rows[i]);
    }
    free(m_rows);
    return k_res;
}

//semi-tensor product
matrix * stpMatrix(matrix * m0, matrix * m1)
{
    //get the lCM
    int lcm = m0->col > m1->row ? m0->col: m1->row;
    while(lcm % m0->col != 0 || lcm % m1->row != 0)
    {
        lcm *= 2;
    }
    //create the Identidy matrix
    matrix * idL = createIdentityMatrix(lcm/m0->col);
    matrix * idR = createIdentityMatrix(lcm/m1->row);
    matrix * kProL = kProductMatrix(m0, idL);
    matrix * kProR = kProductMatrix(m1, idR);
    matrix * res = productMatrix(kProL, kProR);
    clearMatrix(idL);
    free(idL);
    clearMatrix(idR);
    free(idR);
    clearMatrix(kProL);
    free(kProL);
    clearMatrix(kProR);
    free(kProR);
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