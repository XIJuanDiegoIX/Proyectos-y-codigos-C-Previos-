#include <stdio.h>
#include <stdlib.h>
struct Computadora{
char tipo[20];
int cantidad;
float precio;

}pc;

int main()
{
    printf("Ingrese el tipo: "); scanf("%s", &pc.tipo);
    fflush(stdin);
    printf("Ingrese la cantidad: "); scanf("%i", &pc.cantidad);
    printf("Ingrese la precio: "); scanf("%f", &pc.precio);

    printf("\n");
    printf("\n");
    fflush(stdin);
    printf("Tipo: %s", pc.tipo);
    printf("\n");
    printf("Cantidad: %i", pc.cantidad);
    printf("\n");
    printf("Precio: %.2f", pc.precio);
    return 0;
}
