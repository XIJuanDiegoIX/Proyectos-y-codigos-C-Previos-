/*Dise�ar un algoritmo que pida:
Clave de acceso (123), con la estructura selectiva doble.
Solo el nombre del alumno sin apellidos,
7 calificaciones de tipo entero (utilizando while)
y calcular el promedio de las mismas,

En la materia de �Dise�o Estructurado de Algoritmos�.

	IMPRIMIR:
Nombre del alumno
El Promedio
Nota: Dar est�tica a la presentaci�n de las pantallas e imprimir
la �ltima pantalla como si fuera una boleta de calificaciones de dicha materia.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    char nombre[20];
    int pass, var = 1, caltemp, prom = 0;
    setlocale(LC_ALL,"spanish");
    printf("\nO========================================================================O");
    printf("\n\n\t\tIngrese la contrase�a");
    printf("\n\n\nO========================================================================O");
    printf("\n\n\t\tContrase�a: ");
    scanf("%i",&pass);
    system("cls");
    fflush(stdin);
    if (pass == 123){
            system("cls");
            printf("\nO========================================================================O");
            printf("\n\n\t\tIngrese su unicamente su nombre");
            printf("\n\n\nO========================================================================O");
            printf("\n\n\t\tDigite su nombre: ");
            gets(nombre);
            while (var <= 7){
                system("cls");
                printf("\nO========================================================================O");
                printf("\n\n\t\tIngrese la calificacion de la materia %i", var);
                printf("\n\n\nO========================================================================O");
                printf("\n\n\t\tIngrese la calificacion: ");
                scanf("%i", &caltemp);
                prom = prom + caltemp;
                var++;
            }
            prom = prom / (var - 1);
            system("cls");
            printf("\nO========================================================================O");
            printf("\n\n\t\tVoleta de calificaciones del alumno:\n\t\t %s",nombre);
            printf("\n\n\n\nO========================================================================O");
            printf("\n\n\n\t\tSu promedio es: %i", prom);
            printf("\n\n\n\nO========================================================================O");
            printf("\n\n\t\tPulse <Enter> para salir\n\n");
    }
    else{
        printf("\nO========================================================================O");
        printf("\n\n\t\tLa contrase�a es incorrecta.");
        printf("\n\n\n\nO========================================================================O");
        printf("\n\n\t\tPulse <Enter> para salir\n\n");
    }
    return 0;
}
