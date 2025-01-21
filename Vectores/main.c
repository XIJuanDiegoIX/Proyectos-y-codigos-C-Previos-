#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, vec[5];
    printf("=========================================================");
    printf("\n\n\t\tPrograma de Recoleccion de numeros");
    printf("\n\n=========================================================");
    for(i=1;i<6;i++){
        printf("\n\tIngrese el valor del numero %i: ", i);
        scanf("%i", &vec[i]);
    }
    system("cls");
    printf("=========================================================");
    printf("\n\n\t\tPrograma de Recoleccion de numeros");
    printf("\n\n=========================================================");
    printf("\n\n\tLos numeros son:");
    for(i=1;i<6;i++){
        printf("\n\t%i", vec[i]);
    }
    printf("\n\n\tPresione <Enter> para salir");
    return 0;
}
