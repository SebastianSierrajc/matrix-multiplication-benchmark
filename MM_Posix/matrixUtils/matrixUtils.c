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

void matrixMulN(int N, double *a, double *b, double *r){
    int i, j, k;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            double *ptra, *ptrb, s=0.0;
            ptra = a + (i*N);
            ptrb = b + j;
            for(k=0; k<N; k++, ptra++, ptrb+=N)
                s += (*ptra * *ptrb);
            r[j+i*N] = s;
        }
    }
}

void matrixT(int m, int n, double *a, double *r){
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            r[j+i*m] = a[j+i*m];
}

void matrixPrint(int m, int n, double *a){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++)
            printf("\t%lf", a[j+i*m]);
        printf("\n");
    }
}

void matrixFill(int m, int n, double *a){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++)
            scanf("%lf", &a[j+i*m]);
    }
}

void matrixInit(int m, int n, double *a){
   int i, j;
   for(i=0; i<m; i++){
       for(j=0; j<n; j++){
           a[j+i*m] = 2 * (j-i);
       }
   }
}

void matrixInitN(int N, double *a, double *b, double *c){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            a[j+i*N] = 2.0 * (i+j);
            b[j+i*N] = 3.2 * (i+j);
            c[j+i*N] = 1.0;
        }
    }
}

