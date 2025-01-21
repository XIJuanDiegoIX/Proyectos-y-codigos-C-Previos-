#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void Arbol();

int main()
{
    int r;
    setlocale(LC_ALL, "");
    do{
        fflush(stdin);
        Arbol();
        system("color 0A");
        fflush(stdin);
        Arbol();
        system("color 0B");
        fflush(stdin);
        Arbol();
        system("color 0C");
        fflush(stdin);
        Arbol();
        system("color 0D");
        fflush(stdin);
        Arbol();
        system("color 0E");
        fflush(stdin);
        Arbol();
        system("color 0F");
        fflush(stdin);
        r++;    }while(r<4);
    return 0;
}

void Arbol(){
    system("cls");
    int x, y=1, z, x2, y2=1;
    printf("\n");
    printf("\n");    printf("\a \a \a \a \a\t\t\t      ÁRBOL\n\n");
    printf("\n");
    for(z=0;z<12;z++){
        for(x2=32;x2>=y2;x2--){ //Distancia entre el borde y el arbol
            printf(" ");
        }
        for(x=1;x<=y;x++){ //Anchura del arbol
            printf("X");
        }
        printf("\n");
        y+=2;
        y2++;
    }
    for(x=1;x<5;x++){
        printf("\t\t\t      +++++\n");
    }
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                Autor: Juan Diego Rodriguez Macias               \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t      Versión 1.1\n");
    Sleep(600);
}
