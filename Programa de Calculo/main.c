#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "");
    do{
        menu();
    }while();
    return 0;

}

void menu(){
    int i;
    printf("\n\t1.- Suma de dos n�meros enteros.");
    printf("\n\t2.- Resta de dos n�meros enteros.");
    printf("\n\t3.- Multiplicaci�n de dos n�meros enteros.");
    printf("\n\t4.- divisi�n de dos n�meros enteros.");
    printf("\n\t5.- Salir");
    printf("\n\tElige una opci�n:");
    scanf("%i", i);
}
