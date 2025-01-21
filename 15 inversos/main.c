/*Almacenar 15 números en un vector,
Almacenarlos en otro vector en orden inverso al vector original.

IMPRIMIR:

a.- Vector original
b.- Vector resultante

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ord[15], inv[15], i, x=15;

    printf("=============================================================");
    printf("\n\n\t\tPrograma de cuadrado de vectores.");
    printf("\n\n=============================================================\n");

    for(i=1;i<16;i++){
        printf("\t\t%i Ingrese el numero: ", i);
        scanf("%i", &ord[i]);
        inv[x] = ord[i];
        x--;
        Sleep(400);
    }
    printf("\n\n=============================================================");
    sleep(1);
    system("cls");
    printf("=============================================================");
    printf("\n\n\t\tPrograma de cuadrado de vectores.");
    printf("\n\n=============================================================\n");
    printf("\tVector: Original, Inverso");
    for(i=1;i<16;i++){
        printf("\n\t\t%i\t %i", ord[i], inv[i]);
        Sleep(100);
    }
    printf("\n\n=============================================================\n");
    printf("\nIngrese ENTER para salir\n");
    return 0;
}
