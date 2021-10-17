#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "matrixUtils/matrixUtils.h"
#include "benchmarkUtils/timeUtils.h"

// Reserva de memoria
#define SIZE_DATA (1024*1024*64*3) 
static double MEM_CHUNK[SIZE_DATA];

// Version 6. version del algoritmo  2 filas por 2 filas.


int main(int argc, char **argv){

    int N = (int) atoi(argv[1]); // matrix size NxN
    int NUM_T = (int) atoi(argv[2]); //number of threads

//#pragma omp parallel 
    int i, j, k;
    double *matrixA, *matrixB, *matrixC;
    matrixA = MEM_CHUNK;
    matrixB = matrixA + (N * N);
    matrixC = matrixB + (N * N);

    // The main process make the init routines
//#pragma omp master

    matrixInitN(N, matrixA, matrixB, matrixC);
 

    // printf("Matrix A: \n");
    // matrixPrint(N, N, matrixA);
    // printf("Matrix B: \n");
    // matrixPrint(N, N, matrixB);

    omp_set_num_threads(NUM_T);
    sampleStart();


    // Test matrix multiplication with OpenMP
#pragma omp parallel for
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            double *ptra, *ptrb;
            double c0, c1, c2, c3;
            c0 = c1 = c2 =c3 = 0.0;

            ptra = matrixA + (i*N);
            ptrb = matrixB + (j*N);
            k = N;
            while(k&3){
                c0 += (*ptra * *ptrb);
                k--;
                ptra++, ptrb++;
            }

            for(; k>0; k-=4, ptra+=4, ptrb+=4){
                c0 += (*ptra * *ptrb);
                c1 += *(ptra+1) * *(ptrb+1);
                c2 += *(ptra+2) * *(ptrb+2);
                c3 += *(ptra+3) * *(ptrb+3);
            }
            matrixC[j+i*N] = c0 + c1 + c2 + c3;
        }   
    }

    sampleStop();

    // printf("Matrix C: \n");
    // matrixPrint(N, N, matrixC);

    printTime();

   return 0;
}
