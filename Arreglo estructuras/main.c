#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i;
    printf("Ingrese la cantidad de libros a guardar: "); scanf("%i", &x);
    struct biblioteca{
        char nomb[20];
        int cant;
        float pre;
    }libro[x];

    for(i=0;i<x;i++){
        printf("Ingrese el nombre del libro %i: ", i+1);
        scanf("%s", &libro[i].nomb);
        printf("Ingrese la existencia del libro %i: ", i+1);
        scanf("%i", &libro[i].cant);
        printf("Ingrese el precio del libro %i: ", i+1);
        scanf("%f", &libro[i].pre);
    }
    for(i=0;i<x;i++){
        printf("\n");
        printf("Nombre del libro %i: %s", i+1, libro[i].nomb);
        printf("\n");
        printf("Existencia del libro %i: %i", i+1, libro[i].cant);
        printf("\n");
        printf("Precio del libro %i: %.2f", i+1, libro[i].pre);
        printf("\n");
    }
    return 0;
}
