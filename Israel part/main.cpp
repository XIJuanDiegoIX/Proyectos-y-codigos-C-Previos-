#include <iostream>
#include <string>
#include <windows.h>
#include <vector> //Proporciona la funcionalidad para trabajar con vectores dinámicos, que se utilizan para almacenar los diferentes tipos de nieve en el inventario
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
    system("cls");
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
    Sleep(x);
}



class Nieve { //aqui tenemos nuestra clase nieve, con atributos privados de tipo string y float
private:
    string medida;
    float precio;

public: //constructor que inicializa los atributos medida y precio
    Nieve(string _medida, float _precio) : medida(_medida), precio(_precio) {}

    void mostrar() const { //funcion para mostrar la info de la nieve(tamaño y precio)
        cout << "Medida del vaso: " << medida << ", Precio: $" << precio << endl;
    }

    void modificarPrecio(float nuevoPrecio) { //funcion para modificar el precio de la nieve
        precio = nuevoPrecio;
        cout << "\t\tEl precio de la nieve de medida " << medida << " ha sido modificado a $" << precio << endl;
    }

    float obtenerPrecio() const { //devuelve el precio de la nieve
        return precio;
    }
};

class Dinero { //clase dinero
private: //atributos tipo float
    float cantidad;

public: //constructor inicializa la cant de dinero en $0
    Dinero() : cantidad(0) {}

     void agregar(float cantidad) { //metodo para agregar una cantidad de dinero al objeto
        this->cantidad += cantidad;
    }

    void reiniciar() { //reinicia la cant de dinero de la caja a $0 al hacer el corte de caja
        cantidad = 0;
    }

    float obtenerCantidad() const { //devuelve la cant de dinero actual de la caja
        return cantidad;
    }
};

