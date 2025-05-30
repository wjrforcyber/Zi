#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "utilMatrix.h"

// add matrix
int addCheck(matrix *m0, matrix *m1) {
    if (m0->dim != m1->dim) {
        printf("Dims are not identical.\n");
        return 1;
    }
    if (m0->col != m1->col && m0->row != m1->row) {
        printf("Columns/Rows are not identical.\n");
        return 1;
    }
    return 0;
}
matrix *addMatrix(matrix *m0, matrix *m1) {
    int i = 0;
    int j = 0;
    matrix *mR = (matrix *)malloc(sizeof(matrix));
    if (initMatrix(mR) == 1) {
        free(mR);
        return NULL;
    }
    if (addCheck(m0, m1) == 1) {
        free(mR);
        return NULL;
    }
    mR->dim = m0->dim;
    mR->row = m0->row;
    mR->col = m0->col;
    // mR->row_sep = 1;
    int *restruct = (int *)malloc(sizeof(int) * m0->row * m0->col);
    for (int r = 0; r < m0->row; r++) {
        ziArray r0;
        initArray(&r0, 8);
        ziArray r1;
        initArray(&r1, 8);
        fetchMatrixRow(m0, r, &r0);
        fetchMatrixRow(m1, r, &r1);
        ziArray *addRow = addArray(&r0, &r1);
        // extendArray(&mR->m, addRow);
        for (int k = 0; k < addRow->size; k++) {
            restruct[r * m0->col + k] = *(int *)fetchIndexArray(addRow, k);
        }
        clearArray(&r0);
        clearArray(&r1);
        free(fetchIndexArray(addRow, 0));
        clearArray(addRow);
        free(addRow);
    }
    MatrixForEachItem(mR, i, j) {
        pushArray(&mR->m, &restruct[i * mR->col + j]);
    }
    return mR;
}

// product precheck
int productCheck(matrix *m0, matrix *m1) {
    if (m0->col != m1->row) {
        printf("Can't perform product due to wrong dimension.\n");
        return 1;
    }
    return 0;
}
// matrix product
matrix *productMatrix(matrix *m0, matrix *m1) {
    int i = 0;
    int j = 0;
    matrix *mR = (matrix *)malloc(sizeof(matrix));
    if (initMatrixAttri(mR, 2, m0->row, m1->col) == 1) {
        clearArray(&mR->m);
        free(mR);
        return NULL;
    }
    if (productCheck(m0, m1) == 1) {
        clearArray(&mR->m);
        free(mR);
        return NULL;
    }
    int *res = malloc(sizeof(int) * (mR->row * mR->col));

    for (int i = 0; i < mR->row; i++) {
        for (int j = 0; j < mR->col; j++) {
            ziArray r0;
            initArray(&r0, 8);
            ziArray r1;
            initArray(&r1, 8);
            fetchMatrixRow(m0, i, &r0);
            fetchMatrixCol(m1, j, &r1);
            res[i * mR->col + j] = productIntArray(&r0, &r1);
            clearArray(&r0);
            clearArray(&r1);
        }
    }
    MatrixForEachItem(mR, i, j) { pushArray(&mR->m, &res[i * mR->col + j]); }
    return mR;
}

// fetch the item on row and col
int *getMatrixItemIndex(matrix *m0, int row, int col) {
    return fetchIndexArray(&m0->m, row * m0->col + col);
}
// n times matrix
void nTimesMatrixInplace(matrix *m0, int n) {
    int i = 0;
    int j = 0;
    MatrixForEachItem(m0, i, j) {
        *getMatrixItemIndex(m0, i, j) = n * (*getMatrixItemIndex(m0, i, j));
    }
}

// n times matrix
matrix *nTimesMatrixOutplace(matrix *m0, int n) {
    int i = 0;
    int j = 0;
    matrix *res = (matrix *)malloc(sizeof(matrix));
    if (initMatrixAttri(res, 2, m0->row, m0->col) != 0) {
        free(res);
        return NULL;
    }
    int *resArray = malloc(sizeof(int) * (m0->row * m0->col));
    MatrixForEachItem(m0, i, j) {
        resArray[i * m0->col + j] = n * (*getMatrixItemIndex(m0, i, j));
    }
    MatrixForEachItem(m0, i, j) {
        pushArray(&res->m, &resArray[i * m0->col + j]);
    }
    return res;
}

