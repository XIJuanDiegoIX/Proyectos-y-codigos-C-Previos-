#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y);
void carg();
// agregar el siguiente programa para que se pueda trabajar la funcion "gotoxy(x,y)"

 void main()
//Programa Marco()
 {
     int res=1;
     do{
        carg();
        res = rep(res);
     }while(res == 1);
    printf("\n\n\n\n\n\n\n\n");
  return 0;
 }

int rep(int r){
    gotoxy(20, 17);
    printf("Quiere repetir el programa?");
    gotoxy(20, 19);
    printf("1.Si");
    gotoxy(20, 20);
    printf("2.No");
    gotoxy(20, 22);
    scanf("%i", &r);
    return r;
}


void gotoxy(int x, int y){
   HANDLE hCon;
   hCon=GetStdHandle(STD_OUTPUT_HANDLE);
   COORD dwPos;
   dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hCon, dwPos);
  }

 void carg(){

    int i, r;
// revisar los colores con los numeros del 01 al 09.
// el priemr valor es para la coordenada de x y el ssegundo para la coordenada de y - gotoxy(x,y)
    system("COLOR 03");
    system("cls");
    for(i=1;i<29;i++)
  {
       gotoxy(3,i);
       printf("%c",219);
  }
  for(i=4;i<80;i++)
  {
      gotoxy(i,1);
      printf("%c",223);
  }
  for(i=1;i<29;i++)
  {
      gotoxy(80,i);
      printf("%c",219);
  }
  for(i=4;i<80;i++)
  {
      gotoxy(i,28);
      printf("%c",220);
  }

      gotoxy(20,13);
      printf("\a CARGANDO SISTEMA... ");
       gotoxy(20,15);
       for(r=0;r<10;r++){
            printf(" |");
            Sleep(200);
       }

 }
