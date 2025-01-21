/*Enunciado: Programa números positivos.
1) Diseñar un programa que pida 10 números e imprimir solamente
los números positivos, con la estructura “for”.
IMPRIMIR:
a) Título del programa.
b) Los números positivos (capturar y si es positivo que lo imprima
en ese momento, y continuar pidiendo números, auxiliarse de la
estructura selectiva simple).
c) No olvidar el mensaje de despedida y estética de las pantallas.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i;

    for(i=0;i<10;i++){
        system("cls");
        fflush(stdin);
        printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
        printf("\n\n\t\tPrograma de Numeros positivos");
        printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
        printf("\n\n\t\tIngrese un numero: ");
        scanf("%i", &num);
        if(num > 0){
            system("cls");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
            printf("\n\n\t\tPrograma de Numeros positivos");
            printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
            printf("\n\n\t\tEl numero %i es positivo", num);
            printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
            sleep(3);
        }
        system("cls");
        printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
        printf("\n\n\t\tPrograma de Numeros positivos");
        printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
        printf("\n\n\t\tEl programa ha terminado\n");
        printf("\n\n\t\tPulse <ENTER> para terminar el programa");
        printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
    }
    return 0;
}