// check if two matrix can be concatenate left and right
int checkConcatLRValidity(matrix *m0, matrix *m1) {
    // check both matrix has same row number
    if (m0->row != m1->row) {
        printf("Two matrix has different number of row number");
        return 1;
    }
    return 0;
}
// concatenate left and right matrix
matrix *concatMatrixLROutPlace(matrix *m0, matrix *m1) {
    int i = 0;
    int j = 0;
    int new_col = m0->col + m1->col;
    int new_row = m0->row;
    if (checkConcatLRValidity(m0, m1) != 0) {
        return NULL;
    }
    matrix *res = (matrix *)malloc(sizeof(matrix));
    if (initMatrixAttri(res, 2, new_row, new_col) != 0) {
        free(res);
        return NULL;
    }
    int *resArray = malloc(sizeof(int) * (new_row * new_col));
    for (i = 0; i < new_row; i++) {
        for (j = 0; j < m0->col; j++) {
            resArray[i * new_col + j] = *getMatrixItemIndex(m0, i, j);
        }
        for (j = m0->col; j < new_col; j++) {
            resArray[i * new_col + j] = *getMatrixItemIndex(m1, i, j - m0->col);
        }
    }
    MatrixForEachItem(res, i, j) {
        pushArray(&res->m, &resArray[i * new_col + j]);
    }
    return res;
}

// check if two matrix can be concatenate up and down
int checkConcatUDValidity(matrix *m0, matrix *m1) {
    // check both matrix has same row number
    if (m0->col != m1->col) {
        printf("Two matrix has different number of col number");
        return 1;
    }
    return 0;
}
// concatenate left and right matrix
matrix *concatMatrixUDOutPlace(matrix *m0, matrix *m1) {
    int i = 0;
    int j = 0;
    int new_col = m0->col;
    int new_row = m0->row + m1->row;
    if (checkConcatUDValidity(m0, m1) != 0) {
        return NULL;
    }
    matrix *res = (matrix *)malloc(sizeof(matrix));
    if (initMatrixAttri(res, 2, new_row, new_col) != 0) {
        free(res);
        return NULL;
    }
    int *resArray = malloc(sizeof(int) * (new_row * new_col));
    for (i = 0; i < m0->row; i++) {
        for (j = 0; j < new_col; j++) {
            resArray[i * new_col + j] = *getMatrixItemIndex(m0, i, j);
        }
    }
    for (i = m0->row; i < new_row; i++) {
        for (j = 0; j < new_col; j++) {
            resArray[i * new_col + j] = *getMatrixItemIndex(m1, i - m0->row, j);
        }
    }
    MatrixForEachItem(res, i, j) {
        pushArray(&res->m, &resArray[i * new_col + j]);
    }
    return res;
}

// Kronecker product
matrix *kProductMatrix(matrix *m0, matrix *m1) {
    // if right matrix is identity with dimension 1
    int i = 0;
    int j = 0;
    matrix **m_res = malloc(sizeof(matrix *) * (m0->row * m0->col));
    MatrixForEachItem(m0, i, j) {
        int n = *getMatrixItemIndex(m0, i, j);
        matrix *nEach = nTimesMatrixOutplace(m1, n);
        m_res[i * m0->col + j] = nEach;
    }

    matrix **m_rows = malloc(sizeof(matrix *) * m0->row);

    for (i = 0; i < m0->row; i++) {
        matrix *nEach = m_res[i * m0->col];
        if (m0->col != 1) {
            // matrix ** each_free = malloc(sizeof(matrix *) * m0->col - 2);
            for (j = 1; j < m0->col; j++) {
                matrix *old = nEach;
                matrix *mR = m_res[i * m0->col + j];
                nEach = concatMatrixLROutPlace(old, mR);
                // start from 1, this does not free m_res[0]
                if (j > 1) {
                    clearMatrix(old);
                    free(old);
                }
            }
        }
        m_rows[i] = nEach;
    }

    matrix *k_res = m_rows[0];
    if (m0->row != 1) {
        for (i = 1; i < m0->row; i++) {
            matrix *old = k_res;
            k_res = concatMatrixUDOutPlace(old, m_rows[i]);
            if (i > 1) {
                clearMatrix(old);
                free(old);
            }
        }
    }
    // free the m_res
    for (int i = 0; i < m0->row * m0->col; i++) {
        clearMatrix(m_res[i]);
        free(m_res[i]);
    }
    free(m_res);
    // if only one column, the first matrix(column) has already been freed
    if (m0->col == 1) {
        free(m_rows);
        return k_res;
    }
    // free the m_rows
    for (int i = 0; i < m0->row; i++) {
        clearMatrix(m_rows[i]);
        free(m_rows[i]);
    }
    free(m_rows);
    return k_res;
}

