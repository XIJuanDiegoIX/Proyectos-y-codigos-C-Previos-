/*Diseñar un algoritmo que llene un vector A, con 7 números de tipo entero,
los sume y con conforme se vaya sumando, al mismo tiempo…
ir llenando un vector B

IMPRIMIR:
Primero vector A y posteriormente vector B

Nota: al imprimir cada vector utilizar Sleep( … );
Acumular la calificación:
suma=suma+A[x];
Asignar la suma al vector “B”:
B[x] =suma;

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int suma, i, vec[7], vec2[7];

    for(i=1;i<8;i++){
        printf("=============================================================");
        printf("\n\n\t\tPrograma de suma de datos. ");
        printf("\n\n=============================================================");
        printf("\n\n\t\t%i Ingrese el valor: ", i);
        scanf("%i", &vec[i]);
        suma = suma + vec[i];
        vec2[i] = suma;
        fflush(stdin);
        Sleep(400);
        system("cls");
    }
    printf("=============================================================");
    printf("\n\n\t\tPrograma de suma de datos. ");
    printf("\n\n=============================================================\n");
    for(i=1;i<8;i++){
        printf("\n\tEl valor %i es: %i", i, vec[i]);
        Sleep(400);
    }
    printf("\n\n=============================================================\n");
        for(i=1;i<8;i++){
        printf("\n\tEl valor de la suma %i es: %i", i, vec2[i]);
        Sleep(400);
    }
    printf("\n\n=============================================================\n");
    printf("\n\n\t\tPresione <Enter> para terminar\n\n");
    return 0;
}
