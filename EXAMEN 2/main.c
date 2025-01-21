#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
void titulo();
int ERR(int i);
void ERR2();
void ver();
void car();
int menu(int opc1);
void cont();
void fin();

int main()
{
    setlocale(LC_ALL, "");
    int i=0;
    do{
        titulo();
        i = ingreso(i);
    }while(i < 3);
    if(i == 3){
        titulo();
        printf("\n\n\tDemasiados intentos programa finalizado...");
        printf("\n\n\tPresione <Enter> para continiar...");
        getch();
    }
    fin();
    return 0;
}

void titulo(){
    system("cls");
    printf("---------------------------------------------------------");
    printf("\n\n\tSistema de boletas de Alumnos");
    printf("\n\n---------------------------------------------------------");
}

int ingreso(int i){
    int pass, r;
    printf("\n\n\tIngrese su nip: "); scanf("%i", &pass);
    if(pass == 123){
        car();
        ver();
        car();
        do{
            r = menu(r);
            i = 4;
        }while(r != 4);
    }else{
        i++;
        ERR(i);
    }
    return i;
}

int ERR(int i){
    titulo();
    printf("\n\n\t¡¡¡¡¡¡NIP INCORRECTO!!!!!!...");
    printf("\n\n\tLleva (%i/3) intentos...", i);
    printf("\n\n\tPresione <Enter> para continiar...");
    getch();
}

void ERR2(){
    fflush(stdin);
    titulo();
    printf("\n\n\t¡Numero No Valido!...");
    printf("\n\n\tPresione <Enter> para continiar...");
    getch();
}

void fin(){
    titulo();
    printf("\n\n\tPrograma finalizado");
    printf("\n\n\tPresione <Enter> para continuar...");
    printf("\n\n---------------------------------------------------------");
    getch();
}

void cont(){
    printf("\n\n\tPresione <Enter> para continuar...");
    getch();
}

int menu(int opc1){
    float dat[7][7];
    char nomb[100], grupo[100];
    int x, y;
    float prom;
    titulo();
    printf("\n\n\t1.- CAPTURAR BOLETA\n\t2.- IMPRIMIR BOLETA\n\t3.- IMPRIMIR SOLO DATOS DEL ALUMNO.\n\t4.- SALIR DEL SISTEMA");
    printf("\n\n\tELIGE UNA OPCION: "); scanf("%i", &opc1);
    if(opc1 <= 4 && opc1 >= 1){
        if(opc1 == 1){
                titulo();
                printf("\n\n\tCodigo: "); scanf("%f", &dat[1][1]);
                printf("\tNombre: "); scanf("%s", &nomb);
                fflush(stdin);
                printf("\tGrupo: "); scanf("%s", &grupo);
                printf("\tGrado: "); scanf("%f", &dat[4][1]);
                printf("\tEdad: "); scanf("%f", &dat[5][1]);
                printf("\n\tCalificaciones: \n");
                for(y=0;y<7;y++){
                    printf("\tIngrese la calificacion numero %i: ", y+1);
                    scanf("%f", &dat[6][y]);
                }
                for(y=0;y<7;y++){
                    prom += dat[6][y];
                }
                prom = prom/7;
                dat[7][1] = prom;
                printf("\n\tDatos Guardados!!");
                cont();
        }else if(opc1 == 2){
                titulo();
                printf("\n\n\tCodigo: %.0f", dat[1][1]);
                printf("\n\tNombre: %s", nomb);
                printf("\n\tGrupo: %s", grupo);
                printf("\n\tGrado: %.0f", dat[4][1]);
                printf("\n\tEdad: %.0f", dat[5][1]);
                printf("\n\tCalificaciones: ");
                for(y=0;y<7;y++){
                    printf("\n\tCalificacion numero %i: %.2f", y+1, dat[6][y]);
                }
                printf("\n\tPromedio: %.2f", dat[7][1]);
                cont();
        }else if(opc1 == 3){
                titulo();
                printf("\n\n\tCodigo: %.0f", dat[1][1]);
                printf("\n\tNombre: %s", nomb);
                printf("\n\tGrupo: %s", grupo);
                printf("\n\tGrado: %.0f", dat[4][1]);
                printf("\n\tEdad: %.0f", dat[5][1]);
                cont();
        }else if(opc1 == 4){
                titulo();
                printf("\n\n\tElejiste la opcion Salir...");
                cont();
        }
    }else{
        ERR2();
    }
    return opc1;
}

void car(){
    int i;
    for(i = 0; i<6; i++){
    system("cls");
    titulo();
    printf("\n\n\tCargando Sistema.");
    Sleep(100);
    printf(".");
    Sleep(100);
    printf(".");
    Sleep(600);
    }
}

void ver(){
        system("cls");
        titulo();
        Sleep(600);
        printf("\no-------------------------------------------------------o");
        printf("\n|   o----------------------o                            |");
        printf("\n|   | Nip *********        |                            |");
        printf("\n|   | Jose Alberto         |                            |");
        printf("\n|   |                      |                            |");
        printf("\n|   |                      |                            |");
        printf("\n|   o----------------------o                            |");
        printf("\n|                                                       |");
        printf("\n|                            Por: Juan Diego Rodriguez  |");
        printf("\n|                                          version 1.1  |");        printf("\no-------------------------------------------------------o");
        Sleep(1600);
}


