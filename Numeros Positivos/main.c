#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int cal, prom, cont=1;
    char nomb[100];

    printf("=============================================================");
    printf("\n\t\tPrograma de promedios.");
    printf("\n=============================================================");
    printf("\n\n\t\tIngrese su nombre: \n\t");
    gets(nomb);

    do{
        system("cls");
        printf("=============================================================");
        printf("\n\t\tPrograma de promedios.");
        printf("\n=============================================================");
        printf("\n\n\t\tIngrese la calificacion #%i: ",cont);
        scanf("%i", &cal);
        prom += cal;
        cont++;
    }while(cont <= 7);

    system("cls");
    printf("=============================================================");
    printf("\n\t\tPrograma de promedios.");
    printf("\n=============================================================");
    prom = prom / 7;
    printf("\n\n\t\tAlumno: %s \n\t\tSu promedio es: %i",nomb, prom);
    printf("\n\n=============================================================\n\nPulse <ENTER> para salir... \n\n");

    return 0;
}
