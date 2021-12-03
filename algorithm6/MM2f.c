#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "matrixUtils/matrixUtils.h"
#include "benchmarkUtils/timeUtils.h"

// Reserva de memoria
#define SIZE_DATA (1024*1024*64*3) 
static double MEM_CHUNK[SIZE_DATA];


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
    // matrixT(N, N, matrixB, matrixC);
    // printf("Matrix BT: \n");
    // matrixPrint(N, N, matrixC);

    omp_set_num_threads(NUM_T);
    sampleStart();


    // Test matrix multiplication with OpenMP
#pragma omp parallel for
    for(i=0; i<N; i+=2){
        for(j=0; j<N; j+=2){
            double *ptra, *ptrb;
            double c0, c1, c2, c3;
            c0 = c1 = c2 = c3 = 0.0;
            ptra = matrixA + (i*N);
            ptrb = matrixB + (j*N);

            for(k=N; k>=0; k-=2, ptra+=2, ptrb+=2){
                double a0, a1, a2, a3;
                double b0, b1, b2, b3;
                a0 = *ptra; a1 = *(ptra + 1); a2 = *(ptra + 2); a3 = *(ptra + 3);
                b0 = *ptrb; b1 = *(ptrb + 1); b2 = *(ptrb + 2); b3 = *(ptrb + 3);
                c0 += a0 * b0 + a1 * b1;
                c1 += a0 * b2 + a1 * b3;
                c2 += a2 * b0 + a3 * b1;
                c3 += a2 * b2 + a3 * b3;
            }

            ptrb = matrixC + i*N+j;
            *ptrb = c0;
            *(ptrb + 1) = c1;
            *(ptrb + N) = c2;
            *(ptrb + N + 1) = c3;
        }   
    }

    sampleStop();

    // printf("Matrix C: \n");
    // matrixPrint(N, N, matrixC);

    printTime();

   return 0;
}
