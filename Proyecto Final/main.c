#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
void gotoxy(int x, int y);
void mostrar();
void captura();
void cargS();
void marco();
void color();
int menu();
void eliminar();
int borrar(int x);
int modper(int x);
int modaca(int x);
void modificar();
void buscar();
void busper();
void busaca();
void PreSave();
int ingreso(int i);
int ERR(int i);
void img1();
void img2();
void img3();
void img4();
void img5();
void entr();
void entr2();
void sal();
void pant();


struct Datos{   //ESTE APARTADO SE ENCARGA DE CREEAR LA ESTRUCTURA
    struct Personales{
        char nom[50], dom[100], fra[20], ciu[20], tel[20], ema[50], est[30]/*civil*/, nac[30];
        int cp, edad;
    }Per;

    struct Academicos{
        char nom[50], car[50], pro[50], mat[50], hor[10], cun[100]/*Centro univercitario*/, dias[100];
        int edad, grad, cdias;
    }Aca;
}dat[10];

int main(){
    PreSave();
    system("color 10");
    setlocale(LC_ALL, "");
    int i,r,r2=0;
    while(r2==0){
    i=0;
    r=0;
        do{
            marco();
            gotoxy(6,6);
            i = ingreso(i);
        }while(i < 3);
        if(i == 3){
            marco();
            gotoxy(6,6);
            printf("\n\n\tDemasiados intentos programa finalizado...");
            printf("\n\n\tPresione <Enter> para continiar...");
            getch();
        }
        marco();
        gotoxy(6,12);
        printf("\n\n\t¿LE GUSTARIA REPETIR EL PROGRAMA?");
        printf("\n\n\t1.SI OTRO.NO");
        printf("\n\n\tRESULTADO: ");
        scanf("%i", &r);
        if(r != 1){
                r2++;
        }
        printf("\n\n\n\n\n\n\n\n\n");
    }
    printf("\n\n");
    return 0;
}

int ingreso(int i){
    int pass, r;
    printf("\tIngrese su nip: "); scanf("%i", &pass);
    if(pass == 123){
        do{
            entr2();
            r = menu();
            sal();
            i = 4;
        }while(r != 7);
    }else{
        i++;
        ERR(i);
    }
    return i;
}

int ERR(int i){
    marco();
    gotoxy(6,6);
    printf("\t¡¡¡¡¡¡NIP INCORRECTO!!!!!!...");
    printf("\n\n\tLleva (%i/3) intentos...", i);
    printf("\n\n\tPresione <Enter> para continiar...");
    getch();
}

void PreSave(){
strcpy(dat[0].Per.nom, "JUAN DIEGO RODRIGUEZ MACIAS");
strcpy(dat[4].Per.nom, "JUAN DIEGO RODRIGUEZ MACIAS");
strcpy(dat[7].Per.nom, "JUAN DIEGO RODRIGUEZ MACIAS");
strcpy(dat[0].Per.dom, "FOVISSSTE MANZANA 1");
strcpy(dat[0].Per.fra, "NINGUNO");
strcpy(dat[0].Per.ciu, "ZAPOPAN");
strcpy(dat[0].Per.tel, "3321212345");
strcpy(dat[0].Per.ema, "JDEGOMAC@GMAIL.COM");
strcpy(dat[0].Per.est, "SOLTERO");
strcpy(dat[0].Per.nac, "9 JULIO 2003");
dat[0].Per.cp = 45149;
dat[0].Per.edad = 20;
strcpy(dat[0].Aca.nom, "JUAN DIEGO RODRIGUEZ MACIAS");
strcpy(dat[0].Aca.car, "ICOM");
strcpy(dat[0].Aca.pro, "ALMA GLORIA");
strcpy(dat[0].Aca.mat, "PROGRAMACION ESTRUCTURADA");
strcpy(dat[0].Aca.hor, "7-9");
strcpy(dat[0].Aca.cun, "CUCEI");
strcpy(dat[0].Aca.dias, "LUNES - JUEVES");
dat[0].Aca.edad = 20;
dat[0].Aca.grad = 2;
dat[0].Aca.cdias = 4;
}

int menu(){
    int r, r2=0, i;
    do{
        marco();
        gotoxy(45,6);
        printf("MENU");
        gotoxy(40,8);
        printf("1.- CAPTURAR");
        gotoxy(40,10);
        printf("2.- MOSTRAR");
        gotoxy(40,12);
        printf("3.- BUSCAR");
        gotoxy(40,14);        printf("4.- MODIFICAR");
        gotoxy(40,16);
        printf("5.- ELIMINAR");
        gotoxy(40,18);
        printf("6.- CAMBIAR COLOR");
        gotoxy(40,20);
        printf("7.- SALIR");
        gotoxy(40,22);
        printf("RESPUESTA: ");
        scanf("%i", &r);
        if(r < 1 || r > 7){
            printf("\n\n\tNÚMERO NO VÁLIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            printf("\n\tPULSE <ENTER> PARA CONTINUAR...");
            getch();
        }else{
            gotoxy(95,26);
            cargS();
            switch(r){
                case 1: captura(); break;
                case 2: mostrar(); break;
                case 3: buscar(); break;
                case 4: modificar(); break;
                case 5: eliminar(); break;
                case 6: color(); break;
                case 7: r2++; i=7; break;
            }
        }
    }while(r2 < 1);
    return i;
}

void eliminar(){
    int i, x=0, r=0, r2=0, r3=0;
    do{ //CICLO PARA COMPROBAR QUE EL DATO GUARDADO ES CORRECTO Y QUE EL NUMERO SEA VALIDO
        do{ // MENU DE SELECCION DE RANURA DE ALMACENAMIENTO
            marco();
            gotoxy(6,5);
            printf("<<ELIMINAR DATOS>>\n\n\tELIMINAR LA POSICION EN LA POSICION:\n\n\tSELECCIONE UNA POSICION ENTRE 1 Y 10\n\n\tSELECCIONE 11 PARA SALIR\n\n\tPOSICION: ");
            scanf("%i", &r);        //GUARDA Y COMPRUEBA QUE EL DATO ES VALIDO
            if(r < 1 || r > 11){    //DE LO CONTRARIO VOLVERA A EJECUTARSE
                printf("\n\n\tNUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                printf("\n\tPULSE <ENTER> PARA CONTINUAR...");
                getch();
            }else{
                x = r-1;
                r2++; //CIERRA EL CICLO DO Y PASA A LA SIGUIENTE PESTAÑA
            }
        }while(r2 < 1);
        r2--;
        gotoxy(6,15);
        cargS(); //AGREGARA UNPEQUEÑO TIEMPO DE ESPERA ANTES DE LA SIGUIENTE PESTAÑA
        if(r == 11){
            r3++;
        }else{
            marco();
            gotoxy(6,5);
            printf("<<ELIMINAR DATOS>>\n\tDATOS:\t\t\tDATOS PERSONALES:");

            for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
                gotoxy(30,i);
                printf("|");
            }
            gotoxy(30,4);
            printf("O");
            gotoxy(30,28);
            printf("O");

            gotoxy(6,6);
            printf("\n\n\tNOMBRE:\n\n\tDOMICILIO:\n\n\tFRACCIONAMIENTO:\n\n\tCIUDAD:\n\n\tTELEFONO:\n\n\tEMAIL:\n\n\tESTADO CIVIL:\n\n\tFECHA DE NACIMIENTO:\n\n\tCODIGO POSTAL:\n\n\tEDAD:");
            gotoxy(6,6);
            { //IMPRIMIRA LOS DATOS Y PREGUNTARA SI QUIERE CORREGIRLOS
                fflush(stdin);
                gotoxy(32,6);
                printf("\n\n\t\t\t\t%s", dat[x].Per.nom);
                printf("\n\n\t\t\t\t%s", dat[x].Per.dom);
                printf("\n\n\t\t\t\t%s", dat[x].Per.fra);
                printf("\n\n\t\t\t\t%s", dat[x].Per.ciu);
                printf("\n\n\t\t\t\t%s", dat[x].Per.tel);
                printf("\n\n\t\t\t\t%s", dat[x].Per.ema);
                printf("\n\n\t\t\t\t%s", dat[x].Per.est);
                printf("\n\n\t\t\t\t%s", dat[x].Per.nac);
                printf("\n\n\t\t\t\t%i", dat[x].Per.cp);
                printf("\n\n\t\t\t\t%i", dat[x].Per.edad);
            }
            gotoxy(60,24);
            printf("PULSE <ENTER> PARA VER LA SIGUIENTE PESTAÑA...");
            gotoxy(60,25);
            getch();
            r2=0; r3=0;
            do{ // MENU DE SELECCION DE RANURA DE ALMACENAMIENTO
                marco();
                gotoxy(6,5);
                printf("<<ELIMINAR DATOS>>\n\tDATOS:\t\t\t\tDATOS ACADEMICOS:");

                for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTIVAL
                    gotoxy(30,i);
                    printf("|");
                }
                gotoxy(30,4);
                printf("O");
                gotoxy(30,28);
                printf("O");

                gotoxy(6,6);
                printf("\n\n\tNOMBRE:\n\n\tCARRERA:\n\n\tPROFESOR:\n\n\tMATERIA:\n\n\tHORARIO:\n\n\tCENTRO UNIVERSITARIO:\n\n\tDIAS DE ASISTENCIA:\n\n\tEDAD:\n\n\tGRADO O SEMESTRE:\n\n\tCANTIDAD DE DIAS:");
                gotoxy(6,6);
                { //IMPRIMIRA LOS DATOS Y PREGUNTARA SI QUIERE CORREGIRLOS
                    fflush(stdin);
                    gotoxy(32,6);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.nom);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.car);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.pro);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.mat);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.hor);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.cun);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.dias);
                    printf("\n\n\t\t\t\t%i", dat[x].Aca.edad);
                    printf("\n\n\t\t\t\t%i", dat[x].Aca.grad);
                    printf("\n\n\t\t\t\t%i", dat[x].Aca.cdias);
                }
                gotoxy(60,24);
                printf("¿DESEA BORRAR ESTOS DATOS?");
                gotoxy(60,25);
                printf("\t1.SI\t2.NO");
                gotoxy(60,26);
                printf("\tRESPUESTA: ");
                scanf("%i", &r);
                if(r < 1 || r > 2){
                    gotoxy(50,24);
                    printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                    gotoxy(60,25);
                    printf("PULSE <ENTER> PARA CONTINUAR...");
                    gotoxy(60,26);
                    printf("                               ");
                    getch();
                }else{
                    if(r == 1){
                        r2++;
                        borrar(x);
                        r3++;
                        gotoxy(80,26);
                        cargS();
                    }else{
                        r2++;
                    }
                }
            }while(r2 < 1);
        }
    }while(r3 < 1);
}

