#include <iostream>

using namespace std;

//----------------------------------------------------------------
class Neveria {
public:
    // atributos
    string nombre;
    int listaSabores;
    int precio;
    int inventario;

    // métodos
    Neveria(string, int, int, int);  // constructor
    void agregarSabor();
    void actualizarPrecio();
    void realizarVenta();
    void reporteVentas();
    void calcularIngresos();
    void verificarSaborYCantidad();
};

Neveria::Neveria(string _nombre, int _listaSabores, int _precio, int _inventario) {
    nombre = _nombre;
    listaSabores = _listaSabores;
    precio = _precio;
    inventario = _inventario;
}

void Neveria::agregarSabor() {
    cout << "Soy " << nombre << " y estoy agregando un sabor" << endl;
}

void Neveria::actualizarPrecio() {
    cout << "Soy " << nombre << " y estoy actualizando el precio" << endl;
}

void Neveria::realizarVenta() {
    cout << "Soy " << nombre << " y estoy realizando una venta" << endl;
}

void Neveria::reporteVentas() {
    cout << "Soy " << nombre << " y estoy haciendo un reporte de ventas" << endl;
}

void Neveria::calcularIngresos() {
    cout << "Soy " << nombre << " y estoy calculando los ingresos" << endl;
}

void Neveria::verificarSaborYCantidad() {
    cout << "Soy " << nombre << " y estoy verificando el sabor y la cantidad" << endl;
}

//----------------------------------------------------------------

class Nieve : public Neveria {
public:
    // atributos
    int cantidadBolas;
    int barquillos;
    int cucharas;

    // métodos
    Nieve(int, int, int);  // constructor
    void acumularNieve();  // sobreescritura del método
    void anadirChocolate();
};

Nieve::Nieve(int _cantidadBolas, int _barquillos, int _cucharas) : Neveria("", 0, 0, 0) {
    cantidadBolas = _cantidadBolas;
    barquillos = _barquillos;
    cucharas = _cucharas;
}

void Nieve::acumularNieve() {
    cout << "Soy " << nombre << " y estoy acumulando nieve" << endl;
}

void Nieve::anadirChocolate() {
    cout << "Soy " << nombre << " y estoy anadiendo chocolate a la nieve" << endl;
}

//----------------------------------------------------------------

class AguasFrescas : public Neveria {
public:
    // atributos
    int litros;
    int popotes;
    int tapas;

    // métodos
    AguasFrescas(int, int, int);  // constructor
    void anadirFruta();  // sobreescritura del método
    void anadirHielos();
};

AguasFrescas::AguasFrescas(int _litros, int _popotes, int _tapas) : Neveria("", 0, 0, 0) {
    litros = _litros;
    popotes = _popotes;
    tapas = _tapas;
}

void AguasFrescas::anadirFruta() {
    cout << "Soy " << nombre << " y estoy anadiendo fruta al agua fresca" << endl;
}

void AguasFrescas::anadirHielos() {
    cout << "Soy " << nombre << " y estoy anadiendo hielos al agua fresca" << endl;
}

//----------------------------------------------------------------

int main() {
    Neveria p1 = Neveria("Neveria San Pedro", 20, 30, 2);
    p1.agregarSabor();
    p1.actualizarPrecio();
    p1.realizarVenta();
    p1.reporteVentas();
    p1.calcularIngresos();
    p1.verificarSaborYCantidad();

    Nieve nieve1 = Nieve(3, 2, 1);
    nieve1.acumularNieve();
    nieve1.anadirChocolate();

    AguasFrescas agua1 = AguasFrescas(5, 50, 10);
    agua1.anadirFruta();
    agua1.anadirHielos();

    system("pause");
    return 0;
}
