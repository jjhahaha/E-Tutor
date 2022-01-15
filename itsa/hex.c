#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num;
    while( scanf("%d",&num)!=EOF )
    {
        printf("%X\n",num);
    }
    return 0;
}
