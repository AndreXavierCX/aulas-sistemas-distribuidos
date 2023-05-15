#include <stdio.h>

#define N 1000

int main()
{
    int A[N][N], B[N][N], C[N][N];
    int i, j, k;

#pragma omp parallel private(i, j, k) 
    // inicializa as matrizes A e B
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    // multiplica as matrizes A e B
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // imprime a matriz resultante C
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }


    return 0;
}

/* exemplo de código em C que realiza a multiplicação
de duas matrizes de tamanho 1000x1000. Este algoritmo
 envolve três loops aninhados que executam um total
de 1 bilhão de operações*/