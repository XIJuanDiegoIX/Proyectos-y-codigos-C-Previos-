/*Almacenar 10 números en un vector,
Elevar al cuadrado cada valor almacenado en el vector,
Almacenar el resultado en otro vector.
IMPRIMIR:
Los vectores: original y el vector resultante.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, vec[10], vec2[10];

    printf("=============================================================");
    printf("\n\n\t\tPrograma de cuadrado de vectores.");
    printf("\n\n=============================================================");
    for(i=1;i<11;i++){
        printf("\n\t\t%i. Ingrese un numero: ", i);
        scanf("%i", &vec[i]);
        vec2[i] = vec[i] * vec[i];
        sleep(1);
    }
    printf("\n\n=============================================================");
    sleep(3);
    system("cls");
    printf("=============================================================");
    printf("\n\n\t\tPrograma de cuadrado de vectores.");
    printf("\n\n=============================================================");
    printf("\n\n\t\tLos valores del vector 1 son: ");
    for(i=1;i<11;i++){
        printf("\n\t\t\t%i: %i", i, vec[i]);
        sleep(1);
    }
    printf("\n\n\t\tLos valores al cuadrado del vector 2 son: ");
    for(i=1;i<11;i++){
        printf("\n\t\t\t%i: %i", i, vec2[i]);
        sleep(1);
    }
    printf("\n\n=============================================================");
    sleep(3);
    printf("\n\n\t\tPresione enter para salir...");
    return 0;
}
