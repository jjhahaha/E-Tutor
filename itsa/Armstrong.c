#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    //double a;
    int num, Target, result=0,a;

    scanf("%d", &num);

    Target = num;

    while (Target!= 0)
    {
        a = Target%10;
        //printf("%d\n",a);
        //result+=pow(a,3);
        result+=a*a*a;
        //printf("%d\n",result);
        Target/= 10;
    }

    if(result == num)
        printf("Yes\n");
    else
        printf("No\n");

}