int borrar(int x){
    strcpy(dat[x].Per.nom, "");
    strcpy(dat[x].Per.dom, "");
    strcpy(dat[x].Per.fra, "");
    strcpy(dat[x].Per.ciu, "");
    strcpy(dat[x].Per.tel, "");
    strcpy(dat[x].Per.ema, "");
    strcpy(dat[x].Per.est, "");
    strcpy(dat[x].Per.nac, "");
    dat[x].Per.cp = 0;
    dat[x].Per.edad = 0;
    strcpy(dat[x].Aca.nom, "");
    strcpy(dat[x].Aca.car, "");
    strcpy(dat[x].Aca.pro, "");
    strcpy(dat[x].Aca.mat, "");
    strcpy(dat[x].Aca.hor, "");
    strcpy(dat[x].Aca.cun, "");
    strcpy(dat[x].Aca.dias, "");
    dat[x].Aca.edad = 0;
    dat[x].Aca.grad = 0;
    dat[x].Aca.cdias = 0;
}

void mostrar(){
    int i, x, r, r2;
    do{ // MENU DE SELECCION DE RANURA DE ALMACENAMIENTO
        marco();
        gotoxy(6,5);
        printf("<<MOSTRAR DATOS>>\n\n\tMOSTRAR EN LA POSICION:\n\n\tSELECCIONE UNA POSICION ENTRE 1 Y 10\n\n\tSELECCIONE 11 PARA SALIR\n\n\tPOSICION: ");
        scanf("%i", &r);        //GUARDA Y COMPRUEBA QUE EL DATO ES VALIDO
        if(r < 1 || r > 11){    //DE LO CONTRARIO VOLVERA A EJECUTARSE
            printf("\n\n\tNUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            printf("\n\tPULSE <ENTER> PARA CONTINUAR...");
            getch();
        }else{
            x = r-1;
            r2++; //CIERRA EL CICLO DO Y PASA A LA SIGUIENTE PESTAÑA
        }
    }while(r2 < 1);
    gotoxy(6,15);
    cargS();
    if(r != 11){
        marco();
        gotoxy(6,5);
        printf("<<MOSTRAR DATOS>>\n\tDATOS:\t\t\t\tDATOS PERSONALES: ");
        for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
            gotoxy(30,i);
            printf("|");
        }
        gotoxy(30,4);
        printf("O");
        gotoxy(30,28);
        printf("O");
        gotoxy(6,6);
        printf("\n\n\tNOMBRE:\n\n\tDOMICILIO:\n\n\tFRACCIONAMIENTO:\n\n\tCIUDAD:\n\n\tTELEFONO:\n\n\tEMAIL:\n\n\tESTADO CIVIL:\n\n\tFECHA DE NACIMIENTO:\n\n\tCODIGO POSTAL:\n\n\tEDAD:");
        gotoxy(6,6);
        { //IMPRIMIRA LOS DATOS Y PREGUNTARA SI QUIERE CORREGIRLOS
            fflush(stdin);
            gotoxy(32,6);
            printf("\n\n\t\t\t\t%s", dat[x].Per.nom);
            printf("\n\n\t\t\t\t%s", dat[x].Per.dom);
            printf("\n\n\t\t\t\t%s", dat[x].Per.fra);
            printf("\n\n\t\t\t\t%s", dat[x].Per.ciu);
            printf("\n\n\t\t\t\t%s", dat[x].Per.tel);
            printf("\n\n\t\t\t\t%s", dat[x].Per.ema);
            printf("\n\n\t\t\t\t%s", dat[x].Per.est);
            printf("\n\n\t\t\t\t%s", dat[x].Per.nac);
            printf("\n\n\t\t\t\t%i", dat[x].Per.cp);
            printf("\n\n\t\t\t\t%i", dat[x].Per.edad);
        }
        gotoxy(60,24);
        printf("PULSE <ENTER> PARA CONTINUAR...");
        getch();
        gotoxy(95,27);
        cargS();
        marco();
        gotoxy(6,5);
        printf("<<MOSTRAR DATOS>>\n\tDATOS:\t\t\t\tDATOS ACADEMICOS:");
        for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
            gotoxy(30,i);
            printf("|");
        }
        gotoxy(30,4);
        printf("O");
        gotoxy(30,28);
        printf("O");
        gotoxy(6,6);
        printf("\n\n\tNOMBRE:\n\n\tCARRERA:\n\n\tPROFESOR:\n\n\tMATERIA:\n\n\tHORARIO:\n\n\tCENTRO UNIVERSITARIO:\n\n\tDIAS DE ASISTENCIA:\n\n\tEDAD:\n\n\tGRADO O SEMESTRE:\n\n\tCANTIDAD DE DIAS:");
        gotoxy(6,6);
        { //IMPRIMIRA LOS DATOS Y PREGUNTARA SI QUIERE CORREGIRLOS
            fflush(stdin);
            gotoxy(32,6);
            printf("\n\n\t\t\t\t%s", dat[x].Aca.nom);
            printf("\n\n\t\t\t\t%s", dat[x].Aca.car);
            printf("\n\n\t\t\t\t%s", dat[x].Aca.pro);
            printf("\n\n\t\t\t\t%s", dat[x].Aca.mat);
            printf("\n\n\t\t\t\t%s", dat[x].Aca.hor);
            printf("\n\n\t\t\t\t%s", dat[x].Aca.cun);
            printf("\n\n\t\t\t\t%s", dat[x].Aca.dias);
            printf("\n\n\t\t\t\t%i", dat[x].Aca.edad);
            printf("\n\n\t\t\t\t%i", dat[x].Aca.grad);
            printf("\n\n\t\t\t\t%i", dat[x].Aca.cdias);
        }
        gotoxy(60,24);
        printf("PULSE <ENTER> PARA CONTINUAR...");
        getch();
        gotoxy(95,27);
        cargS();
    }
}

