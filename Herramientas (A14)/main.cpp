#include <iostream>
#include <string>

using namespace std;

class Herramientas{
    public:
    Herramientas();
};

Herramientas::Herramientas(){
}

class HerramientaPlomero : Herramientas{
    public:
        float precio;
        string color;
    HerramientaPlomero(float, string);
    void HerrPlo();
};

HerramientaPlomero::HerramientaPlomero(float _precio, string _color) : Herramientas(){
    precio= _precio;
 color = _color;
}

class HerramientaCarpintero : Herramientas{
    public:
        float precio;
        string color;
    HerramientaCarpintero(float, string);
    void HerrCar();
};

HerramientaCarpintero::HerramientaCarpintero(float _precio, string _color) : Herramientas(){
    precio = _precio;
 color = _color;
}

void HerramientaPlomero::HerrPlo(){
    cout<<"Este es la soldadura y tiene un costo de "<<precio<<" y es de color "<<color<<endl<<endl;
}
void HerramientaCarpintero::HerrCar(){
    cout<<"Este es el serrucho y tiene un costo de "<<precio<<" y es de color "<<color<<endl<<endl;
}

int main()
{
    float prec;
    string col;
    HerramientaPlomero Soldadora(120.00, "Rojo");
    HerramientaCarpintero Serrucho(75.00, "Cafe");
    Soldadora.HerrPlo();
    Serrucho.HerrCar();
    cout<<"Ingrese el nuevo precio de la soldadora: "; cin>>prec;
    cout<<"Ingrese el nuevo color de la serrucho: "; cin>>col;
    Soldadora.precio = prec;
    Serrucho.color = col;
    Soldadora.HerrPlo();
    Serrucho.HerrCar();
    return 0;
}
