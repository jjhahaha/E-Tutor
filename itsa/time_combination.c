#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int total, day, hour, min, sec;
    scanf("%d",&total);
    day = floor(total / 86400);
    hour = floor((total % 86400)/3600);
    min = floor((total % 86400 % 3600)/60);
    sec = total % 86400 % 3600 % 60;

    printf("%d days\n",day);
    printf("%d hours\n",hour);
    printf("%d minutes\n",min);
    printf("%d seconds\n",sec);
}