void captura(){ //CAPTURA DE DATOS
    int i, x, r, r2=0, r3=0;
    do{ // MENU DE SELECCION DE RANURA DE ALMACENAMIENTO
        marco();
        gotoxy(6,5);
        printf("<<CAPTURA DE DATOS>>\n\n\tGUARDAR EN LA POSICION:\n\n\tSELECCIONE UNA POSICION ENTRE 1 Y 10\n\n\tSELECCIONE 11 PARA SALIR...\n\n\tPOSICION: ");
        scanf("%i", &r);        //GUARDA Y COMPRUEBA QUE EL DATO ES VALIDO
        if(r < 1 || r > 11){    //DE LO CONTRARIO VOLVERA A EJECUTARSE
            printf("\n\n\tNUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            printf("\n\tPULSE <ENTER> PARA CONTINUAR...");
            getch();
        }else{
            x = r-1;
            r2++; //CIERRA EL CICLO DO Y PASA A LA SIGUIENTE PESTAÑA
        }
    }while(r2 < 1);
    r2--;
    if(r!=11){
        gotoxy(6,15);
        cargS(); //AGREGARA UNPEQUEÑO TIEMPO DE ESPERA ANTES DE LA SIGUIENTE PESTAÑA

        do{ //NUEVO CICLO PARA CONFIRMAR GUARDADO DE DATOS
            marco();
            gotoxy(6,5);
            printf("<<CAPTURA DE DATOS>>\n\tDATOS A CAPTURAR:\t\tDATOS PERSONALES:");
            for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
                gotoxy(30,i);
                printf("|");
            }
            gotoxy(30,4);
            printf("O");
            gotoxy(30,28);
            printf("O");
            gotoxy(6,6);
            printf("\n\n\tNOMBRE:\n\n\tDOMICILIO:\n\n\tFRACCIONAMIENTO:\n\n\tCIUDAD:\n\n\tTELEFONO:\n\n\tEMAIL:\n\n\tESTADO CIVIL:\n\n\tFECHA DE NACIMIENTO:\n\n\tCODIGO POSTAL:\n\n\tEDAD:");
            gotoxy(6,6);
            { //LINEAS DE TEXTO Y CAPTURA
                fflush(stdin);
                gotoxy(32,6);
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                gotoxy(32,8); gets(dat[x].Per.nom); fflush(stdin);
                gotoxy(32,10); gets(dat[x].Per.dom); fflush(stdin);
                gotoxy(32,12); gets(dat[x].Per.fra); fflush(stdin);                gotoxy(32,14); gets(dat[x].Per.ciu); fflush(stdin);
                gotoxy(32,16); gets(dat[x].Per.tel); fflush(stdin);
                gotoxy(32,18); gets(dat[x].Per.ema); fflush(stdin);
                gotoxy(32,20); gets(dat[x].Per.est); fflush(stdin);
                gotoxy(32,22); gets(dat[x].Per.nac); fflush(stdin);
                gotoxy(32,24); scanf("%i", &dat[x].Per.cp); fflush(stdin);                gotoxy(32,26); scanf("%i", &dat[x].Per.edad); fflush(stdin);
            }
            gotoxy(90,27);
            cargS();
            do{ //CICLO PARA COMPROBAR QUE EL DATO GUARDADO ES CORRECTO Y QUE EL NUMERO SEA VALIDO
                marco();
                gotoxy(6,5);
                printf("<<CAPTURA DE DATOS>>\n\tDATOS A CAPTURAR:\t\tDATOS PERSONALES:");
                for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
                    gotoxy(30,i);
                    printf("|");
                }
                gotoxy(30,4);
                printf("O");
                gotoxy(30,28);
                printf("O");
                gotoxy(6,6);
                printf("\n\n\tNOMBRE:\n\n\tDOMICILIO:\n\n\tFRACCIONAMIENTO:\n\n\tCIUDAD:\n\n\tTELEFONO:\n\n\tEMAIL:\n\n\tESTADO CIVIL:\n\n\tFECHA DE NACIMIENTO:\n\n\tCODIGO POSTAL:\n\n\tEDAD:");
                gotoxy(6,6);
                { //IMPRIMIRA LOS DATOS Y PREGUNTARA SI QUIERE CORREGIRLOS
                    fflush(stdin);
                    gotoxy(32,6);
                    printf("\n\n\t\t\t\t%s", dat[x].Per.nom);
                    printf("\n\n\t\t\t\t%s", dat[x].Per.dom);
                    printf("\n\n\t\t\t\t%s", dat[x].Per.fra);
                    printf("\n\n\t\t\t\t%s", dat[x].Per.ciu);
                    printf("\n\n\t\t\t\t%s", dat[x].Per.tel);
                    printf("\n\n\t\t\t\t%s", dat[x].Per.ema);
                    printf("\n\n\t\t\t\t%s", dat[x].Per.est);
                    printf("\n\n\t\t\t\t%s", dat[x].Per.nac);
                    printf("\n\n\t\t\t\t%i", dat[x].Per.cp);
                    printf("\n\n\t\t\t\t%i", dat[x].Per.edad);
                }
                gotoxy(60,24);
                printf("¿LOS DATOS GUARDADOS SON CORRECTOS?");
                gotoxy(60,25);
                printf("\t1.SI\t2.NO");
                gotoxy(60,26);
                printf("\tRESPUESTA: ");
                scanf("%i", &r);
                if(r < 1 || r > 2){
                    gotoxy(55,24);
                    printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                    gotoxy(60,25);
                    printf("PULSE <ENTER> PARA CONTINUAR...");
                    gotoxy(60,26);
                    printf("                             ");
                    getch();
                }else{
                    if(r == 1){ //Salir de ambos ciclos (Se selcciona el numero 1)
                        r2++;
                        r3++;
                    }else{      //Volver a guardar los datos
                        r3++;
                    }
                }
            }while(r3 < 1);
        }while(r2 < 1);
        do{ //NUEVO CICLO PARA CONFIRMAR GUARDADO DE DATOS
            marco();
            gotoxy(6,5);
            printf("<<CAPTURA DE DATOS>>\n\tDATOS A CAPTURAR:\t\tDATOS ACADEMICOS:");
            for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
                gotoxy(30,i);
                printf("|");
            }
            gotoxy(30,4);
            printf("O");
            gotoxy(30,28);
            printf("O");
            gotoxy(6,6);
            printf("\n\n\tNOMBRE:\n\n\tCARRERA:\n\n\tPROFESOR:\n\n\tMATERIA:\n\n\tHORARIO:\n\n\tCENTRO UNIVERSITARIO:\n\n\tDIAS DE ASISTENCIA:\n\n\tEDAD:\n\n\tGRADO O SEMESTRE:\n\n\tCANTIDAD DE DIAS:");
            gotoxy(6,6);
            char nom[50], car[50], pro[50], mat[50], hor[10], cun[30]/*Centro univercitario*/, dias[100];
            int edad, grad, cdias;
            { //LINEAS DE TEXTO Y CAPTURA
                fflush(stdin);
                gotoxy(32,6);
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                printf("\n\n\t\t\t\t__________________________________________________________________________________");
                gotoxy(32,8); gets(dat[x].Aca.nom); fflush(stdin);
                gotoxy(32,10); gets(dat[x].Aca.car); fflush(stdin);
                gotoxy(32,12); gets(dat[x].Aca.pro); fflush(stdin);
                gotoxy(32,14); gets(dat[x].Aca.mat); fflush(stdin);
                gotoxy(32,16); gets(dat[x].Aca.hor); fflush(stdin);
                gotoxy(32,18); gets(dat[x].Aca.cun); fflush(stdin);
                gotoxy(32,20); gets(dat[x].Aca.dias); fflush(stdin);
                gotoxy(32,22); scanf("%i", &dat[x].Aca.edad); fflush(stdin);
                gotoxy(32,24); scanf("%i", &dat[x].Aca.grad); fflush(stdin);
                gotoxy(32,26); scanf("%i", &dat[x].Aca.cdias); fflush(stdin);
            }
            gotoxy(90,27);
            cargS();
            r2=0;
            r3=0;
            do{ //CICLO PARA COMPROBAR QUE EL DATO GUARDADO ES CORRECTO Y QUE EL NUMERO SEA VALIDO
                marco();
                gotoxy(6,5);
                printf("<<CAPTURA DE DATOS>>\n\tDATOS A CAPTURAR:\t\tDATOS ACADEMICOS:");
                for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
                    gotoxy(30,i);
                    printf("|");
                }
                gotoxy(30,4);
                printf("O");
                gotoxy(30,28);
                printf("O");
                gotoxy(6,6);
                printf("\n\n\tNOMBRE:\n\n\tCARRERA:\n\n\tPROFESOR:\n\n\tMATERIA:\n\n\tHORARIO:\n\n\tCENTRO UNIVERSITARIO:\n\n\tDIAS DE ASISTENCIA:\n\n\tEDAD:\n\n\tGRADO O SEMESTRE:\n\n\tCANTIDAD DE DIAS:");
                gotoxy(6,6);
                { //IMPRIMIRA LOS DATOS Y PREGUNTARA SI QUIERE CORREGIRLOS
                    fflush(stdin);
                    gotoxy(32,6);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.nom);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.car);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.pro);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.mat);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.hor);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.cun);
                    printf("\n\n\t\t\t\t%s", dat[x].Aca.dias);
                    printf("\n\n\t\t\t\t%i", dat[x].Aca.edad);
                    printf("\n\n\t\t\t\t%i", dat[x].Aca.grad);
                    printf("\n\n\t\t\t\t%i", dat[x].Aca.cdias);
                }
                gotoxy(60,24);
                printf("¿LOS DATOS GUARDADOS SON CORRECTOS?");
                gotoxy(60,25);
                printf("\t1.SI\t2.NO");
                gotoxy(60,26);
                printf("\tRESPUESTA: ");
                scanf("%i", &r);
                if(r < 1 || r > 2){
                    gotoxy(55,24);
                    printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                    gotoxy(60,25);
                    printf("PULSE <ENTER> PARA CONTINUAR...");
                    gotoxy(60,26);
                    printf("                             ");
                    getch();
                }else{
                    if(r == 1){ //Salir de ambos ciclos (Se selcciona el numero 1)
                        r2++;
                        r3++;
                    }else{      //Volver a guardar los datos
                        r3++;
                    }
                }
            }while(r3 < 1);
        }while(r2 < 1);
        gotoxy(60,26);
        printf("                             ");
        gotoxy(60,26);
        cargS();
    }
}

