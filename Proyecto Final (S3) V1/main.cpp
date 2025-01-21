#include <iostream>
#include <string>
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

/*
--------------------------------------------------------
        Clase Padre y contructor
--------------------------------------------------------
*/
class Producto{ //Clase padre (Productos)
    private: //Datos privados
        float inventario;
    public: //Datos publicos
        string nombre;
        float precio;
        string sabor;
    Producto(float, string, float, string); //Contructor
        //Funcion();
};

Producto::Producto(float _inventario, string _nombre, float _precio, string _sabor){ //Contructor
    inventario= _inventario;
    nombre = _nombre;
    precio= _precio;
    sabor= _sabor;
}

/*
--------------------------------------------------------
        Clase Hija y contructor (Nieve)
--------------------------------------------------------
*/

class Nieve:Producto{ //Clase hija
    public:
        string recipiente;
        int cant_bolas;
        int chocolate_derretido; //1.Si 0.No
        string topping;
    Nieve(float, string, float, string, string, int, int, string); //Contructor
        void mostrarNieve();
};

Nieve::Nieve(float _inventario, string _nombre, float _precio, string _sabor, string _recipiente, int _cant_bolas, int _chocolate_derretido, string _topping) : Producto (_inventario, _nombre, _precio, _sabor){
//Metodo contructor
    recipiente = _recipiente;
    cant_bolas = _cant_bolas;
    chocolate_derretido = _chocolate_derretido;
    topping = _topping;
}

//Funcion

void Nieve::mostrarNieve(){
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Su producto es: "<<nombre<<" de "<<sabor<<endl;
    cout<<"Recipiente: "<<recipiente<<endl;
    cout<<cant_bolas<<" Bolas"<<endl;
    cout<<"Topping: "<<topping<<endl;
    cout<<endl;
    cout<<precio<<"$"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
}

/*
--------------------------------------------------------
        Clase Hija y contructor (Agua)
--------------------------------------------------------
*/

class Agua:Producto{
    public:
        string tamano;
        int hielo; // 1.si 0.no
    Agua(float, string, float, string, string, int); //Contructor
        void mostrarAgua();
};

Agua::Agua(float _inventario, string _nombre, float _precio, string _sabor, string _tamano, int _hielo) : Producto (_inventario, _nombre, _precio, _sabor){
//Metodo contructor
    tamano = _tamano;
    hielo = _hielo;
}

//Funcion

void Agua::mostrarAgua(){
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Su producto es: "<<nombre<<" de "<<sabor<<endl;
    cout<<"Tamaño: "<<tamano<<endl;
    cout<<endl;
    cout<<precio<<"$"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
}
/*
--------------------------------------------------------
        Menu y objetos
--------------------------------------------------------
*/


int main()
{
    //float descuento; // 1.00 - 0.00
    gotoxy(10,10);
    cout<<"Hola"<<endl;
    Nieve prodNieve = Nieve(4.5, "Nieve", 59.50, "Vainilla", "Cono", 2, 1, "Galleta");
    Agua prodAgua = Agua(7.0, "Agua", 79.50, "Menta", "Grande", 1);
    prodNieve.mostrarNieve();
    cout<<endl;
    prodAgua.mostrarAgua();
    return 0;
}
