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