#include "matrix.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//read from string
/*
Predefined matrix format as
[1,2,3], which is one dimension, a vector;
[[1,2,3,4],[5,6,7,8]], which is two dimension;
[[[1,2],[3,4]],[[5,6],[7,8]]], which is three dimension.
*/

int initMatrix(matrix* mI)
{
    mI->dim = 0;
    mI->row = 0;
    mI->col = 0;
    if(initArray(&mI->m, 8) != 0)
    {
        printf("Initialization of matrix failed.\n");
        return 1;
    }
    return 0;
}

int initMatrixAttri(matrix *mI, int dim, int row, int col)
{
    mI->dim = dim;
    mI->row = row;
    mI->col = col;
    if(initArray(&mI->m, row * col / INCREASE_RATE) != 0)
    {
        printf("Initialization of matix with attributes failed.\n");
        return 1;
    }
    return 0;
}

//clear matrix
int clearMatrix(matrix* m)
{
    if(clearArray(&m->m) != 0)
    {
        printf("Failed to clear matrix array.\n");
        return 1;
    }
    return 0;
}

//Not a good one
int readMatrix(matrix* mI, char* mS)
{
    initMatrix(mI);
    //index indicates wheather it is a digit
    char* ptr = mS;
    char* ptr_r;
    char* preC;
    int endFlag = 0;
    //int sArray[100];
    int *sArray = (int *)malloc(sizeof(int) * 100);
    int index = 0;
    int dimFlag = 0;
    int colFlag = 0;

    while(endFlag == 0)
    {
        while(isdigit(*ptr) == 0)
        {
            //check if it is the [ in the begining
            if(*ptr == '[' && dimFlag == 0)
            {
                mI->dim++;
            }
            //record the previous char when it is [
            if(*ptr == '[')
            {
                preC = ptr;
            }
            if(*ptr == ',' && colFlag == 0)
            {
                mI->col++;
            }
            if(*ptr == ']' && colFlag == 0)
            {
                mI->col++;
                colFlag = 1;
            }
            ptr++;
            if(*ptr != '\0')
            {
                continue;
            }
            endFlag = 1;
            break;
        }
        if(endFlag == 1)
        {
            break;
        }
        //no longer update the dim when the first time meets a digit
        dimFlag = 1;
        //tmp save the current number
        char buf[10] = {0};
        ptr_r = ptr;
        while(isdigit(*ptr_r) != 0)
        {
            ptr_r++;
        }
        strncpy(buf, ptr, ptr_r - ptr);
        int num = atoi(buf);
        sArray[index] = num;
        index++;
        //check if the preC is [
        if(*preC == '[')
        {
            mI->row++;
        }
        preC = ptr_r;
        ptr = ptr_r;
    }
    for(int i = 0 ; i < index; i ++)
    {
        printf("sArray %d is %d \n", i, sArray[i]);
    }
    for(int i = 0; i < index; i++)
    {
        pushArray(&mI->m, &sArray[i]);
    }
    showDigitsArray(&mI->m);
    return 0;
}

//fetch the row with the index
int fetchMatrixRow(matrix* mI, int rowIndex, ziArray* rowArray)
{
    if(rowIndex > mI->row - 1)
    {
        printf("Row index exceeded.\n");
    }
    for(int i = 0; i < mI->col; i++)
    {
        pushArray(rowArray, fetchIndexArray(&mI->m, rowIndex * mI->col + i));
    }
    return 0;
}

//fetch the matrix column
int fetchMatrixCol(matrix* mI, int colIndex, ziArray* colArray)
{
    if(colIndex > mI->col - 1)
    {
        printf("Column index exceeded.\n");
    }
    for(int i = 0 ; i < mI->row; i++)
    {
        pushArray(colArray, fetchIndexArray(&mI->m, i * mI->col + colIndex));
    }
    return 0;
}

//get the int item in specific index
int* getMatrixIntItemIndex(matrix* mI, int rowIndex, int colIndex)
{
    if(rowIndex > mI->row || colIndex > mI->col)
    {
        printf("Index of row or col is exceeded.\n");
        return NULL;
    }
    return fetchIndexArray(&mI->m, rowIndex * mI->col + colIndex);
}