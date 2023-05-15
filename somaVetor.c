#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    float a[2048];
    float b[2048];
    float c[2048];

    int i;

#pragma omp parallel
#pragma omp for
    for (i = 0; i < 2048; i++)
    {
        a[i] = 2;
        b[i] = 3;
    }

#pragma omp for
    for (i = 0; i < 2048; i++)
    {
        c[i] = a[i] + b[i];
    }

#pragma omp for
    for (i = 0; i < 2048; i++)
    {
        printf("C[%d]=%f \n", i, c[i]);
    }
    return 0;
}