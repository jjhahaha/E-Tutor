#include <stdio.h>
#include <string.h>
int main()
{
    long long a,i,ans=1;
    scanf("%lld", &a);

    for(i=1; i<=a; i++)
    {
        ans=ans*i;
        //printf("%d\n", ans);
    }
    printf("%lld\n", ans);
}
