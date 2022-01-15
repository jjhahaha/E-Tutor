#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
    int year;
    scanf("%d", &year);

    //(Four years is a Bissextile Year, one hundred years is not a Bissextile Year) || Four hundred years is a Bissextile Year

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("Bissextile Year\n");
    }
    else
    {
        printf("Common Year\n");
    }
    //printf("\n");
}
