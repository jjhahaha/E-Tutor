#include<stdio.h>
#include<stdlib.h>

int main()
{

    int weight,gender=0;
    double c=0;

    while(scanf("%d%d",&weight,&gender)!=EOF)
    {
        if(gender==1)
        {
            c=(weight-80)*0.7;
            printf("%.1lf\n",c);
        }
        else if(gender==2)
        {
            c=(weight-70)*0.6;
            printf("%.1lf\n",c);
        }
    }

    return 0;

}
