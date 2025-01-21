#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void FC10();

int main()
{
    FC10();
    return 0;
}

void FC10(){ //10 4 7 5 2 9 6 3 1 8
    Sleep(1000);
    printf("\nHabia una familia de osos");
    FC4();
}

void FC7(){
    Sleep(1000);
    printf("\nMama por que me llamo 'Copo de nieve'?");
    FC5();
}

void FC9(){
    Sleep(1000);
    printf("\nDespues llega el siguiente hijo y le pregunta");
    FC6();
}

void FC4(){
    Sleep(1000);
    printf("\nEl hijo mayor se acerca con su mama y le dice: ");
    FC7();
}

void FC5(){
    Sleep(1000);
    printf("\nLa mama responde: ");
    Sleep(1000);
    printf("\nCuando eras un bebe te callo un copo de nieve en la nariz,\n asi que te llamamos asi.");
    FC2();
}

void FC6(){
    Sleep(1000);
    printf("\nMama, por que me llamo 'Gotita'?");
    FC3();
}

void FC2(){
    Sleep(1000);
    printf("\nGracias ma");
    FC9();
}

void FC8(){
    Sleep(1000);
    printf("\nY por ultimo llega ladrillo con su mama y pregunta:");
    printf("\n ADgh Ahgd aFgh");
    getch();
}

void FC3(){
    Sleep(1000);
    printf("\nA lo que la mama responde:");
    printf("\nCuando eras bebe te callo una gota de agua en la nariz");
    FC1();
}

void FC1(){
    Sleep(1000);
    printf("\nGracias mama");
    FC8();
}
