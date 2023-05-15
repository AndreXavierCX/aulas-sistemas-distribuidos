#include <omp.h>
#include <stdio.h>
#define posicoes 2048

int main(int argc, char *argv[])
{
    float a[posicoes];
    float b[posicoes];
    float c[posicoes];

    int i;

#pragma omp parallel
    {
//#pragma omp for
        for (i = 0; i < posicoes; i++)
        {
            a[i] = 2;
            b[i] = 3;
        }

//#pragma omp for
        for (i = 0; i < posicoes; i++)
        {
            c[i] = a[i] + b[i];
        }

#pragma omp for ordered
        for (i = 0; i < 10; i++)
        {
            #pragma omp ordered
            // printf("C[%d]=%f \n",i,c[i]);
            printf("thread %d interação %d do loop valor C[%d]=%f \n", omp_get_thread_num(), i, i, c[i]);
        }
    }
    return 0;
}