// semi-tensor product
matrix *stpMatrix(matrix *m0, matrix *m1) {
    // special case
    if (m0->col == m1->row) {
        return productMatrix(m0, m1);
    }
    // get the lCM
    int lcm = m0->col > m1->row ? m0->col : m1->row;
    while (lcm % m0->col != 0 || lcm % m1->row != 0) {
        lcm *= 2;
    }
    // create the Identidy matrix
    matrix *idL = createIdentityMatrix(lcm / m0->col);
    // printf("Id L:\n");
    // showDigitsArray(&idL->m);
    matrix *idR = createIdentityMatrix(lcm / m1->row);
    // printf("Id R:\n");
    // showDigitsArray(&idR->m);
    matrix *kProL = kProductMatrix(m0, idL);
    // printf("KPro L:\n");
    // showDigitsArray(&kProL->m);
    matrix *kProR = kProductMatrix(m1, idR);
    // printf("KPro R:\n");
    // showDigitsArray(&kProR->m);
    matrix *res = productMatrix(kProL, kProR);
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

// check matix identity
int checkIdentityMatrix(matrix *m0, matrix *m1) {
    if (m0->dim != m1->dim || m0->row != m1->row || m0->col != m1->col) {
        printf("Dimension or attributes are not identical.\n");
        printf("Matrix Left\t\tMtairx Right\t\t\n");
        printf("Dim(%d %d)\t\tRow(%d %d)\t\tCol(%d %d)\n", m0->dim, m1->dim,
               m0->row, m1->row, m0->col, m1->col);
        return 1;
    }
    int i = 0;
    int j = 0;
    MatrixForEachItem(m0, i, j) {
        if (*getMatrixItemIndex(m0, i, j) != *getMatrixItemIndex(m1, i, j)) {
            return 1;
        }
    }
    return 0;
}

// STP: NOT operator
matrix *notMatrix() {
    matrix *not_res = (matrix *)malloc(sizeof(matrix));
    initMatrixAttri(not_res, 2, 2, 2);
    int *not = (int *)malloc(sizeof(int) * 4);
    //[[0,1],[1,0]]
    not [0] = 0;
    not [1] = 1;
    not [2] = 1;
    not [3] = 0;
    for (int i = 0; i < 4; i++) {
        pushArray(&not_res->m, &not [i]);
    }
    return not_res;
}

// STP: EQ operator
matrix *eqMatrix(int n) {
    matrix *eq_res = (matrix *)malloc(sizeof(matrix));
    int col = 1 << n;
    initMatrixAttri(eq_res, 2, 2, 2 * col);
    int *eq = (int *)malloc(sizeof(int) * 2 * col);

    for (int i = 0; i < col; i++) {
        if (i == 0 || i == col - 1) {
            eq[i] = 1;
        } else {
            eq[i] = 0;
        }
        pushArray(&eq_res->m, &eq[i]);
    }
    for (int i = col; i < 2 * col; i++) {
        if (i == col || i == 2 * col - 1) {
            eq[i] = 0;
        } else {
            eq[i] = 1;
        }
        pushArray(&eq_res->m, &eq[i]);
    }
    return eq_res;
}

// STP: AND operator N
matrix *andNMatrix(int n) {
    matrix *and_res = (matrix *)malloc(sizeof(matrix));
    int col = 1 << n;
    initMatrixAttri(and_res, 2, 2, col);
    int *and = (int *)malloc(sizeof(int) * (2 * col));
    for (int i = 0; i < col; i++) {
        if (i == 0) {
            and[i] = 1;
        } else {
            and[i] = 0;
        }
        pushArray(&and_res->m, &and[i]);
    }
    for (int i = col; i < 2 * col; i++) {
        if (i == col) {
            and[i] = 0;
        } else {
            and[i] = 1;
        }
        pushArray(&and_res->m, &and[i]);
    }
    return and_res;
}

// STP: OR operator N
matrix *orNMatrix(int n) {
    matrix *or_res = (matrix *)malloc(sizeof(matrix));
    int col = 1 << n;
    initMatrixAttri(or_res, 2, 2, col);
    int * or = (int *)malloc(sizeof(int) * (2 * col));
    for (int i = 0; i < col; i++) {
        if (i == col - 1) {
            or [i] = 0;
        } else {
            or [i] = 1;
        }
        pushArray(&or_res->m, & or [i]);
    }
    for (int i = col; i < 2 * col; i++) {
        if (i == 2 * col - 1) {
            or [i] = 1;
        } else {
            or [i] = 0;
        }
        pushArray(&or_res->m, & or [i]);
    }
    return or_res;
}

// STP: CONST1 N
matrix *getConst1(int n) {
    int col = 1 << n;
    matrix *const1;
    const1 = (matrix *)malloc(sizeof(matrix));
    initMatrixAttri(const1, 2, 2, col);
    int *const_res = (int *)malloc(sizeof(int) * 2 * col);
    for (int i = 0; i < 2 * col; i++) {
        if (i < col) {
            const_res[i] = 1;
        } else {
            const_res[i] = 0;
        }
        pushArray(&const1->m, &const_res[i]);
    }
    return const1;
}

// STP: CONST0 N
matrix *getConst0(int n) {
    matrix *not = notMatrix();
    matrix *const1 = getConst1(n);
    showDigitsMatrix(const1);
    matrix *const0 = stpMatrix(not, const1);
    clearMatrix(const1);
    free(const1);
    clearMatrix(not );
    free(not );
    return const0;
}

// Matrix transpose
matrix *tMatrix(matrix *m) {
    matrix *tRes = (matrix *)malloc(sizeof(matrix));
    int newRow = m->col;
    int newCol = m->row;
    initMatrixAttri(tRes, 2, newRow, newCol);
    int i, j;
    int *t = (int *)malloc(sizeof(int) * (newRow * newCol));
    MatrixForEachItemColRow(m, i, j) {
        t[i * m->row + j] = *getMatrixItemIndex(m, j, i);
        pushArray(&tRes->m, &t[i * m->row + j]);
    }
    return tRes;
}

// STP: Matrix transpose property
matrix *stpTwoTMatrix(matrix *m0, matrix *m1) {
    matrix *tL = tMatrix(m0);
    matrix *tR = tMatrix(m1);
    matrix *res = stpMatrix(tL, tR);
    clearMatrix(tL);
    free(tL);
    clearMatrix(tR);
    free(tR);
    return res;
}

// STP: Swap matrix m*n*m*n
matrix *swapMatrix(int m, int n) {
    matrix *res = (matrix *)malloc(sizeof(matrix));
    int newRow = m * n;
    int newCol = m * n;
    initMatrixAttri(res, 2, newRow, newCol);

    // prepare the result matrix
    int *res_i = (int *)malloc(sizeof(int) * newRow * newCol);
    // All initialize to 0
    memset(res_i, 0, sizeof(int) * newRow * newCol);

    // set the new label of the row
    int *rowEncode = (int *)malloc(sizeof(int) * newRow);
    memset(rowEncode, 0, sizeof(int) * newRow);
    // for row, n outer loop, m inner loop
    int indexCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int rowTemp = intConcatenate(j, i);
            rowEncode[indexCount] = rowTemp;
            indexCount++;
        }
    }
    // set the new label of the col
    int *colEncode = (int *)malloc(sizeof(int) * newCol);
    memset(colEncode, 0, sizeof(int) * newCol);
    indexCount = 0;
    // for col, m outer loop, n inner loop
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int colTemp = intConcatenate(i, j);
            colEncode[indexCount] = colTemp;
            indexCount++;
        }
    }

    for (int i = 0; i < newRow; i++) {
        for (int j = 0; j < newCol; j++) {
            if (rowEncode[i] == colEncode[j]) {
                res_i[i * newCol + j] = 1;
            }
        }
    }

    for (int i = 0; i < newRow * newCol; i++) {
        pushArray(&res->m, &res_i[i]);
    }
    free(rowEncode);
    free(colEncode);
    return res;
}