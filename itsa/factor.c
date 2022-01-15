#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num,i;
    scanf("%d", &num);
    for(i=1; i<=num; i++)
    {
        if(num%i==0)
        {
            if(i==1)
                printf("%d", i);
            else
                printf(" %d", i);
        }
    }
    printf("\n");

}
