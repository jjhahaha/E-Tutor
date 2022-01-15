#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,c,d,total;
    while(scanf("%d%d", &a,&b)!=EOF)
    {
        c=a * (a + 1) / 2;
        d=b * (b + 1) / 2;
        if(c>d)total=c-d+b;
        else total=d-c+a;

        printf("%d\n",total);
    }


}
