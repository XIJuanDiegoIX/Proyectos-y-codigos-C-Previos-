#include <iostream>
#include <windows.h>

using namespace std;

/*
Codigo Go to X Y
*/
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void pantalla(){
    int i;
    gotoxy(4,1);
    for(i=0;i<112;i++){
    cout<<"-";
    }

    gotoxy(4,5);
    for(i=0;i<112;i++){
    cout<<"-";
    }

    gotoxy(4,28);
    for(i=0;i<112;i++){
    cout<<"-";
    }

    for(i=2;i<29;i++){
    gotoxy(4,i);
    cout<<"|";
    }

    for(i=2;i<29;i++){
    gotoxy(115,i);
    cout<<"|";
    }

    gotoxy(4,1); cout<<"o";
    gotoxy(4,5); cout<<"o";
    gotoxy(115,5); cout<<"o";
    gotoxy(115,1); cout<<"o";
    gotoxy(4,28); cout<<"o";
    gotoxy(115,28); cout<<"o";
    gotoxy(115,28); cout<<"o";
    gotoxy(40,3); cout<<"Neveria LA PERLA";
    gotoxy(97,2); cout<<"By Diego & Israel";
    gotoxy(97,4); cout<<"Version: 1.6.5.24";

}

void carga(){
    int x=100;
    gotoxy(0,7);
    cout<<"\t\t\t\t\t                        ######          "<<endl;
    cout<<"\t\t\t\t\t                    ####      ####      "<<endl;
    cout<<"\t\t\t\t\t                  ##              ##    "<<endl;
    cout<<"\t\t\t\t\t                ##    ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##      ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##                      ##"<<endl;
    cout<<"\t\t\t\t\t            ####                      ##"<<endl;
    cout<<"\t\t\t\t\t            ##  ##    ##              ##"<<endl;
    cout<<"\t\t\t\t\t          ##    ##      ##          ##  "<<endl;
    cout<<"\t\t\t\t\t          ##    ####      ####      ##  "<<endl;
    cout<<"\t\t\t\t\t        ##          ####          ##    "<<endl;
    cout<<"\t\t\t\t\t        ##  ##          ##      ##      "<<endl;
    cout<<"\t\t\t\t\t      ##          ##      ######        "<<endl;
    cout<<"\t\t\t\t\t      ##        ##      ####            "<<endl;
    cout<<"\t\t\t\t\t    ##    ####      ####                "<<endl;
    cout<<"\t\t\t\t\t    ##  ##      ####                    "<<endl;
    cout<<"\t\t\t\t\t  ##        ####                        "<<endl;
    cout<<"\t\t\t\t\t  ##    ####                            "<<endl;
    cout<<"\t\t\t\t\t##  ####                                "<<endl;
    cout<<"\t\t\t\t\t####                                                   Cargando     "<<endl;
    pantalla();
    Sleep(x);
    gotoxy(0,7);
    cout<<"\t\t\t\t\t                        ######          "<<endl;
    cout<<"\t\t\t\t\t                    ####      ####      "<<endl;
    cout<<"\t\t\t\t\t                  ##              ##    "<<endl;
    cout<<"\t\t\t\t\t                ##    ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##      ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##                      ##"<<endl;
    cout<<"\t\t\t\t\t            ####                      ##"<<endl;
    cout<<"\t\t\t\t\t            ##  ##    ##              ##"<<endl;
    cout<<"\t\t\t\t\t          ##    ##      ##          ##  "<<endl;
    cout<<"\t\t\t\t\t          ##    ####      ####      ##  "<<endl;
    cout<<"\t\t\t\t\t        ##          ####          ##    "<<endl;
    cout<<"\t\t\t\t\t        ##  ##          ##      ##      "<<endl;
    cout<<"\t\t\t\t\t      ##          ##      ########      "<<endl;
    cout<<"\t\t\t\t\t      ##        ##      ########        "<<endl;
    cout<<"\t\t\t\t\t    ##    ####      ####                "<<endl;
    cout<<"\t\t\t\t\t    ##  ##      ####                    "<<endl;
    cout<<"\t\t\t\t\t  ##        ####                        "<<endl;
    cout<<"\t\t\t\t\t  ##    ####                            "<<endl;
    cout<<"\t\t\t\t\t##  ####                                "<<endl;
    cout<<"\t\t\t\t\t####                                                   Cargando.    "<<endl;
    pantalla();
    Sleep(x);
    gotoxy(0,7);
    cout<<"\t\t\t\t\t                        ######          "<<endl;
    cout<<"\t\t\t\t\t                    ####      ####      "<<endl;
    cout<<"\t\t\t\t\t                  ##              ##    "<<endl;
    cout<<"\t\t\t\t\t                ##    ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##      ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##                      ##"<<endl;
    cout<<"\t\t\t\t\t            ####                      ##"<<endl;
    cout<<"\t\t\t\t\t            ##  ##    ##              ##"<<endl;
    cout<<"\t\t\t\t\t          ##    ##      ##          ##  "<<endl;
    cout<<"\t\t\t\t\t          ##    ####      ####      ##  "<<endl;
    cout<<"\t\t\t\t\t        ##          ####          ##    "<<endl;
    cout<<"\t\t\t\t\t        ##  ##          ##      ##      "<<endl;
    cout<<"\t\t\t\t\t      ##          ##      ######        "<<endl;
    cout<<"\t\t\t\t\t      ##        ##      ########        "<<endl;
    cout<<"\t\t\t\t\t    ##    ####      ####  ####          "<<endl;
    cout<<"\t\t\t\t\t    ##  ##      ####                    "<<endl;
    cout<<"\t\t\t\t\t  ##        ####                        "<<endl;
    cout<<"\t\t\t\t\t  ##    ####                            "<<endl;
    cout<<"\t\t\t\t\t##  ####                                "<<endl;
    cout<<"\t\t\t\t\t####                                                   Cargando..   "<<endl;
    pantalla();
    Sleep(x);
    gotoxy(0,7);
    cout<<"\t\t\t\t\t                        ######          "<<endl;
    cout<<"\t\t\t\t\t                    ####      ####      "<<endl;
    cout<<"\t\t\t\t\t                  ##              ##    "<<endl;
    cout<<"\t\t\t\t\t                ##    ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##      ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##                      ##"<<endl;
    cout<<"\t\t\t\t\t            ####                      ##"<<endl;
    cout<<"\t\t\t\t\t            ##  ##    ##              ##"<<endl;
    cout<<"\t\t\t\t\t          ##    ##      ##          ##  "<<endl;
    cout<<"\t\t\t\t\t          ##    ####      ####      ##  "<<endl;
    cout<<"\t\t\t\t\t        ##          ####          ##    "<<endl;
    cout<<"\t\t\t\t\t        ##  ##          ##      ##      "<<endl;
    cout<<"\t\t\t\t\t      ##          ##      ######        "<<endl;
    cout<<"\t\t\t\t\t      ##        ##      ######          "<<endl;
    cout<<"\t\t\t\t\t    ##    ####      ####    ##          "<<endl;
    cout<<"\t\t\t\t\t    ##  ##      ####        ##          "<<endl;
    cout<<"\t\t\t\t\t  ##        ####                        "<<endl;
    cout<<"\t\t\t\t\t  ##    ####                            "<<endl;
    cout<<"\t\t\t\t\t##  ####                                "<<endl;
    cout<<"\t\t\t\t\t####                                                   Cargando...  "<<endl;
    pantalla();
    Sleep(x);
    gotoxy(0,7);
    cout<<"\t\t\t\t\t                        ######          "<<endl;
    cout<<"\t\t\t\t\t                    ####      ####      "<<endl;
    cout<<"\t\t\t\t\t                  ##              ##    "<<endl;
    cout<<"\t\t\t\t\t                ##    ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##      ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##                      ##"<<endl;
    cout<<"\t\t\t\t\t            ####                      ##"<<endl;
    cout<<"\t\t\t\t\t            ##  ##    ##              ##"<<endl;
    cout<<"\t\t\t\t\t          ##    ##      ##          ##  "<<endl;
    cout<<"\t\t\t\t\t          ##    ####      ####      ##  "<<endl;
    cout<<"\t\t\t\t\t        ##          ####          ##    "<<endl;
    cout<<"\t\t\t\t\t        ##  ##          ##      ##      "<<endl;
    cout<<"\t\t\t\t\t      ##          ##      ######        "<<endl;
    cout<<"\t\t\t\t\t      ##        ##      ####            "<<endl;
    cout<<"\t\t\t\t\t    ##    ####      ####                "<<endl;
    cout<<"\t\t\t\t\t    ##  ##      ####        ##          "<<endl;
    cout<<"\t\t\t\t\t  ##        ####            ##          "<<endl;
    cout<<"\t\t\t\t\t  ##    ####                ##          "<<endl;
    cout<<"\t\t\t\t\t##  ####                                "<<endl;
    cout<<"\t\t\t\t\t####                                                   Cargando.... "<<endl;
    pantalla();
    Sleep(x);
    gotoxy(0,7);
    cout<<"\t\t\t\t\t                        ######          "<<endl;
    cout<<"\t\t\t\t\t                    ####      ####      "<<endl;
    cout<<"\t\t\t\t\t                  ##              ##    "<<endl;
    cout<<"\t\t\t\t\t                ##    ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##      ##            ##  "<<endl;
    cout<<"\t\t\t\t\t              ##                      ##"<<endl;
    cout<<"\t\t\t\t\t            ####                      ##"<<endl;
    cout<<"\t\t\t\t\t            ##  ##    ##              ##"<<endl;
    cout<<"\t\t\t\t\t          ##    ##      ##          ##  "<<endl;
    cout<<"\t\t\t\t\t          ##    ####      ####      ##  "<<endl;
    cout<<"\t\t\t\t\t        ##          ####          ##    "<<endl;
    cout<<"\t\t\t\t\t        ##  ##          ##      ##      "<<endl;
    cout<<"\t\t\t\t\t      ##          ##      ######        "<<endl;
    cout<<"\t\t\t\t\t      ##        ##      ####            "<<endl;
    cout<<"\t\t\t\t\t    ##    ####      ####                "<<endl;
    cout<<"\t\t\t\t\t    ##  ##      ####                    "<<endl;
    cout<<"\t\t\t\t\t  ##        ####                        "<<endl;
    cout<<"\t\t\t\t\t  ##    ####                            "<<endl;
    cout<<"\t\t\t\t\t##  ####                    ##          "<<endl;
    cout<<"\t\t\t\t\t####                        ##                         Cargando....."<<endl;
    pantalla();
    Sleep(x);
}

int main()
{
    system("color 10");
    int i;
    pantalla();
    for(i=0;i<4;i++){
        carga();
    }
    {/*
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
    */}
    gotoxy(4,29);
    return 0;
}
