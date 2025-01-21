
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int x;

    do{
        setlocale(LC_ALL, "");
        system("cls");
        printf("===================================================================");
        printf("\n\n\t\tPrograma de Saludo");
        printf("\n\n===================================================================");
        printf("\n\n\t\tHOLA ('v')");
        sleep(2);
        printf("\n\n\t\t¿Deseas que se vuelva a imprimir la palabra, “Hola”?");
        printf("\n\t\tPresione: \n\t\t1 para si\n\t\t2 para no\n");
        scanf("%i",&x);
        if(x != 1 && x != 2){
            printf("\n\t\tEste caracter no es valido.\n\t\tFinalisando programa.");
            sleep(2);
            }
        }while(x == 1);
    system("cls");
    printf("===================================================================");
    printf("\n\n\t\tPrograma de Saludo");
    printf("\n\n\===================================================================");
    printf("\n\t\tEl programa ha finalizado\n\t\tPulse <Enter> para salir");
    sleep(2);

    return 0;

}
