#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int a,ans=1,i;
    scanf("%d", &a);

    //ans=pow(2,a);
    for(i=1; i<=a; i++)ans=2*ans;
    if(a<=31)printf("%d\n",ans);
    else printf("Value of more than 31\n");

}
