#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, ncase;
    double num[10];
    double mmax=-1e16, mmin=1e16;

    //scanf("%d", &ncase);

    for( i = 0; i < 10; i++)
    {
        scanf("%lf", &num[i]);

        if(num[i] > mmax)
            mmax = num[i];

        if(num[i] < mmin)
            mmin = num[i];

    }
    printf("maximum:%.2f\n",mmax );
    printf("minimum:%.2f\n",mmin );


    return 0;
}