void cargS(){
    printf("CARGANDO.");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
}

void marco(){ //APARTADO DEDICADO A GENERAR EL MARCO
    int i;
    system("cls");
    gotoxy(6,2);
    printf("\t\t\t\tSISTEMA DE COMPILACION DE DATOS");
    for(i=1;i<29;i++){ //LINEA VERTICAL IZQUIERDA
            gotoxy(3,i);
            printf("|");            //printf("%c",219);
    }
    for(i=4;i<115;i++){ //LINEA HORIZONTAL ALTA
          gotoxy(i,1);
          printf("-");
          //printf("%c",223);
    }
    for(i=4;i<115;i++){ //LINEA HORIZONTAL MEDIA
          gotoxy(i,4);
          printf("-");
          //printf("%c",223);
    }
    for(i=1;i<29;i++){ //LINEA VERTICAL DERECHA
          gotoxy(115,i);
          printf("|");
          //printf("%c",219);
    }
    for(i=4;i<115;i++){ //LINEA HORIZONTAL BAJA
          gotoxy(i,28);
          printf("-");          //printf("%c",220);
    }
    gotoxy(3,1);
    printf("O");
    gotoxy(115,1);
    printf("O");
    gotoxy(3,4);
    printf("O");
    gotoxy(115,4);
    printf("O");
    gotoxy(115,28);
    printf("O");
    gotoxy(3,28);
    printf("O");
}

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void color(){
    int r, r2=0;

    do{
        marco();
        gotoxy(6,6);
        printf("\t<<SELECCION DE COLOR>>");
        gotoxy(6,8);
        printf("SELECCIONE UN COLOR:");
        gotoxy(8,10);
        printf("1.VERDE CON MORADO\n\t2.AGUAMARINA CLARO CON GRIS\n\t3.ROJO CLARO CON BLANCO\n\t4.PURPURA CLARO CON AMARILLO\n\t5.AMARILLO CLARO CON ROJO\n\t6.BLANCO BRILLANTE CON VERDE\n\t7.BLANCO CON NEGRO\n\t8.POR DEFECTO\n\t9.CANCELAR");
        gotoxy(6,20);
        printf("RESPUESTA: ");
        scanf("%i", &r);
        if(r < 1 || r > 9){
            gotoxy(6,22);
            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            gotoxy(6,24);
            printf("PULSE <ENTER> PARA CONTINUAR...");
            getch();
        }else
            gotoxy(6,22);
            switch(r){
            case 1: cargS(); system("color 5A"); r2++; break;
            case 2: cargS(); system("color 8B"); r2++; break;
            case 3: cargS(); system("color 7C"); r2++; break;
            case 4: cargS(); system("color 6D"); r2++; break;
            case 5: cargS(); system("color 4E"); r2++; break;
            case 6: cargS(); system("color 2F"); r2++; break;
            case 7: cargS(); system("color 0F"); r2++; break;
            case 8: cargS(); system("color _"); r2++; break;
            case 9: cargS(); r2++; break;
        }
    }while(r2 < 1);
    r2=0;
}

