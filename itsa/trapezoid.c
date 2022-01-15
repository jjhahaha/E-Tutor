#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main()
{
    int a;
    double dist,b;
    scanf("%d", &a);
    b=a*100;
    dist=ceil(b/(100-30*2.54));
    printf("%.lf\n",dist);

}
