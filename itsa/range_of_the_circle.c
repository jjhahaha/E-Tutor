#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    int range=10000;
    scanf("%d %d",&a,&b);
    double area;
    area=(a*a)+(b*b);
    if(area<range)
        printf("inside\n");
    else
        printf("outside\n");

}
