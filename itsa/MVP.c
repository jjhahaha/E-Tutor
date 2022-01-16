#include <stdio.h>
#include <string.h>
int main()
{
    int a,b,c,d,e;
    int MVP;
    scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);

    MVP=a+2*b+2*c+2*d-2*e;

    if(MVP>=45)printf("A\n");
    else if(35<=MVP && MVP<=44)printf("B\n");
    else if(25<=MVP && MVP<=34)printf("C\n");
    else if(MVP<25)printf("D\n");


}
