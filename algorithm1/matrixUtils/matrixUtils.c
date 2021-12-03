#include <stdio.h>
#include "matrixUtils.h"

void matrixAdd(int m, int n, int a[m][n], int b[m][n], int r[m][n]){
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            r[i][j] = a[i][j] + b[i][j];
}

void matrixSub(int m, int n, int a[m][n], int b[m][n], int r[m][n]){
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            r[i][j] = a[i][j] - b[i][j]; 
}

void matrixMul(int m, int n, int p, int a[m][n], int b[n][p], int r[m][p]){
    int i, j, k;
    for(i=0; i<m; i++){
        for(j=0; j<p; j++){
            r[i][j] = 0;
            for(k=0; k<n; k++)
                r[i][j] += a[i][k] * b[k][j];
        }
    }
}

void matrixMulN(int N, int a[N][N], int b[N][N], int r[N][N]){
    int i, j, k;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            r[i][j] = 0;
            for(k=0; k<N; k++)
                r[i][j] += a[i][k] * b[k][j];
        }
    }
}

void matrixT(int m, int n, int a[m][n], int r[n][m]){
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            r[j][i] = a[i][j];
}

void matrixPrint(int m, int n, int a[m][n]){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++)
            printf("\t%d", a[i][j]);
        printf("\n");
    }
}

void matrixFill(int m, int n, int a[m][n]){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
    }
}

void matrixInit(int m, int n, int a[m][n]){
   int i, j;
   for(i=0; i<m; i++){
       for(j=0; j<n; j++){
           a[i][j] = 2 * (j-i);
       }
   }
}

void matrixInitN(int N, int a[N][N]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            a[i][j] = 2 * (j-i);
        }
    }
}