void modificar(){
    int i, x, r, r2=0, r3=0;
    do{ // MENU DE SELECCION DE RANURA DE ALMACENAMIENTO
        marco();
        gotoxy(6,5);
        printf("<<MODIFICAR DATOS>>\n\n\tMODIFICAR LA POSICION:\n\n\tSELECCIONE UNA POSICION ENTRE 1 Y 10\n\n\tSELECCIONE 11 PARA SALIR...\n\n\tPOSICION: ");
        scanf("%i", &r);        //GUARDA Y COMPRUEBA QUE EL DATO ES VALIDO
        if(r < 1 || r > 11){    //DE LO CONTRARIO VOLVERA A EJECUTARSE
            printf("\n\n\tNUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            printf("\n\tPULSE <ENTER> PARA CONTINUAR...");
            getch();
        }else{
            x = r-1;
            r2++; //CIERRA EL CICLO DO Y PASA A LA SIGUIENTE PESTAÑA
        }
    }while(r2 < 1);
    r2=0;
    if(r!=11){
        gotoxy(6,15);
        cargS(); //AGREGARA UNPEQUEÑO TIEMPO DE ESPERA ANTES DE LA SIGUIENTE PESTAÑA

        do{ //CICLO PARA COMPROBAR QUE EL DATO GUARDADO ES CORRECTO Y QUE EL NUMERO SEA VALIDO
            marco();
            gotoxy(6,5);
            printf("<<MODIFICAR DATOS>>\n\tDATOS A MODIFICAR:\t\tDATOS PERSONALES:");
            for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
                gotoxy(30,i);
                printf("|");
            }
            gotoxy(30,4);
            printf("O");
            gotoxy(30,28);
            printf("O");
            gotoxy(6,6);
            printf("\n\n\tNOMBRE:\n\n\tDOMICIOLIO:\n\n\tFRACCIONAMIENTO:\n\n\tCIUDAD:\n\n\tTELEFONO:\n\n\tEMAIL:\n\n\tESTADO CIVIL:\n\n\tFECHA DE NACIMIENTO:\n\n\tCODIGO POSTAL:\n\n\tEDAD:");
            gotoxy(6,6);
            { //IMPRIMIRA LOS DATOS Y PREGUNTARA SI QUIERE CORREGIRLOS
                fflush(stdin);
                gotoxy(32,6);
                printf("\n\n\t\t\t\t1: %s", dat[x].Per.nom);
                printf("\n\n\t\t\t\t2: %s", dat[x].Per.dom);
                printf("\n\n\t\t\t\t3: %s", dat[x].Per.fra);
                printf("\n\n\t\t\t\t4: %s", dat[x].Per.ciu);
                printf("\n\n\t\t\t\t5: %s", dat[x].Per.tel);
                printf("\n\n\t\t\t\t6: %s", dat[x].Per.ema);
                printf("\n\n\t\t\t\t7: %s", dat[x].Per.est);
                printf("\n\n\t\t\t\t8: %s", dat[x].Per.nac);
                printf("\n\n\t\t\t\t9: %i", dat[x].Per.cp);
                printf("\n\n\t\t\t\t10: %i", dat[x].Per.edad);
            }
            gotoxy(60,24);
            printf("¿DESEA MODIFICAR ALGUN DATO?");
            gotoxy(60,25);
            printf("\t1.SI\t2.NO");
            gotoxy(60,26);
            printf("\tRESPUESTA: ");
            scanf("%i", &r);
            if(r < 1 || r > 2){
                gotoxy(55,24);
                printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                gotoxy(60,25);
                printf("PULSE <ENTER> PARA CONTINUAR...");
                gotoxy(60,26);
                printf("                             ");
                getch();
            }else{
                if(r == 1){ //Salir de ambos ciclos (Se selcciona el numero 1)
                    modper(x);
                }else{
                    r3++;
                }
            }
        }while(r3 < 1);

        gotoxy(80,26);
        cargS(); //AGREGARA UNPEQUEÑO TIEMPO DE ESPERA ANTES DE LA SIGUIENTE PESTAÑA
        r2=0; r3=0;
        do{ //CICLO PARA COMPROBAR QUE EL DATO GUARDADO ES CORRECTO Y QUE EL NUMERO SEA VALIDO
            marco();
            gotoxy(6,5);
            printf("<<MODIFICAR DATOS>>\n\tDATOS A MODIFICAR:\t\tDATOS ACADEMICOS:");
            for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
                gotoxy(30,i);
                printf("|");
            }
            gotoxy(30,4);
            printf("O");
            gotoxy(30,28);
            printf("O");
            gotoxy(6,6);
            printf("\n\n\tNOMBRE:\n\n\tCARRERA:\n\n\tPROFESOR:\n\n\tMATERIA:\n\n\tHORARIO:\n\n\tCENTRO UNIVERSITARIO:\n\n\tDIAS DE ASISTENCIA:\n\n\tEDAD:\n\n\tGRADO O SEMESTRE:\n\n\tCANTIDAD DE DIAS:");
            gotoxy(6,6);
            { //IMPRIMIRA LOS DATOS Y PREGUNTARA SI QUIERE CORREGIRLOS
                fflush(stdin);
                gotoxy(32,6);
                printf("\n\n\t\t\t\t1: %s", dat[x].Aca.nom);
                printf("\n\n\t\t\t\t2: %s", dat[x].Aca.car);
                printf("\n\n\t\t\t\t3: %s", dat[x].Aca.pro);
                printf("\n\n\t\t\t\t4: %s", dat[x].Aca.mat);
                printf("\n\n\t\t\t\t5: %s", dat[x].Aca.hor);
                printf("\n\n\t\t\t\t6: %s", dat[x].Aca.cun);
                printf("\n\n\t\t\t\t7: %s", dat[x].Aca.dias);
                printf("\n\n\t\t\t\t8: %i", dat[x].Aca.edad);
                printf("\n\n\t\t\t\t9: %i", dat[x].Aca.grad);
                printf("\n\n\t\t\t\t10: %i", dat[x].Aca.cdias);
            }
            gotoxy(60,24);
            printf("¿DESEA MODIFICAR ALGUN DATO?");
            gotoxy(60,25);
            printf("\t1.SI\t2.NO");
            gotoxy(60,26);
            printf("\tRESPUESTA: ");
            scanf("%i", &r);
            if(r < 1 || r > 2){
                gotoxy(55,24);
                printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                gotoxy(60,25);
                printf("PULSE <ENTER> PARA CONTINUAR...");
                gotoxy(60,26);
                printf("                             ");
                getch();
            }else{
                if(r == 1){ //Salir de ambos ciclos (Se selcciona el numero 1)
                    modaca(x);
                }else{
                    r3++;
                }
            }
        }while(r3 < 1);
        gotoxy(80,26);
        cargS();
    }
}

int modper(int x){
    int r, r2=0;
    do{
        gotoxy(55,24); //ESTO BORRARA EL TEXTO ANTERIOR
        printf("                                                            ");
        gotoxy(60,25);
        printf("                                ");
        gotoxy(60,26);
        printf("                             ");
        gotoxy(60,24);
        printf("¿QUE DATO DESEA MODIFICAR?");
        gotoxy(60,25);
        printf("SELECCIONE UNO ENTRE 1 Y 10");
        gotoxy(60,26);
        printf("\tRESPUESTA: ");
        scanf("%i", &r);
        if(r < 1 || r > 10){
            gotoxy(55,24);
            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            gotoxy(60,25);
            printf("PULSE <ENTER> PARA CONTINUAR...");
            gotoxy(60,26);
            printf("                             ");
            getch();
        }else{
            fflush(stdin);
            gotoxy(55,24); //ESTO BORRARA EL TEXTO ANTERIOR
            printf("                                                            ");
            gotoxy(60,25);
            printf("                                ");
            gotoxy(60,26);
            printf("                             ");
            switch(r){
                case 1: gotoxy(35,8); printf("_______________________________________________________________________________"); gotoxy(35,8); gets(dat[x].Per.nom); fflush(stdin); break;
                case 2: gotoxy(35,10); printf("_______________________________________________________________________________"); gotoxy(35,10); gets(dat[x].Per.dom); fflush(stdin); break;
                case 3: gotoxy(35,12); printf("_______________________________________________________________________________"); gotoxy(35,12); gets(dat[x].Per.fra); fflush(stdin); break;
                case 4: gotoxy(35,14); printf("_______________________________________________________________________________"); gotoxy(35,14); gets(dat[x].Per.ciu); fflush(stdin); break;
                case 5: gotoxy(35,16); printf("_______________________________________________________________________________"); gotoxy(35,16); gets(dat[x].Per.tel); fflush(stdin); break;
                case 6: gotoxy(35,18); printf("_______________________________________________________________________________"); gotoxy(35,18); gets(dat[x].Per.ema); fflush(stdin); break;
                case 7: gotoxy(35,20); printf("_______________________________________________________________________________"); gotoxy(35,20); gets(dat[x].Per.est); fflush(stdin); break;
                case 8: gotoxy(35,22); printf("_______________________________________________________________________________"); gotoxy(35,22); gets(dat[x].Per.nac); fflush(stdin); break;
                case 9: gotoxy(35,24); printf("_______________________________________________________________________________"); gotoxy(35,24); scanf("%i", &dat[x].Per.cp); fflush(stdin); break;
                case 10: gotoxy(36,26); printf("______________________________________________________________________________"); gotoxy(36,26); scanf("%i", &dat[x].Per.edad); fflush(stdin); break;
            }
            r2++;
        }
    }while(r2 < 1);
}

