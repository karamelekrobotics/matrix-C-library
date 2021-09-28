/*
 * Robotics and Vision Technologies R&D Commerce Co.
 * Author:  Berkan Onder Karamelek
 * Purpose: Robogor Matrix Operations Lib.
 * Language: C
 * Last Update: 28.09.2021
 */

#include "rbgrmatx.h"

/**
*@brief MatX_CreateEmptyMat
*@param MatX
*@param uint8_t
*@param uint8_t
*@retval NONE
*/
void MatX_CreateEmptyMat(MatX *mat, int r, int c)
{
    int i = 0, j = 0;
    mat->rsize = r; 
    mat->csize = c;
    mat->values = (double**)malloc(r * sizeof(double*));
    for (i = 0; i < r; i++)
        mat->values[i] = (double*)malloc(c * sizeof(double));
    
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            mat->values[i][j] = 0;
}

/**
*@brief MatX_CreateMat
*@param MatX
*@param uint8_t
*@param uint8_t
*@param double**
*@retval NONE
*/
void MatX_CreateMat(MatX *mat, int r, int c, double source[r][c])
{
    int i = 0, j = 0;
    mat->rsize = r;
    mat->csize = c;
    mat->values = (double**)malloc(r * sizeof(double*));
    for (i = 0; i < mat->rsize; i++)
        mat->values[i] = (double*)malloc(c * sizeof(double));
    
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            mat->values[i][j] = source[i][j];
}

/**
*@brief MatX_FreeMem
*@param MatX
*@retval NONE
*/
void MatX_FreeMem(MatX *mat)
{
    int n = mat->rsize;
    while(n) free(mat->values[--n]);
    free(mat->values);
}

/**
*@brief MatX_Copy2d
*@param MatX
*@param MatX
*@retval NONE
*/
void MatX_Copy2d(MatX *source, MatX *dest)
{
    int i, j;
    for (i = 0; i < dest->rsize; i++) {
        for (j = 0; j < dest->csize; j++) {
            dest->values[i][j] = source->values[i][j];
        }
    }
}

/**
*@brief MatX_Clear
*@param MatX
*@retval uint8_t
*/
int MatX_Clear(MatX* mat)
{
    int i, j;
    if ((mat->rsize != 0) && (mat->csize)) { 
        for (i = 0; i < mat->rsize; i++) {
            for (j = 0; j < mat->csize; j++) {
                mat->values[i][j] = 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

/**
*@brief MatX_Multiply
*@param MatX
*@param MatX
*@param MatX
*@retval uint8_t
*/
int MatX_Multiply(MatX* mat1, MatX* mat2, MatX* multip)
{
    int i = 0, j = 0, k = 0;
    if (mat1->csize != mat2->rsize) {
        return 0;
    } else {
        multip->rsize = mat1->rsize;
        multip->csize = mat2->csize;
        for (i = 0; i < multip->rsize; i++) {
            for (j = 0; j < multip->csize; j++) {
                for (k = 0; k < mat2->rsize; k++) {
                    multip->values[i][j] += mat1->values[i][k] * mat2->values[k][j];
                }
            }
        }
        return 1;
    }
}

/**
*@brief MatX_Sum
*@param MatX
*@param MatX
*@param MatX
*@retval uint8_t
*/
int MatX_Sum(MatX* mat1, MatX* mat2, MatX* sum)
{
    int i = 0, j = 0;
    if ((mat1->rsize != mat2->rsize) && (mat1->csize != mat2->csize)) {
        return 0;
    } else{
        for (i = 0; i < mat1->rsize; i++) {
            for (j = 0; j < mat1->csize; j++) {
                sum->values[i][j] = mat1->values[i][j] + mat2->values[i][j];
            }
        }
        return 1;
    }
}

/**
*@brief MatX_Subs
*@param MatX
*@param MatX
*@param MatX
*@retval uint8_t
*/
int MatX_Subs(MatX* mat1, MatX* mat2, MatX* sum)
{
    int i = 0, j = 0;
    if ((mat1->rsize != mat2->rsize) && (mat1->csize != mat2->csize)) {
        return 0;
    } else{
        for (i = 0; i < mat1->rsize; i++) {
            for (j = 0; j < mat1->csize; j++) {
                sum->values[i][j] = mat1->values[i][j] - mat2->values[i][j];
            }
        }
        return 1;
    }
}

/**
*@brief MatX_Subs
*@param MatX
*@param MatX
*@param MatX
*@retval uint8_t
*/
double MatX_ArgMax(MatX* mat)
{
    int i, j;
    double max;
    for (i = 0; i < (mat->rsize-1); i++) {
        for (j = 0; j < (mat->csize-1); j++) {
            if (mat->values[i][j] > mat->values[i+1][j+1]) {
                max = mat->values[i][j];
            } else {
                max = mat->values[i+1][j+1];
            }
        }
    }
    return max;
}

/**
*@brief MatX_ArgMin
*@param MatX
*@retval double
*/
double MatX_ArgMin(MatX* mat)
{
    int i, j;
    double min;
    for (i = 0; i < (mat->rsize-1); i++) {
        for (j = 0; j < (mat->csize-1); j++) {
            if (mat->values[i][j] > mat->values[i+1][j+1]) {
                min = mat->values[i+1][j+1];
            } else {
                min = mat->values[i][j];
            }
        }
    }
    return min;
}

/**
*@brief MatX_reLU
*@param MatX
*@retval None
*/
void MatX_reLU(MatX* mat)
{
    int i, j;
    for (i = 0; i < mat->rsize; i++) {
        for (j = 0; j < mat->csize; j++) {
            if (mat->values[i][j] < 0) {
                mat->values[i][j] = 0;
            } else {
                // do nothing
                ;
            }
        }
        
    }
    
}

/**
*@brief MatX_Print
*@param MatX
*@retval NONE
*/
void MatX_Print(MatX* mat)
{
    int i, j;
    for (i = 0; i < mat->rsize; i++) {
        for (j = 0; j < mat->csize; j++) {
            printf("%f ",mat->values[i][j]);
        }
        printf("\n");
    }
}