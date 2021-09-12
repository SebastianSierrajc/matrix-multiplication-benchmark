#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* Prototypes for the functions */

/*
 * Function: matrixSum
 * Use matrixAdd(m, n, a, b, r)
 * ----------------------------
 * Calculate the addition of two matrices of size mxn.
 * the result of the addition is saved in matrix r of size mxn in-place.
*/
void matrixAdd(int m, int n, int a[m][n], int b[m][n], int r[m][n]);

/*
 * Function: matrixSub
 * Use matrixSub(m, n, a, b, r)
 * ----------------------------
 * Calculate the subtraction of two matrices of size mxn.
 * the result of the subtraction is saved in matrix r of size mxn in-place.
*/
void matrixSub(int m, int n, int a[m][n], int b[m][n], int r[m][n]);

/*
 * Function: matrixMul
 * Use matrixMul(m, n, p, a, b, r)
 * ----------------------------
 * Calculate the multiplication of two matrices of sizes mxn and nxp respectively.
 * the result of the multiplication is saved in matrix r of size mxn in-place.
*/
void matrixMul(int m, int n, int p, int a[m][n], int b[n][p], int r[m][p]);

/*
 * Function: matrixMul
 * Use matrixMulN(m, n, p, a, b, r)
 * ----------------------------
 * Calculate the multiplication of two matrices of sizes nxn respectively.
 * the result of the multiplication is saved in matrix r of size nxn in-place.
*/
void matrixMulN(int N, int a[N][N], int b[N][N], int r[N][N]);

/*
 * Function: matrixT
 * Use matrixT(m, n, a, r)
 * ----------------------------
 * Calculate the transpose of matrix a, of size mxn.
 * the result of the transposition is saved in matrix r, of size nxm, in-place.
*/
void matrixT(int m, int n, int a[m][n], int r[n][m]);

/*
 * Function: matrixPrint
 * Use matrixPrint(m, n, a)
 * ----------------------------
 * Print the matrix a in standard output
*/
void matrixPrint(int m, int n, int a[m][n]);

/*
 * Function: matrixFill
 * Use matrixFill(m, n, a)
 * ----------------------------
 * Fill the matrix a with data from standard input
*/
void matrixFill(int m, int n, int a[m][n]);


/*
 * Function: Init
 * Use matrixInit(m, n, a)
 * ----------------------------
 * Init the values of a matrix of size mxn
*/
void matrixInit(int m, int n, int a[m][n]);

/*
 * Function: Init
 * Use matrixInitN(m, n, a)
 * ----------------------------
 * Init the values of a matrix of size nxn
*/
void matrixInitN(int N, int a[N][N]);

#endif

