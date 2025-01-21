#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int tabla[2][3], x, y;
    for(x=0;x<2;x++){
        for(y=0;y<3;y++){
            printf("======================================================================");
            printf("\n\n\t\tPrograma de creacion de tabla.");
            printf("\n\n======================================================================");
            printf("\n\tIngrese un numero para la posicion: (%i,%i): ",x+1 ,y+1);
            scanf("%i", &tabla[x][y]);
            Sleep(400);
            system("cls");
        }
    }
        printf("======================================================================");
        printf("\n\n\t\tPrograma de creacion de tabla.");
        printf("\n\n======================================================================");
        printf("\n\n\tLa tabla es la siguiente: \n\t\t________________\n\t\t");
        for(x=0;x<2;x++){
            for(y=0;y<3;y++){
                printf("|%3i ",tabla[x][y]);
                Sleep(400);
            }
            printf("|\n\t\t|____|____|____|\n\t\t");
        }
        Sleep(400);
    printf("\n\n======================================================================");
    printf("\n\n\tProceso terminado, ingrese <Enter> para salir...");
    printf("\n\n======================================================================");
    getch();

    return 0;
}
