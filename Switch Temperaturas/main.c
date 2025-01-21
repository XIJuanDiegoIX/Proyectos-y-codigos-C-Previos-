/*Nota importante:

_______________________________________________________________-_______
a) Al ejecutarlos, al final preguntar si se desea volver a ejecutar:
Presionar el número 1, Para Si,
O cualquier otro número, Para No
Con la estructura cíclica do…while.

EJERCICIO PROPUESTO:

Programa_23:
Enunciado:
Sistema, “Conversiones de Grados”, las Funciones a agregar son las siguientes:
1.- Grados 0 F a 0 C
2.- Grados 0 C a 0 F
3.- Grados 0 C a 0 K
4.- Grados 0 K a 0 C
5.- Salir*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float RESF(float res);
float FC();
float CF();
float KC();
float CK();


int main()
{
    int r2;
    do{
        menu();
        title();
        printf("\n\t\tQuiere repetir el programa?\n\t\t1.Si\n\t\t2.No\n\t\tRespuesta: "); scanf("%i",&r2);
    }while(r2 != 2);
    fin();

    return 0;
}

void menu(){
    title();
    float t;
    int i;
    printf("\n\t1.- Grados F a C\n\t2.- Grados C a F\n\t3.- Grados C a K\n\t4.- Grados K a C\n\t5.- Salir...\n\tRespuesta: ");
    scanf("%i", &i);
    printf("\n\n============================================================\n");
    Sleep(1000);
    if(i != 5){
        switch(i){
            case 1:
            t = FC();
            RESF(t);
            getch();
            break;
            case 2:
            t = CF(t);
            RESF(t);
            getch();
            break;
            case 3:
            t = CK(t);
            RESF(t);
            getch();
            break;
            case 4:            t = KC(t);
            RESF(t);
            getch();
            break;
        }
    }
}

float FC(){
    title();
    float res, n1;
    printf("\n\tIngrese los grados F a convertir a C: ");
    scanf("%f",&n1);
    res=((n1-32)*0.5555);
    return res;
}

float CF(){
    title();
    float res, n1;
    printf("\n\tIngrese los grados C a convertir a F: "); scanf("%f", &n1);
    res = (n1 * 1.8) + 32;
    return res;
}

float CK(){
    title();
    float res, n1;
    printf("\n\tIngrese los grados C a convertir a K: "); scanf("%f", &n1);
    res = n1 + 273.15;
    return res;
}

float KC(){
    title();
    float res, n1;
    printf("\n\tIngrese los grados K a convertir a C: "); scanf("%f", &n1);
    res = n1 - 273.15;
    return res;
}

void title(){
    Sleep(400);
    system("cls");
    printf("============================================================");
    printf("\n\n\t\tConversion de grados");
    printf("\n\n============================================================\n");

}

void fin(){
    Sleep(400);
    printf("\n\n============================================================\n");
    printf("\n\tFin del programa Pulse <ENTER> para salir");
    printf("\n\n============================================================\n");
}

float RESF(float res){
    printf("\n\n============================================================");
    printf("\n\t\tEl resultado es: %.2f", res);
    printf("\n\t\tPulse <ENTER> para continuar");
    printf("\n============================================================");
}
