#include <stdio.h>

typedef int bool;
#define false 0
#define true  1


int main()
{
    int num,i;
    bool isprime=true;

    scanf("%d", &num);
    for(i=2; i<num; i++)
    {
        if(num % i == 0)
        {
            isprime=false;
            break;
        }
    }
    if(isprime)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
