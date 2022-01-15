#include<stdio.h>
#include<stdlib.h>

int main()
{
    int ncase, N;

    scanf("%d", &N);
    N = N / 3;
    N=N * (N + 1) * 3 / 2;//Multiplier of 3 by trapezoidal area formula
    printf("%d\n", N);


}
