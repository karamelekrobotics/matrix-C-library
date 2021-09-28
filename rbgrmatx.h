/*
 * Robotics and Vision Technologies R&D Commerce Co.
 * Author:  Berkan Onder Karamelek
 * Purpose: Robogor Matrix Operations Lib.
 * Language: C
 * Last Update: 28.09.2021
 */

#ifndef _RBGR_MATX_H_
#define _RBGR_MATX_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int rsize;
    int csize;
    double** values;
}MatX;

/**
*@brief MatX_CreateEmptyMat
*@param MatX
*@param uint8_t
*@param uint8_t
*@retval NONE
*/
void MatX_CreateEmptyMat(MatX *mat, int r, int c);

/**
*@brief MatX_CreateMat
*@param MatX
*@param uint8_t
*@param uint8_t
*@param double**
*@retval NONE
*/
void MatX_CreateMat(MatX *mat, int r, int c, double source[r][c]);

/**
*@brief MatX_FreeMem
*@param MatX
*@retval NONE
*/
void MatX_FreeMem(MatX *mat);

/**
*@brief MatX_Copy2d
*@param MatX
*@param MatX
*@retval NONE
*/
void MatX_Copy2d(MatX *source, MatX *dest);

/**
*@brief MatX_Clear
*@param MatX
*@retval uint8_t
*/
int MatX_Clear(MatX* mat);

/**
*@brief MatX_Multiply
*@param MatX
*@param MatX
*@param MatX
*@retval uint8_t
*/
int MatX_Multiply(MatX* mat1, MatX* mat2, MatX* multip);

/**
*@brief MatX_Sum
*@param MatX
*@param MatX
*@param MatX
*@retval uint8_t
*/
int MatX_Sum(MatX* mat1, MatX* mat2, MatX* sum);

/**
*@brief MatX_Subs
*@param MatX
*@param MatX
*@param MatX
*@retval uint8_t
*/
int MatX_Subs(MatX* mat1, MatX* mat2, MatX* sum);

/**
*@brief MatX_ArgMax
*@param MatX
*@retval double
*/
double MatX_ArgMax(MatX* mat);

/**
*@brief MatX_ArgMin
*@param MatX
*@retval double
*/
double MatX_ArgMin(MatX* mat);

/**
*@brief MatX_reLU
*@param MatX
*@retval None
*/
void MatX_reLU(MatX* mat);

/**
*@brief MatX_Print
*@param MatX
*@retval NONE
*/
void MatX_Print(MatX* mat);
  
#endif
