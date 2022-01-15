#include <stdio.h>

int main()
{
    int i=0,max=-1e16;
    int arr[6];

    for(i=0; i<6; i++)
        scanf("%d",&arr[i]);
    for(i=0; i<6; i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    printf("%d\n",max);

}
