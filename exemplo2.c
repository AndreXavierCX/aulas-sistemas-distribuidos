#include <omp.h>
#include <stdio.h>
#define posicoes 10

int main(int argc, char *argv[])
{
    float a[posicoes] = {12, 15, 43, 43, 54, 21, 67, 13, 78, 34};
    float b[posicoes] = {34, 35, 67, 86, 23, 54, 65, 76, 11, 14};
    float c;

    int i, aux;

#pragma omp parallel
    {
        // #pragma omp for
        /*for (i = 0; i < posicoes; i++)
        {
            a[i] = 2;
            b[i] = 3;
        }*/

#pragma omp for
        for (i = 0; i < posicoes; i++)
        {
            c += a[i] * b[i];
        }

        aux +=c; 
        // #pragma omp for ordered
        // for (i = 0; i < 10; i++)
        //{
        // #pragma omp ordered
        //  printf("C[%d]=%f \n",i,c[i]);
        // printf("thread %d interação %d do loop valor C[%d]=%f \n", omp_get_thread_num(), i, i, c[i]);
        // }
    }
    return 0;
}