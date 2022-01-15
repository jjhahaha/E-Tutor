#include<stdio.h>
#include<stdlib.h>

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
    {
        double Ti,T;
        char d;
        int i;
        scanf("%lf,%d",&Ti,&i);//input : 94.87,9
        //T i = T i-1 + 2.71828 * i
        T = Ti + 2.71828 * (1 + i) * i / 2 ;
        printf("%.4lf\n",T);
    }
}
