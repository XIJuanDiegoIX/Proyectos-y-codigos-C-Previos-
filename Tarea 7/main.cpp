#include <iostream>
#include<stdlib.h>
using namespace std;

class Persona{
private: //Atributos
    int edad;
    string nombre;
public:
    Persona(int,string); //Constructor
    void comer();
    void jugar();
};

//Contructor, inicalisa los atributos
Persona::Persona(int _edad,string _nombre){
    edad = _edad;
    nombre = _nombre;
}

void Persona::comer(){
    cout<<"Soy "<<nombre<<" y estoy comiendo pizza"<<endl;
}

void Persona::jugar(){
    cout<<"Soy "<<nombre<<" y estoy jugando a las cartas y tengo "<<edad<<endl;
}
int main()
{
    Persona p1 = Persona(20,"Diego");
    Persona p2(19,"Vanessa");
    Persona p3(21,"Juan");

    p1.comer();
    p2.jugar();

    p3.comer();
    p3.jugar();

    system("pause");
    return 0;
}
