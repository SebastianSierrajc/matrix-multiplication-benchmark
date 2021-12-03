#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "matrixUtils/matrixUtils.h"
#include "benchmarkUtils/timeUtils.h"

// Reserva de memoria
#define SIZE_DATA (1024*1024*64*3) 
static double MEM_CHUNK[SIZE_DATA];

// Version 5. version del algoritmo filas por filas.


int main(int argc, char **argv){

    int N = (int) atoi(argv[1]); // matrix size NxN
    int NUM_T = (int) atoi(argv[2]); //number of threads

//#pragma omp parallel 
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
    
    /* 
    matrixT(N, N, matrixB, matrixC);
    printf("Matrix BT: \n");
    matrixPrint(N, N, matrixC);
    */
    
    omp_set_num_threads(NUM_T);
    sampleStart();


    // Test matrix multiplication with OpenMP
#pragma omp parallel for
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            double *ptra, *ptrb, s=0.0;
            ptra = matrixA + (i*N);
            ptrb = matrixB + (j*N);
            for(int k=0; k<N; k++, ptra++, ptrb++)
                s += (*ptra * *ptrb);
            matrixC[j+i*N] = s;
        }   
    }

    sampleStop();

    // printf("Matrix C: \n");
    // matrixPrint(N, N, matrixC);

    printTime();

   return 0;
}
