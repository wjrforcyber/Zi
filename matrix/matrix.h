#include "array.h"

typedef struct matrix_ matrix;
struct matrix_
{
    int dim;
    int row;
    int col;
    ziArray m;
};

int initMatrix(matrix* mI);
int initMatrixAttri(matrix *mI, int dim, int row, int col);
int readMatrix(matrix* mI, char * mS);
int fetchMatrixRow(matrix* mI, int rowIndex, ziArray* rowArray);
int fetchMatrixCol(matrix* mI, int colIndex, ziArray* colArray);
matrix* addMatrix(matrix* m0, matrix* m1);
matrix* productMatrix(matrix* m0, matrix* m1);

#define MatrixForEachItem( m, i, j ) \
    for( i = 0; i < m->row; i++)        \
        for( j = 0; j < m->col; j++)    \
