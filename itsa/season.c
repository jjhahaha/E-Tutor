#include<stdio.h>
#include<stdlib.h>


int main()
{
    int month;
    scanf("%d", &month);

    if(3 <= month && 5 >= month) printf("Spring");
    else if(6 <= month && 8 >= month) printf("Summer");
    else if(9 <= month && 11 >= month) printf("Autumn");
    else printf("Winter");

    printf("\n");
}