int modaca(int x){
    int r, r2=0;
    do{
        gotoxy(55,24); //ESTO BORRARA EL TEXTO ANTERIOR
        printf("                                                            ");
        gotoxy(60,25);
        printf("                                ");
        gotoxy(60,26);
        printf("                             ");
        gotoxy(60,24);
        printf("¿QUE DATO DESEA MODIFICAR?");
        gotoxy(60,25);
        printf("SELECCIONE UNO ENTRE 1 Y 10");
        gotoxy(60,26);
        printf("\tRESPUESTA: ");
        scanf("%i", &r);
        if(r < 1 || r > 10){
            gotoxy(55,24);
            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            gotoxy(60,25);
            printf("PULSE <ENTER> PARA CONTINUAR...");
            gotoxy(60,26);
            printf("                             ");
            getch();
        }else{
            fflush(stdin);
            gotoxy(55,24); //ESTO BORRARA EL TEXTO ANTERIOR
            printf("                                                            ");
            gotoxy(60,25);
            printf("                                ");
            gotoxy(60,26);
            printf("                             ");
            switch(r){
                case 1: gotoxy(35,8); printf("_______________________________________________________________________________"); gotoxy(35,8); gets(dat[x].Aca.nom); fflush(stdin); break;
                case 2: gotoxy(35,10); printf("_______________________________________________________________________________"); gotoxy(35,10); gets(dat[x].Aca.car); fflush(stdin); break;
                case 3: gotoxy(35,12); printf("_______________________________________________________________________________"); gotoxy(35,12); gets(dat[x].Aca.pro); fflush(stdin); break;
                case 4: gotoxy(35,14); printf("_______________________________________________________________________________"); gotoxy(35,14); gets(dat[x].Aca.mat); fflush(stdin); break;
                case 5: gotoxy(35,16); printf("_______________________________________________________________________________"); gotoxy(35,16); gets(dat[x].Aca.hor); fflush(stdin); break;
                case 6: gotoxy(35,18); printf("_______________________________________________________________________________"); gotoxy(35,18); gets(dat[x].Aca.cun); fflush(stdin); break;
                case 7: gotoxy(35,20); printf("_______________________________________________________________________________"); gotoxy(35,20); gets(dat[x].Aca.dias); fflush(stdin); break;
                case 8: gotoxy(35,22); printf("_______________________________________________________________________________"); gotoxy(35,22); scanf("%i", &dat[x].Aca.edad); fflush(stdin); break;
                case 9: gotoxy(35,24); printf("_______________________________________________________________________________"); gotoxy(35,24); scanf("%i", &dat[x].Aca.grad); fflush(stdin); break;
                case 10: gotoxy(36,26); printf("______________________________________________________________________________"); gotoxy(36,26); scanf("%i", &dat[x].Aca.cdias); fflush(stdin); break;
            }
            r2++;
        }
    }while(r2 < 1);
}

void buscar(){
    int x, r, r2=0, i=0;
    do{
        marco();
        gotoxy(6,5);
        printf("<<BUSCAR DATOS>>\n\n\tDESEA BUSCAR:\n\n\t1.DATOS PERSONALES\n\n\t2.DATOS ACADEMICOS\n\n\t3.SALIR\n\n\tRESPUESTA: ");
        scanf("%i", &r);
        if(r < 1 || r > 3){
            printf("\n\n\tNUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            printf("\n\tPULSE <ENTER> PARA CONTINUAR...");
            getch();
        }else if(r == 3){
            r2++;
            gotoxy(6,17);
            cargS();
        }else{
            gotoxy(6,17);
            cargS();
            switch(r){
            case 1: busper(); break;
            case 2: busaca(); break;
            }
            r2++;
        }
    }while(r2 < 1);
}

void busper(){
    int r, r3=0, r2=0, res[10], i=0, x=0, res2;
    char txt100[100], txt50[50], txt30[30], txt20[20], txt10[10];
    do{
        marco();
        for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
            gotoxy(30,i);
            printf("|");
        }
        gotoxy(30,4);
        printf("O");
        gotoxy(30,28);
        printf("O");
        gotoxy(6,5);
        i = 0;
        x = 0;
        r = 0;
        printf("<<BUSQUEDA DE DATOS>>\n\tDATOS A BUSCAR:");
        printf("\n\n\t1. NOMBRE\n\n\t2. DOMICILIO\n\n\t3. FRACCIONAMIENTO\n\n\t4. CIUDAD\n\n\t5. TELEFONO\n\n\t6. EMAIL\n\n\t7. ESTADO CIVIL\n\n\t8. FECHA DE NACIMIENTO\n\n\t9. CODIGO POSTAL\n\n\t10. EDAD");
        gotoxy(40,26);
        printf("¿QUE DATOS DESEA BUSCAR? RESPUESTA: ");
        scanf("%i", &r);
        if(r < 1 || r > 10){
            gotoxy(40,26);
            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            gotoxy(40,27);
            printf("PULSE <ENTER> PARA CONTINUAR...");
            getch();
        }else{
            switch(r){
                case 1:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,8);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,8);
                    fflush(stdin);
                    gets(txt50);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt50, dat[x].Per.nom);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,8);
                    printf("                                                                                  ");
                    gotoxy(32,8);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,9);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,9);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,8);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,9);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,8);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,9);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 2:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,10);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,10);
                    fflush(stdin);
                    gets(txt100);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt100, dat[x].Per.dom);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,10);
                    printf("                                                                                  ");
                    gotoxy(32,10);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,11);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,11);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,10);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,11);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,10);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,11);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 3:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,12);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,12);
                    fflush(stdin);
                    gets(txt20);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt20, dat[x].Per.fra);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,12);
                    printf("                                                                                  ");
                    gotoxy(32,12);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,13);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,13);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,12);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,13);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,12);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,13);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 4:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,14);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,14);
                    fflush(stdin);
                    gets(txt20);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt20, dat[x].Per.ciu);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,14);
                    printf("                                                                                  ");
                    gotoxy(32,14);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,15);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,15);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,14);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,15);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,14);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,15);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 5:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,16);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,16);
                    fflush(stdin);
                    gets(txt20);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt20, dat[x].Per.tel);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,16);
                    printf("                                                                                  ");
                    gotoxy(32,16);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,17);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,17);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,16);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,17);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,16);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,17);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 6:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,18);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,18);
                    fflush(stdin);
                    gets(txt50);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt50, dat[x].Per.ema);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,18);
                    printf("                                                                                  ");
                    gotoxy(32,18);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,19);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,19);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,18);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,19);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,18);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,19);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 7:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,20);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,20);
                    fflush(stdin);
                    gets(txt10);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt10, dat[x].Per.est);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,20);
                    printf("                                                                                  ");
                    gotoxy(32,20);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,21);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,21);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,20);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,21);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,20);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,21);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 8:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,22);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,22);
                    fflush(stdin);
                    gets(txt30);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt30, dat[x].Per.nac);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,22);
                    printf("                                                                                  ");
                    gotoxy(32,22);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,23);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,23);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,22);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,23);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,22);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,23);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 9:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,24);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,24);
                    scanf("%i", &res2);
                    for(x=0;x<10;x++){
                        if(res2 == dat[x].Per.cp){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,24);
                    printf("                                                                                  ");
                    gotoxy(32,24);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,25);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,25);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,24);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,25);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,24);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,25);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 10:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,26);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,26);
                    scanf("%i", &res2);
                    for(x=0;x<10;x++){
                        if(res2 == dat[x].Per.edad){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,26);
                    printf("                                                                                  ");
                    gotoxy(32,26);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,27);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,27);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,26);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,27);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,26);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,27);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
            }
            gotoxy(95,27);
            cargS();
        }
    }while(r2 < 1);
}

