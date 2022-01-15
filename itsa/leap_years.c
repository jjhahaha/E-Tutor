#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
    int year;
    scanf("%d", &year);

    // （四年是一次閏年，百年不是閏年) || 四百年是閏年

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("Bissextile Year");
    }
    else
    {
        printf("Common Year");
    }
    printf("\n");
}
