/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
// agregar el siguiente programa para que se pueda trabajar la funcion "gotoxy(x,y)"
void gotoxy(int x, int y)
{
   HANDLE hCon;
   hCon=GetStdHandle(STD_OUTPUT_HANDLE);
   COORD dwPos;
   dwPos.X = x;
 dwPos.Y = y;
 SetConsoleCursorPosition(hCon, dwPos);
  }

 void main()
//Programa Marco()
 {
    int i;

// revisar los colores con los numeros del 01 al 09.
// el priemr valor es para la coordenada de x y el ssegundo para la coordenada de y - gotoxy(x,y)
    system("COLOR 02");

    for(i=1;i<29;i++)
  {    Sleep(50);
       gotoxy(3,i);
       printf("%c",219);
  }
  for(i=4;i<80;i++)
  {   Sleep(50);
      gotoxy(i,1);
      printf("%c",223);
  }
  for(i=1;i<29;i++)
  {   Sleep(50);
      gotoxy(80,i);
      printf("%c",219);
  }
  for(i=4;i<80;i++)
  {   Sleep(50);

      gotoxy(i,28);
      printf("%c",220);
  }

      gotoxy(20,13);
      printf(" Hola \n\n\n\n \n\n \n\n \n\n \n\n  \n\n \n\n \n\n ");
       gotoxy(20,15);
      printf(" Ejercicio de coordenadas . . . \n\n\n\n \n\n \n\n \n\n \n\n  \n\n \n\n \n\n ");
       gotoxy(20,17);
      printf(" Presione <enter> para salir ... \n\n\n\n \n\n \n\n \n\n \n\n  \n\n \n\n \n\n ");

  return 0;
 }
