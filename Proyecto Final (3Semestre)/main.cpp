#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Nieve {
public:
    string tamano;
    float precio;

    Nieve(string t = "", float p = 0) : tamano(t), precio(p) {}
};

class Venta {
public:
    Nieve nieve;
    float pago;

    Venta(Nieve n = Nieve(), float pag = 0) : nieve(n), pago(pag) {}

    float calcular_cambio() {
        return pago - nieve.precio;
    }
};

class GestorDinero {
public:
    float dinero_disponible;

    GestorDinero() : dinero_disponible(0) {}

    void entrada_dinero(float cantidad) {
        dinero_disponible += cantidad;
    }

    bool salida_dinero(float cantidad) {
        if (cantidad <= dinero_disponible) {
            dinero_disponible -= cantidad;
            return true;
        } else {
            return false;
        }
    }

    float calcular_dinero_vendido() {
        float dinero_vendido = 0;
        return dinero_vendido;
    }
};

class Menu {
public:
    GestorDinero gestor_dinero;
    string contrasena_admin = "nieve";

    void mostrar_menu_principal() {
        cout << "1. Realizar venta" << endl;
        cout << "2. Entrada de dinero" << endl;
        cout << "3. Salida de dinero" << endl;
        cout << "4. Modificar precios (requiere autenticacion)" << endl;
        cout << "5. Corte de caja" << endl;
        cout << "6. Salir" << endl;
    }

    void realizar_venta(unordered_map<string, Nieve>& nieves) {
        string tamano;
        cout << "Selecciona el tamano de la nieve (Chica, Mediana, Grande): ";
        cin >> tamano;
        Nieve nieve_seleccionada = nieves[tamano];

        cout << "Precio de la nieve: " << nieve_seleccionada.precio << endl;
        float pago;
        cout << "Ingresa la cantidad de dinero recibida: ";
        cin >> pago;

        Venta venta(nieve_seleccionada, pago);
        float cambio = venta.calcular_cambio();
        if (cambio >= 0) {
            cout << "Cambio: " << cambio << endl;
        } else {
            cout << "Cantidad insuficiente" << endl;
        }
    }

    void entrada_dinero() {
        float cantidad;
        cout << "Ingrese la cantidad de dinero a ingresar: ";
        cin >> cantidad;
        gestor_dinero.entrada_dinero(cantidad);
        cout << "Dinero ingresado correctamente" << endl;
    }

    void salida_dinero() {
        float cantidad;
        cout << "Ingrese la cantidad de dinero a retirar: ";
        cin >> cantidad;
        if (gestor_dinero.salida_dinero(cantidad)) {
            cout << "Dinero retirado correctamente" << endl;
        } else {
            cout << "Fondos insuficientes" << endl;
        }
    }

    void modificar_precios() {
        string contrasena;
        cout << "Ingrese la contrasena de administrador: ";
        cin >> contrasena;

        if (contrasena == contrasena_admin) {
            cout << "Autenticacion exitosa. Puede modificar precios." << endl;
        } else {
            cout << "Contrasena incorrecta. Acceso denegado." << endl;
        }
    }

    void corte_caja() {
        float dinero_vendido = gestor_dinero.calcular_dinero_vendido();
        cout << "Dinero total vendido: " << dinero_vendido << endl;
        cout << "Dinero disponible en caja: " << gestor_dinero.dinero_disponible << endl;
    }
};

int main() {
    Menu menu;
    unordered_map<string, Nieve> nieves = {
        {"Chica", Nieve("Chica", 2.50)},
        {"Mediana", Nieve("Mediana", 3.50)},
        {"Grande", Nieve("Grande", 4.50)}
    };

    while (true) {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        menu.mostrar_menu_principal();
        int opcion;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menu.realizar_venta(nieves);
                break;
            case 2:
                menu.entrada_dinero();
                break;
            case 3:
                menu.salida_dinero();
                break;
            case 4:
                menu.modificar_precios();
                break;
            case 5:
                menu.corte_caja();
                break;
            case 6:
                cout << "Hasta luego!" << endl;
                return 0;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
    }

    return 0;
}