int main() {  //funcion main, esta es la funcion principal del programa
    vector<Nieve> inventario; //se inicializa un vector "inventario" para almacenar los diferentes tipos de nieves
    Dinero caja; //objeto "caja" de la clase "dinero" para manejar el dinero de la neveria
    string clave; //variable "clave" de tipo string, esta sirve mas adelante para pedir una clave para poder entrar en algunas opciones del programa

    inventario.push_back(Nieve("Chico", 25.0)); //vector "inventario" este almacenara los tipos de nieve
    inventario.push_back(Nieve("Mediano", 30.0)); //push_back es una funcion de los vectores en c++, se utiliza para agregar un nuevo elemento al final del vector "inventario", esto con la finalidad de agregar un nuevo precio despues o en general otra cosa
    inventario.push_back(Nieve("Grande", 33.0));
    inventario.push_back(Nieve("Extra Grande", 36.0)); //constructor de la clase "nieve" con los argumentos "extra grande" y "36.0"
    inventario.push_back(Nieve("Cono Sencillo", 25.0));
    inventario.push_back(Nieve("Cono Doble", 36.0));

system("color 20");
    int i, t_l=2000;
    pantalla();
    for(i=0;i<4;i++){
        carga();
    }
    pantalla();
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

    gotoxy(70,27);
    cout << "Bienvenido a la Neveria la Perla" << endl; //mensaje de bienvendida :D
    Sleep(t_l);

    while (true) { //bucle while que representa el menu del programa
    //La condición while (true) indica que el bucle se ejecutará indefinidamente, ya que la condición siempre es verdadera (true). Esto solo se detiene cuando se ejecuta una instrucción return, lo que termina la función main() y, por lo tanto, el programa.
        pantalla();
        gotoxy(12,9);
        cout << "*** Menu Principal ***" << endl;
        gotoxy(12,11);
        cout << "1. Vender nieve" << endl;
        gotoxy(12,13);        cout << "2. Modificar precio de la nieve" << endl;
        gotoxy(12,15);
        cout << "3. Corte de caja" << endl; //muestra el menu con cout
        gotoxy(12,17);
        cout << "4. Estado de corte" << endl;
        gotoxy(12,19);
        cout << "5. Salir" << endl;
        gotoxy(12,25);
        cout << "                                                                   ";
        gotoxy(12,25);
        cout << "Seleccione una opcion: ";
        int opcion; //variable "opcion" de tipo int para almacenar la opcion realizada por el usuario
        cin >> opcion; //Se utiliza cin para leer la entrada del usuario y almacenarla en esta variable.

        switch (opcion) { //estructura de control "switch" para seleccionar el bloque de código que corresponde a la opción seleccionada por el usuario.
            case 1: { //Si el usuario elige la opción 1, se ejecuta el código para vender nieve.
                while(true){
                    pantalla();
                    gotoxy(12,7);
                    cout << "\t\t*** Venta de nieve ***\n" << endl;
                    cout << "\t\tSeleccione el medida del vaso que desea comprar:" << endl;
                    for (int i = 0; i < inventario.size(); ++i) {
    //inicia el contador "i" en 0, el sig se ejecutara mientras "i" sea menor que el vector inventario y el sig incrementa el valor de "i" en 1 en cada iteracion
                        cout <<"\n\t    "<< i+1 << ". "; //Imprime el número de la opción seguido de un punto
                        inventario[i].mostrar();
    //Llama al método mostrar() de cada objeto Nieve en el vector inventario, lo que imprime la información del tamaño del vaso y el precio de cada tipo de nieve.
                    }
                    gotoxy(12,23);
                    cout << "Digite Cero para salir...";
                    gotoxy(12,25);
                    cout << "Ingrese el numero correspondiente al medida del vaso: ";
                    int numNieve; //metodo para ingresar el numero y guardarlo
                    cin >> numNieve;
                    if(numNieve != 0){
                        if (numNieve >= 1 && numNieve <= inventario.size()) { //Este if verifica si la variable numNieve, que representa el número seleccionado por el usuario, está dentro del rango válido.
                            while(true){
                                pantalla();
                                gotoxy(12,7);
                                float precioNieve = inventario[numNieve-1].obtenerPrecio();
                                cout << "El precio del medida seleccionado es: $" << precioNieve << endl;
                                gotoxy(12,9);
                                cout << "Digite Cero para cancelar."<< endl;
                                gotoxy(12,26);
                                cout << "Ingrese la cantidad de dinero recibida:             ";
                                gotoxy(52,26);
                                float dineroRecibido;
                                cin >> dineroRecibido;
                                if(dineroRecibido != 0){
                                    if (dineroRecibido >= precioNieve) {
                                        float cambio = dineroRecibido - precioNieve;
                                        gotoxy(12,26);
                                        cout << "Gracias por su compra. Su cambio es: $" << cambio <<"                  \n\t\t";
                                        caja.agregar(precioNieve);
                                        system("pause");
                                        break;
                                    } else { //Este else se ejecuta si la condición del if anterior no se cumple
                                        gotoxy(12,26);
                                        cout << "El dinero recibido es insuficiente. Vuelva a intentarlo." << endl;
                                        Sleep(t_l);
                                    }
                                }else{
                                    break;
                                }
                            }
                            break;
                        } else {
                            gotoxy(12,25);
                            cout << "Numero de medida invalido. Vuelva a intentarlo.        " << endl;
                            Sleep(t_l);
                        }
                    }else{
                        break;
                    }
                }
                break; //rompe el bucle de este caso
            }
            case 2: {
                gotoxy(12,25);
                cout << "Por favor, ingrese la clave para acceder: ";
                cin >> clave;
                if (clave == "nieve") {
                    while(true){
                        pantalla();
                        gotoxy(12,7);
                        cout << "Seleccione el medida del vaso que desea modificar:" << endl;
                        for (int i = 0; i < inventario.size(); ++i) {
                            cout <<"\n\t    "<<  i+1 << ". ";
                            inventario[i].mostrar();
                        }
                        gotoxy(12,23);
                        cout << "Digite Cero para cancelar."<< endl;
                        gotoxy(12,25);
                        cout << "Ingrese el numero correspondiente al medida del vaso:      ";
                        gotoxy(66,25);
                        int numNieve;
                        cin >> numNieve;
                        if(numNieve != 0){
                            if (numNieve >= 1 && numNieve <= inventario.size()) {
                                gotoxy(12,25);
                                cout << "Ingrese el nuevo precio para el medida seleccionado: $         ";
                                gotoxy(12,23);
                                cout << "                                   "<< endl;
                                gotoxy(66,25);
                                float nuevoPrecio;
                                cin >> nuevoPrecio;
                                inventario[numNieve-1].modificarPrecio(nuevoPrecio);
                                Sleep(t_l);
                                break;
                            } else {
                                gotoxy(12,25);
                                cout << "Numero de medida invalido. Vuelva a intentarlo.                " << endl;
                                Sleep(t_l);
                            }
                        }else{
                            break;
                        }
                    }
                } else {
                    gotoxy(12,25);
                    cout << "Clave incorrecta. Acceso denegado.             " << endl;
                    Sleep(t_l);
                }
                break;
            }
            case 3: {
                gotoxy(12,25);
                cout << "Por favor, ingrese la clave para acceder: ";
                cin >> clave;
                if (clave == "nieve") {
                    cout << "\n\t\tDinero total en caja: $" << caja.obtenerCantidad() << "        ";
                    caja.reiniciar(); // Reiniciar el conteo de dinero en cada corte de caja
                    system("pause");
                } else {
                    gotoxy(12,25);
                    cout << "Clave incorrecta. Acceso denegado.             " << endl;
                }
                break;
            }
            case 4: {
                gotoxy(12,25);
                cout << "\n\n\tDinero total vendido hasta el momento: $" << caja.obtenerCantidad() << endl;
                Sleep(t_l);
                break;
            }
            case 5: {
                cout << "\n\t\tGracias por usar nuestro sistema. Hasta luego" << endl;
                Sleep(t_l);
                return 0;
            }
            default:
                gotoxy(12,25);
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                Sleep(t_l);
        }
    }
    gotoxy(4,29);
    return 0; //finaliza el codigo
}

