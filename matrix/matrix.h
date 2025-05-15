#include "array.h"

typedef struct matrix_ matrix;
struct matrix_
{
    int dim;
    int row;
    int col;
    ziArray m;
};
/******** matrix.c **********/
int initMatrix(matrix* mI);
int initMatrixAttri(matrix *mI, int dim, int row, int col);
int clearMatrix(matrix *mI);
int readMatrix(matrix* mI, char * mS);
int fetchMatrixRow(matrix* mI, int rowIndex, ziArray* rowArray);
int fetchMatrixCol(matrix* mI, int colIndex, ziArray* colArray);
int* getMatrixItemIndex(matrix* mI, int rowIndex, int colIndex);
matrix* createIdentityMatrix(int n);
int isIdentityMatrix(matrix *m0);
int showDigitsMatrix(matrix* m0);
/******** matrixCal.c **********/
matrix* addMatrix(matrix* m0, matrix* m1);
matrix* productMatrix(matrix* m0, matrix* m1);
matrix* nTimesMatrixOutplace(matrix* m0, int n);
matrix* concatMatrixLROutPlace(matrix* m0, matrix* m1);
matrix* concatMatrixUDOutPlace(matrix* m0, matrix* m1);
matrix* kProductMatrix(matrix* m0, matrix* m1);
matrix* stpMatrix(matrix* m0, matrix* m1);
matrix* notMatrix();
matrix* eqMatrix();
matrix* andNMatrix(int n);
matrix* orNMatrix(int n);
matrix* tMatrix(matrix* m);
matrix* stpTwoTMatrix(matrix* m0, matrix* m1);
matrix* swapMatrix(int m, int n);
int checkIdentityMatrix(matrix* m0, matrix* m1);

#define MatrixForEachItem( m, i, j ) \
    for( i = 0; i < m->row; i++)        \
        for( j = 0; j < m->col; j++)

#define MatrixForEachItemColRow( m, i, j ) \
    for( i = 0; i < m->col; i++)        \
        for( j = 0; j < m->row; j++)
