#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrixUtils/matrixUtils.h"
#include "benchmarkUtils/timeUtils.h"

// Reserva de memoria
#define SIZE_DATA (1024*1024*64*3) 
static double MEM_CHUNK[SIZE_DATA];

// Estrategia declaracion de las variables a nivel global
int N, NUM_T;
double *a, *b, *c; // matrices

void *matrixMulT(void *arg){

    int i, j, k; // iteradores
    int idThreads; // identificador de hilo
    int portion; // Porcion de la matrix b;
    int startRow, endRow; // inicio y fin de la porcion de la matriz A

    idThreads = *((int *) arg); // se obtiene el dietificador del hilo
    portion   = N / NUM_T;
    startRow  = idThreads * portion;
    endRow    = (idThreads + 1) * portion;
    
    for(i=startRow; i<endRow; i++){
        for(j=0; j<N; j++){
            double *ptra, *ptrb, add =0.0;
            ptra = a+(i*N);
            ptrb = b+j;
            for(k=0; k<N; k++, ptra++, ptrb++)
                add += (*ptra * *ptrb);
            c[j+i*N] = add;
        }
    }

    return 0;
}

int main(int argc, char **argv){
    int countThreads; // contador general de hilos
    pthread_t *threads; // delcarando apuntadores a hilos (posix)

    N = (int) atoi(argv[1]);
    NUM_T = (int) atoi(argv[2]);

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

    // declaracion de hilos
    threads = (pthread_t *) malloc(NUM_T * sizeof(pthread_t));
    // se reparte el trabajo invocando cada hilo
    for(countThreads=0; countThreads<NUM_T; countThreads++){
        int *tId; // punteor identificador del hilo
        tId = (int *) malloc(sizeof(int));
        *tId = countThreads; 
        pthread_create(&threads[countThreads], NULL, matrixMulT, (void *) tId);
    }

    // espera a que todos los hilos terminen (sincronizacion)
    for(countThreads=0; countThreads<NUM_T; countThreads++){
        pthread_join(threads[countThreads], NULL);
    }

    sampleStop();
    printTime();

    /*matrixPrint(N, N, c);*/

    return 0;
}

