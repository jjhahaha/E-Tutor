#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
    int year;
    scanf("%d", &year);

    // �]�|�~�O�@���|�~�A�ʦ~���O�|�~) || �|�ʦ~�O�|�~

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
