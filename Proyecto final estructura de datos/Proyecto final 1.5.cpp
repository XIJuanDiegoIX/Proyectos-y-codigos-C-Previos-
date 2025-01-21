#include <iostream>
#include <vector>
#include <random>
#include <stack>
#include <limits>
#include <stdexcept>
#include <windows.h>

using namespace std;

// --- Lista Ligada ---

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void transformarSumaAcumulativa(Node* head) {
    int sumaAcumulativa = 0;
    Node* current = head;

    while (current != nullptr) {
        sumaAcumulativa += current->data;
        current->data = sumaAcumulativa;
        current = current->next;
    }
}

void imprimirLista(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void agregarNodo(Node*& head, int val) {
    if (head == nullptr) {
        head = new Node(val);
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(val);
    }
}

void menuLista() {
    Node* head = nullptr;
    int val, cant, opc, res;
    do {
        cout << "\n1-Agregar nuevo nodo" << endl;
        cout << "2-Agregar n nodos" << endl;
        cout << "3-Imprimir lista" << endl;
        cout << "4-Transformar e imprimir lista" << endl;
        cout << "5-Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> opc;
        cout << endl;
        switch (opc) {
            case 1:
                cout << "Ingrese el valor del nodo: "; cin >> val;
                agregarNodo(head, val); 
                break;
            case 2:
                cout << "Ingrese la cantidad de nodos: "; cin >> cant;
                cout << "¿Desea generarlos de manera aleatoria?" << endl;
                cout << "1-Si   2-No" << endl;
                cout << "Ingrese una opcion: "; cin >> res;
                switch (res) {
                    case 1:
                        for (int i = 0; i < cant; i++) {
                            val = rand() % 100 + 1;
                            agregarNodo(head, val);
                        }
                        break;
                    case 2:
                        for (int i = 0; i < cant; i++) {
                            cout << "Ingrese el valor del nodo " << (i + 1) << ": "; cin >> val;
                            agregarNodo(head, val);
                        }
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
                break;
            case 3:
                cout << "La lista es: ";
                imprimirLista(head);
                break;
            case 4:
                transformarSumaAcumulativa(head);
                cout << "Lista transformada: ";
                imprimirLista(head);
                break;
            case 5:
                cout << "\nUsted escogio salir. Hasta luego" << endl;
                Sleep(2000);
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opc != 5);
}

// --- Pila y Cola ---

class MinStack {
private:
    stack<int> stk;
    stack<int> minStk;

public:
    void push(int val) {
        stk.push(val);
        if (minStk.empty() || val <= minStk.top()) {
            minStk.push(val);
        }
    }

    void pop() {
        if (!stk.empty()) {
            if (stk.top() == minStk.top()) {
                minStk.pop();
            }
            stk.pop();
        }
    }

    int top() {
        if (!stk.empty()) {
            return stk.top();
        }
        throw runtime_error("La pila está vacía.");
    }

    int getMin() {
        if (!minStk.empty()) {
            return minStk.top();
        }
        throw runtime_error("La pila está vacía.");
    }

    void printStack() {
        stack<int> temp = stk;
        cout << "Pila: ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

class QueueUsingStacks {
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    void enqueue(int val) {
        stk1.push(val);
    }

    void dequeue() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if (!stk2.empty()) {
            stk2.pop();
        } else {
            throw runtime_error("La cola está vacía.");
        }
    }

    int front() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if (!stk2.empty()) {
            return stk2.top();
        } else {
            throw runtime_error("La cola está vacía.");
        }
    }

    void printQueue() {
        stack<int> temp1 = stk1, temp2;
        while (!temp1.empty()) {
            temp2.push(temp1.top());
            temp1.pop();
        }
        cout << "Cola: ";
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        cout << endl;
    }
};

void menuPilaCola() {
    MinStack pila;
    QueueUsingStacks cola;
    int opc, val;

    do {
        cout << "\n1-Push en Pila" << endl;
        cout << "2-Pop en Pila" << endl;
        cout << "3-Top de Pila" << endl;
        cout << "4-Min absoluto en Pila" << endl;
        cout << "5-Imprimir Pila" << endl;
        cout << "6-Encolar en Cola" << endl;
        cout << "7-Desencolar en Cola" << endl;
        cout << "8-Imprimir Cola" << endl;
        cout << "9-Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingrese el valor: "; cin >> val;
                pila.push(val);
                break;
            case 2:
                try {
                    pila.pop();
                    cout << "Pop exitoso." << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                try {
                    cout << "Top de Pila: " << pila.top() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                try {
                    cout << "Min absoluto de Pila: " << pila.getMin() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                pila.printStack();
                break;
            case 6:
                cout << "Ingrese el valor: "; cin >> val;
                cola.enqueue(val);
                break;
            case 7:
                try {
                    cola.dequeue();
                    cout << "Desencolado exitoso." << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            case 8:
                cola.printQueue();
                break;
            case 9:
                cout << "Saliendo del menú de Pila y Cola." << endl;
                Sleep(2000);
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opc != 9);
}

// --- Ordenamiento ---

void imprimirVector(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int left = low + 1;
        int right = high;

        while (left <= right) {
            while (left <= right && arr[left] < pivot) left++;
            while (left <= right && arr[right] >= pivot) right--;
            if (left < right) swap(arr[left], arr[right]);
        }
        swap(arr[low], arr[right]);

        quickSort(arr, low, right - 1);
        quickSort(arr, right + 1, high);
    }
}

void menuOrdenamiento() {
    vector<int> arr;
    int opc, t, val;

    do {
        cout << "\n1-Crear lista personalizada" << endl;
        cout << "2-Ver lista original" << endl;
        cout << "3-QuickSort" << endl;
        cout << "4-Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingrese el tamaño de la lista: "; cin >> t;
                arr.clear();
                for (int i = 0; i < t; ++i) {
                    cout << "Ingrese el valor " << (i + 1) << ": ";
                    cin >> val;
                    arr.push_back(val);
                }
                break;
            case 2:
                cout << "Lista original: ";
                imprimirVector(arr);
                break;
            case 3:
                quickSort(arr, 0, arr.size() - 1);
                cout << "QuickSort aplicado: ";
                imprimirVector(arr);
                break;
            case 4:
                cout << "Saliendo del menú de Ordenamiento." << endl;
                Sleep(2000);
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opc != 4);
}

// --- Recursividad ---

int fibonacciRecursivo(int n, string& proceso) {
    if (n <= 1) {
        proceso += to_string(n);
        return n;
    }
    int a = fibonacciRecursivo(n - 1, proceso);
    int b = fibonacciRecursivo(n - 2, proceso);
    proceso += to_string(a) + "+" + to_string(b) + "=" + to_string(a + b) + " ";
    return a + b;
}

int fibonacciIterativo(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    cout << "0 ";
    for (int i = 1; i < n; ++i) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void menuRecursividad() {
    int opc, n;
    string proceso;

    do {
        cout << "\n1-Fibonacci Recursivo" << endl;
        cout << "2-Fibonacci Iterativo" << endl;
        cout << "3-Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingrese el valor de n: "; cin >> n;
                proceso = "";
                cout << "Fibonacci recursivo de " << n << " es: " << fibonacciRecursivo(n, proceso) << endl;
                cout << "Proceso: " << proceso << endl;
                break;
            case 2:
                cout << "Ingrese el valor de n: "; cin >> n;
                cout << "Fibonacci iterativo de " << n << " es: ";
                cout << fibonacciIterativo(n) << endl;
                break;
            case 3:
                cout << "Saliendo del menú de Recursividad." << endl;
                Sleep(2000);
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opc != 3);
}

void salir() {
    cout << "Gracias por usar este programa." << endl;
}

int main() {
    int opc;
    do {
        cout << "1-Lista ligada" << endl;
        cout << "2-Pilas y colas" << endl;
        cout << "3-Ordenamiento" << endl;
        cout << "4-Recursividad" << endl;
        cout << "5-Salir" << endl;
        cout << "Seleccione una opcion: "; cin >> opc;

        switch (opc) {
            case 1:
                menuLista();
                break;
            case 2:
                menuPilaCola();
                break;
            case 3:
                menuOrdenamiento();
                break;
            case 4:
                menuRecursividad();
                break;
            case 5:
                salir();
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
        Sleep(3000);
    } while (opc != 5);
    return 0;
}
