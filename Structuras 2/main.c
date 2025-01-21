#include <stdio.h>
#include <stdlib.h>
    struct biblioteca{
    char libro1;
    char libro2;
    };

    struct libro{
    char nombre[30];
    char tipo[20];
    int disponible;
    float precio;

    struct biblioteca tiplibro;
    }libro1,libro2;

int main()
{
    printf("INGRESE EL NOMBRE DEL LIBRO 1\n");
    gets(libro1.nombre);
    fflush(stdin);
    printf("INGRESA DE QUE TIPO ES EL LIBRO 1\n");
    gets(libro1.tipo);
    fflush(stdin);
    printf("INGRESA LA DISPONIBILIDAD DEL LIBRO 1\n");
    scanf("%d", &libro1.disponible);
    printf("INGRESA EL PRECIO DEL LIBRO 1\n");
    scanf("%f", &libro1.precio);
    fflush(stdin);


    printf("INGRESE EL NOMBRE DEL LIBRO 2\n");
    gets(libro2.nombre);
    fflush(stdin);
    printf("INGRESA DE QUE TIPO ES EL LIBRO 2\n");
    gets(libro2.tipo);
    fflush(stdin);
    printf("INGRESA LA DISPONIBILIDAD DEL LIBRO 2\n");
    scanf("%d", &libro2.disponible);
    printf("INGRESA EL PRECIO DEL LIBRO 2\n");
    scanf("%f", &libro2.precio);
    fflush(stdin);

    printf("_____________________________\n");
    printf("DATOS DEL LIBRO \n");
    printf("LIBRO 1: \n");
    printf("NOMBRE: %s\n", libro1.nombre);
    printf("TIPO: %s\n", libro1.tipo);
    printf("DISPONIBILIDAD: %d\n", libro1.disponible);
    printf("PRECIO: %f\n", libro1.precio);

    printf("_____________________________\n");
    printf("DATOS DEL LIBRO \n");
    printf("LIBRO 2: \n");
    printf("NOMBRE: %s\n", libro2.nombre);
    printf("TIPO: %s\n", libro2.tipo);
    printf("DISPONIBILIDAD: %d\n", libro2.disponible);
    printf("PRECIO: %f\n", libro2.precio);

    return 0;
}
