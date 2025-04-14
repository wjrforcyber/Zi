#include "array.h"

typedef struct matrix_ matrix;
struct matrix_
{
    int dim;
    int row;
    int col;
    ziArray m;
};


int readMatrix(matrix* mI, char * mS);
int fetchMatrixRow(matrix* mI, int rowIndex, ziArray* rowArray);
int fetchMatrixCol(matrix* mI, int colIndex, ziArray* colArray);