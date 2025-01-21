#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char a[25];
    int i;

    for(i=0;i<5;i++){
        printf("\n%i Ingrese su nombre:",i+1);
        gets(a);
        printf("%s", a);
        Sleep(400);
        fflush(stdin);
    }

    getch();
    return 0;
}
