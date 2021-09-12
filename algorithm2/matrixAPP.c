#include <stdio.h>
#include <stdlib.h>
#include "matrixUtils/matrixUtils.h"
#include "benchmarkUtils/timeUtils.h"

// Reserva de memoria
#define SIZE_DATA (1024*1024*64*3) 
static double MEM_CHUNK[SIZE_DATA];

int main(int argc, char **argv){
    int N = (int) atoi(argv[1]);
    double *a;
    double *b;
    double *c;

    a = MEM_CHUNK;
    b = a + (N * N);
    c = b + (N * N);
    
    matrixInitN(N, a, b,c); 
    
    /*matrixPrint(N, N, a);
    printf("\n");
    matrixPrint(N, N, b);
    printf("\n");
    matrixPrint(N, N, c);*/
    
    sampleStart();
    matrixMulN(N, a, b, c);
    sampleStop();
    printTime();

    /*matrixPrint(N, N, c);*/

    return 0;
}

