/*Enunciado: Programa n�meros positivos.
1) Dise�ar un programa que pida 10 n�meros e imprimir solamente
los n�meros positivos, con la estructura �for�.
IMPRIMIR:
a) T�tulo del programa.
b) Los n�meros positivos (capturar y si es positivo que lo imprima
en ese momento, y continuar pidiendo n�meros, auxiliarse de la
estructura selectiva simple).
c) No olvidar el mensaje de despedida y est�tica de las pantallas.*/

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
