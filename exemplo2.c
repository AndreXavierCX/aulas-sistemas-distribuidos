#include <omp.h>
#include <stdio.h>
#define posicoes 4

int main(int argc, char *argv[])
{
    float a[posicoes] = {2, 4, 6, 8};
    float b[posicoes] = {1, 2, 3, 4};
    float c, aux;

    int i;

#pragma omp parallel shared(aux)
    {
        #pragma omp for
        for (i = 0; i < posicoes; i++)
        {
            #pragma omp atomic
            c += a[i] * b[i];
            printf("thread %d interação %d do loop valor C[%d]=%f \n", omp_get_thread_num(), i, i, c);
        }

        
        aux = c;
        
        // #pragma omp ordered
        //  printf("C[%d]=%f \n",i,c[i]);
        // printf("thread %d interação %d do loop valor C[%d]=%f \n", omp_get_thread_num(), i, i, c[i]);
        // }
    }

    printf("Resultado %f \n", aux);

    return 0;
}