void busaca(){
    int r, r3=0, r2=0, res[10], i=0, x=0, res2;
    char txt100[100], txt50[50], txt30[30], txt20[20], txt10[10];
    do{
        marco();
        for(i=4;i<29;i++){ //POSICIONA UNA BARRA VERTICAL
            gotoxy(30,i);
            printf("|");
        }
        gotoxy(30,4);
        printf("O");
        gotoxy(30,28);
        printf("O");
        gotoxy(6,5);
        i = 0;
        x = 0;
        r = 0;
        printf("<<BUSQUEDA DE DATOS>>\n\tDATOS A BUSCAR:");
        printf("\n\n\t1.NOMBR:\n\n\t2.CARRERA\n\n\t3.PROFESOR\n\n\t4.MATERIA\n\n\t5.HORARIO\n\n\t6.CENTRO UNIVERSITARIO\n\n\t7.DIAS DE ASISTENCIA\n\n\t8.EDAD\n\n\t9.GRADO O SEMESTRE\n\n\t10.CANTIDAD DE DIAS");
        gotoxy(40,26);
        printf("¿QUE DATOS DESEA BUSCAR? RESPUESTA: ");
        scanf("%i", &r);
        if(r < 1 || r > 10){
            gotoxy(40,26);
            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
            gotoxy(40,27);
            printf("PULSE <ENTER> PARA CONTINUAR...");
            getch();
        }else{
            switch(r){
                case 1:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,8);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,8);
                    fflush(stdin);
                    gets(txt50);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt50, dat[x].Aca.nom);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,8);
                    printf("                                                                                  ");
                    gotoxy(32,8);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,9);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,9);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,8);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,9);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,8);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,9);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 2:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,10);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,10);
                    fflush(stdin);
                    gets(txt50);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt50, dat[x].Aca.car);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,10);
                    printf("                                                                                  ");
                    gotoxy(32,10);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,11);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,11);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,10);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,11);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,10);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,11);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 3:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,12);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,12);
                    fflush(stdin);
                    gets(txt50);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt50, dat[x].Aca.pro);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,12);
                    printf("                                                                                  ");
                    gotoxy(32,12);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,13);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,13);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,12);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,13);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,12);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,13);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 4:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,14);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,14);
                    fflush(stdin);
                    gets(txt50);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt50, dat[x].Aca.mat);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,14);
                    printf("                                                                                  ");
                    gotoxy(32,14);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,15);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,15);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,14);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,15);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,14);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,15);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 5:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,16);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,16);
                    fflush(stdin);
                    gets(txt10);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt10, dat[x].Aca.hor);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,16);
                    printf("                                                                                  ");
                    gotoxy(32,16);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,17);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,17);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,16);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,17);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,16);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,17);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 6:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,18);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,18);
                    fflush(stdin);
                    gets(txt100);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt100, dat[x].Aca.cun);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,18);
                    printf("                                                                                  ");
                    gotoxy(32,18);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,19);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,19);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,18);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,19);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,18);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,19);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 7:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,20);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,20);
                    fflush(stdin);
                    gets(txt100);
                    fflush(stdin);
                    for(x=0;x<10;x++){
                        res2 = strcasecmp(txt100, dat[x].Aca.dias);
                        if(res2 == 0){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,20);
                    printf("                                                                                  ");
                    gotoxy(32,20);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,21);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,21);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,20);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,21);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,20);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,21);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 8:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,22);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,22);
                    scanf("%i", &res2);
                    for(x=0;x<10;x++){
                        if(res2 == dat[x].Aca.edad){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,22);
                    printf("                                                                                  ");
                    gotoxy(32,22);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,23);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,23);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,22);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,23);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,22);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,23);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 9:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,24);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,24);
                    scanf("%i", &res2);
                    for(x=0;x<10;x++){
                        if(res2 == dat[x].Aca.grad){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,24);
                    printf("                                                                                  ");
                    gotoxy(32,24);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,25);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,25);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,24);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,25);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,24);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,25);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
                case 10:{
                    gotoxy(40,26);
                    printf("                                                    ");
                    gotoxy(32,26);
                    printf("__________________________________________________________________________________");
                    gotoxy(32,26);
                    scanf("%i", &res2);
                    for(x=0;x<10;x++){
                        if(res2 == dat[x].Aca.cdias){
                            res[i] = x+1;
                            i++;
                        }
                    }
                    gotoxy(32,26);
                    printf("                                                                                  ");
                    gotoxy(32,26);
                    if(i != 0){
                        printf("SE ENCONTRARON COINCIDENCIAS EN LOS ARCHIVOS:");
                        for(x=0;x<i;x++){
                            printf(" %i", res[x]);
                        }
                        printf(".");
                        gotoxy(32,27);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }else{
                        printf("NO SE ENCONTRARON COINCIDENCIAS.");
                        gotoxy(32,27);
                        printf("PULSE <ENTER> PARA CONTINUAR...");
                        getch();
                    }
                    do{
                        gotoxy(32,26);
                        printf("¿DESEA BUSCAR NUEVAMENTE?                                  ");
                        gotoxy(32,27);
                        printf("1.SI 2.NO           RESPUESTA: ");
                        scanf("%i", &r);
                        if(r < 1 || r > 2){
                            gotoxy(32,26);
                            printf("NUMERO NO VALIDO, INTENTE DE NUEVO DIGITANDO UNO DISTINTO.");
                            gotoxy(32,27);
                            printf("PULSE <ENTER> PARA CONTINUAR...  ");
                            getch();
                        }else{
                            r3++;
                            if(r == 2){
                                r2++;
                            }
                        }
                    }while(r3 < 1);
                }break;
            }
            gotoxy(95,27);
            cargS();
        }
    }while(r2 < 1);
}

void entr2(){
    marco();
    entr();
    entr();
    entr();
    pant();
    marco();
    entr();
    entr();
    entr();
}

void sal(){
    marco();
    entr();
    entr();
    entr();
    entr();
}

void entr(){
    gotoxy(6,4);
    img1();
    Sleep(100);
    gotoxy(6,4);
    img2();
    Sleep(100);
    gotoxy(6,4);
    img3();
    Sleep(100);
    gotoxy(6,4);
    img4();
    Sleep(100);
    gotoxy(6,4);
    img5();
    Sleep(100);
    gotoxy(6,4);
    img1();
    Sleep(500);
}

