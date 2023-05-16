#include <omp.h>
#include <stdio.h>
#define posicoes 4

int main(int argc, char *argv[])
{
    float a[posicoes] = {2, 4, 6, 8};
    float b[posicoes] = {1, 2, 3, 4};
    float c, aux;

    int i;

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

        #pragma omp atomic
        aux += c;
        printf("Resultado %f \n", aux);
        
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