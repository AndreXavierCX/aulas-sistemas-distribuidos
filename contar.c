#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int i;
    printf("Vamos contar de 1 a 4\n");

#pragma omp parallel private(i)
    for (int i = 1; i <= 4; i++)
    {
        printf("%d\n", i);
    }
}