void img1(){
    printf("\n\t\t\t                                                      ");
    printf("\n\t\t\t                                                      ");
    printf("\n\t\t\t                                                      ");
    printf("\n\t\t\t                                                      ");
    printf("\n\t\t\t                                                      ");
    printf("\n\t\t\t              ########          ########              ");
    printf("\n\t\t\t        ######        ##      ##        ######        ");
    printf("\n\t\t\t########                ######                ########");
    printf("\n\t\t\t####                                              ####");
    printf("\n\t\t\t##                        ##                        ##");
    printf("\n\t\t\t##                        ##                        ##");
    printf("\n\t\t\t##                        ##                        ##");
    printf("\n\t\t\t##                                                  ##");
    printf("\n\t\t\t##                        ##                        ##");
    printf("\n\t\t\t##                        ##                        ##");
    printf("\n\t\t\t##                        ##                        ##");
    printf("\n\t\t\t##                                                  ##");
    printf("\n\t\t\t##                        ##                        ##");
    printf("\n\t\t\t##            ########    ##    ########            ##");
    printf("\n\t\t\t##      ######        ##      ##        ######      ##");
    printf("\n\t\t\t##  ####                ######                ####  ##");
    printf("\n\t\t\t####        ############      ############        ####");
    printf("\n\t\t\t############            ######            ############      CARGANDO.....");
}

void img2(){
    printf("\n\t\t\t                                                      ");
    printf("\n\t\t\t                                                      ");
    printf("\n\t\t\t                                      ######          ");
    printf("\n\t\t\t                                    ##      ##        ");
    printf("\n\t\t\t                                  ##        ##        ");
    printf("\n\t\t\t              ########          ##          ##        ");
    printf("\n\t\t\t        ######        ##      ##            ##        ");
    printf("\n\t\t\t########                ######              ##########");
    printf("\n\t\t\t####                                        ##    ####");
    printf("\n\t\t\t##                        ##                ##      ##");
    printf("\n\t\t\t##                        ##                ##      ##");
    printf("\n\t\t\t##                        ##                ##      ##");
    printf("\n\t\t\t##                                          ##      ##");
    printf("\n\t\t\t##                        ##                ##      ##");
    printf("\n\t\t\t##                        ##                ##      ##");
    printf("\n\t\t\t##                        ##          ######        ##");
    printf("\n\t\t\t##                                  ##              ##");
    printf("\n\t\t\t##                        ##      ##                ##");
    printf("\n\t\t\t##            ########    ##    ########            ##");
    printf("\n\t\t\t##      ######        ##      ##        ######      ##");
    printf("\n\t\t\t##  ####                ######                ####  ##");
    printf("\n\t\t\t####        ############      ############        ####");
    printf("\n\t\t\t############            ######            ############      CARGANDO.    ");
}

void img3(){
    printf("\n\t\t\t                                ##                    ");
    printf("\n\t\t\t                              ####                    ");
    printf("\n\t\t\t                            ##  ##                    ");
    printf("\n\t\t\t                            ##  ##                    ");
    printf("\n\t\t\t                            ##  ##                    ");
    printf("\n\t\t\t              ########    ##    ########              ");
    printf("\n\t\t\t        ######        ##  ##    ##      ######        ");
    printf("\n\t\t\t########                ####    ##            ########");
    printf("\n\t\t\t####                      ##    ##                ####");
    printf("\n\t\t\t##                        ##    ##                  ##");
    printf("\n\t\t\t##                        ##    ##                  ##");
    printf("\n\t\t\t##                        ##    ##                  ##");
    printf("\n\t\t\t##                        ##    ##                  ##");
    printf("\n\t\t\t##                        ##    ##                  ##");
    printf("\n\t\t\t##                        ##    ##                  ##");
    printf("\n\t\t\t##                        ##    ##                  ##");
    printf("\n\t\t\t##                        ##  ##                    ##");
    printf("\n\t\t\t##                        ####                      ##");
    printf("\n\t\t\t##            ########    ####  ########            ##");
    printf("\n\t\t\t##      ######        ##  ######        ######      ##");
    printf("\n\t\t\t##  ####                ######                ####  ##");
    printf("\n\t\t\t####        ############      ############        ####");
    printf("\n\t\t\t############            ######            ############      CARGANDO..   ");
}

void img4(){
    printf("\n\t\t\t                    ##                                ");
    printf("\n\t\t\t                    ####                              ");
    printf("\n\t\t\t                    ##  ##                            ");
    printf("\n\t\t\t                    ##  ##                            ");
    printf("\n\t\t\t                    ##  ##                            ");
    printf("\n\t\t\t              ########    ##    ########              ");
    printf("\n\t\t\t        ######      ##    ##  ##        ######        ");
    printf("\n\t\t\t########            ##    ####                ########");
    printf("\n\t\t\t####                ##    ##                      ####");
    printf("\n\t\t\t##                  ##    ##                        ##");
    printf("\n\t\t\t##                  ##    ##                        ##");
    printf("\n\t\t\t##                  ##    ##                        ##");
    printf("\n\t\t\t##                  ##    ##                        ##");
    printf("\n\t\t\t##                  ##    ##                        ##");
    printf("\n\t\t\t##                  ##    ##                        ##");
    printf("\n\t\t\t##                  ##    ##                        ##");
    printf("\n\t\t\t##                    ##  ##                        ##");
    printf("\n\t\t\t##                      ####                        ##");
    printf("\n\t\t\t##            ########  ####    ########            ##");
    printf("\n\t\t\t##      ######        ######  ##        ######      ##");
    printf("\n\t\t\t##  ####                ######                ####  ##");
    printf("\n\t\t\t####        ############      ############        ####");
    printf("\n\t\t\t############            ######            ############      CARGANDO...  ");
}

void img5(){
    printf("\n\t\t\t                                                      ");
    printf("\n\t\t\t                                                      ");
    printf("\n\t\t\t          ######                                      ");
    printf("\n\t\t\t        ##      ##                                    ");
    printf("\n\t\t\t        ##        ##                                  ");
    printf("\n\t\t\t        ##          ##          ########              ");
    printf("\n\t\t\t        ##            ##      ##        ######        ");
    printf("\n\t\t\t##########              ######                ########");
    printf("\n\t\t\t####    ##                                        ####");
    printf("\n\t\t\t##      ##                ##                        ##");
    printf("\n\t\t\t##      ##                ##                        ##");
    printf("\n\t\t\t##      ##                ##                        ##");
    printf("\n\t\t\t##      ##                                          ##");
    printf("\n\t\t\t##      ##                ##                        ##");
    printf("\n\t\t\t##      ##                ##                        ##");
    printf("\n\t\t\t##        ######          ##                        ##");
    printf("\n\t\t\t##              ##                                  ##");
    printf("\n\t\t\t##                ##      ##                        ##");
    printf("\n\t\t\t##            ########    ##    ########            ##");
    printf("\n\t\t\t##      ######        ##      ##        ######      ##");
    printf("\n\t\t\t##  ####                ######                ####  ##");
    printf("\n\t\t\t####        ############      ############        ####");
    printf("\n\t\t\t############            ######            ############      CARGANDO.... ");
}

void pant(){
    marco();
    gotoxy(6,6);
    printf("\n\tSISTEMA DE DATOS");
    printf("\n\t##############################################");
    printf("\n\t#AUTOR:      # JUAN DIEGO RODRIGUEZ MACIAS   #");
    printf("\n\t#            #                               #");
    printf("\n\t#VERSION:    # 1.2.5.3                       #");
    printf("\n\t#            #                               #");
    printf("\n\t#FECHA:      # 15 NOVIEMBRE DEL 2023         #");
    printf("\n\t#            #                               #");
    printf("\n\t#DISFRUTEN :)#                               #");
    printf("\n\t#            #                               #");
    printf("\n\t#            #                               #");
    printf("\n\t#            #                               #");
    printf("\n\t#            #                               #");
    printf("\n\t#            #                               #");
    printf("\n\t#            #                               #");    printf("\n\t##############################################");
    gotoxy(95, 27);
    sleep(5);
    cargS();
}
