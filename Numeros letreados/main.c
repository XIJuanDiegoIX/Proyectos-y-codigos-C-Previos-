/*Hacer un programa que pida por pantalla un número,
del 1 al 10 y mediante un procedimiento o funciones,
muestre por pantalla, el numero escrito con letras.

Imprimir:
El numero escrito con letras.


Nota: Agregar la función Sleep(400);
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    menu();
    fin();
    return 0;
}

void menu(){
    int n;
    t();
    printf("\n\t\tIngrese un numero del 1 al 10: ");
    scanf("%i", &n);
    switch(n){
        case 1: t(); n1(); break;
        case 2: t(); n2(); break;
        case 3: t(); n3(); break;
        case 4: t(); n4(); break;
        case 5: t(); n5(); break;
        case 6: t(); n6(); break;
        case 7: t(); n7(); break;
        case 8: t(); n8(); break;
        case 9: t(); n9(); break;
        case 10: t(); n10(); break;

    }
}

void n1(){
    printf("\n\t\tEl numero es el UNO");
}
void n2(){
    printf("\n\t\tEl numero es el DOS");
}
void n3(){
    printf("\n\t\tEl numero es el TRES");
}
void n4(){
    printf("\n\t\tEl numero es el CUATRO");
}
void n5(){
    printf("\n\t\tEl numero es el CINCO");
}
void n6(){
    printf("\n\t\tEl numero es el SEIS");
}
void n7(){
    printf("\n\t\tEl numero es el SIETE");
}
void n8(){
    printf("\n\t\tEl numero es el OCHO");
}
void n9(){
    printf("\n\t\tEl numero es el NUEVE");
}
void n10(){
    printf("\n\t\tEl numero es el DIEZ");
}
void t(){
    Sleep(400);
    system("cls");
    printf("============================================================");
    printf("\n\n\t\tDigitador de numeros");
    printf("\n\n============================================================\n");
}
void fin(){
    Sleep(400);
    printf("\n\n============================================================\n");
    printf("\n\t\tFin del programa Pulse <ENTER> para salir");
    printf("\n\n============================================================\n");
}

