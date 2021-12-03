#include <stdio.h>
#include <stdlib.h>
#include "matrixUtils/matrixUtils.h"
#include "benchmarkUtils/timeUtils.h"

int main(int argc, char **argv){
    // declaracion de variables
    int N = (int) atoi(argv[1]);
    int a[N][N];
    int b[N][N];
    int c[N][N];

    // inicializacion de matrices
    matrixInitN(N, a);
    matrixInitN(N, b);
    
    // inicio toma de tiempo
    sampleStart();
    matrixMulN(N, a, b, c);
    sampleStop();
    // fin toma de tiempo

    printTime();

    return 0;
}

