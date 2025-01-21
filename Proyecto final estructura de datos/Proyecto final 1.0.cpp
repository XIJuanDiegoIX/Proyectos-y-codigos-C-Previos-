#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <conio.h>
#include <windows.h>
#include <stack>
#include <limits>
#include <stdexcept>

using namespace std;

// Definición de un nodo en la lista ligada
struct Node {
    int data;
    Node* next;

    // Constructor para facilitar la creación de nodos
    Node(int val) : data(val), next(nullptr) {}
};

// Función para transformar la lista a su suma acumulativa
void transformarSumaAcumulativa(Node* head) {
    int sumaAcumulativa = 0;
    Node* current = head;

    // Recorremos la lista para actualizar cada nodo
    while (current != nullptr) {
        sumaAcumulativa += current->data;
        current->data = sumaAcumulativa; // Actualizamos el nodo con la suma acumulativa
        current = current->next;
    }
}

// Función para imprimir la lista ligada
void imprimirLista(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Función para agregar un nodo al final de la lista
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

void Lista() {
    Node* head = nullptr;
    int x, cant, opc, res;
    do{
        cout << "\n1-Agregar nuevo nodo" << endl;
        cout << "2-Agregar n nodos" << endl;
        cout << "3-Imprimir lista" << endl;
        cout << "4-Transformar e imprimir lista" << endl;
        cout << "5-Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> opc;
        cout << endl;
        switch (opc){
            case 1:
                cout << "Ingrese el valor del nodo: "; cin >> x;
                agregarNodo(head, x); 
                break;
            case 2:
                cout << "Ingrese la cantidad de nodos: "; cin >> cant;
                cout << "¿Desea generarlos de manera aleatoria?" << endl;
                cout << endl;
                cout << "1-Si   2-No" << endl;
                cout << "Ingrese una opcion: "; cin >> res;
                switch(res){
                    case 1:
                        for(int i = 0; i < cant; i++){
                            x = rand() % 100 + 1;
                            agregarNodo(head, x);
                        }
                        break;
                    case 2:
                        for(int i = 0; i < cant; i++){
                            cout << "Ingrese el valor del nodo " << (i+1) << ": "; cin >> x;
                            agregarNodo(head, x);
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
    }while(opc != 5);
}

// Clase: Pila que Rastrea el Mínimo Absoluto y Relativo
class PilaMinima {
private:
    stack<int> pila;        // Pila principal
    stack<int> minPila;     // Pila para rastrear el mínimo absoluto

public:
    // Agregar un elemento a la pila
    void push(int valor) {
        pila.push(valor);
        if (minPila.empty() || valor <= minPila.top()) {
            minPila.push(valor); // Actualizar el mínimo absoluto
        }
    }

    // Eliminar el elemento superior de la pila
    void pop() {
        if (!pila.empty()) {
            if (pila.top() == minPila.top()) {
                minPila.pop(); // Actualizar el mínimo absoluto si es necesario
            }
            pila.pop();
        }
    }

    // Obtener el valor superior de la pila
    int top() {
        if (!pila.empty()) {
            return pila.top();
        }
        throw runtime_error("La pila está vacía.");
    }

    // Obtener el mínimo absoluto de la pila
    int getMinAbs() {
        if (!minPila.empty()) {
            return minPila.top();
        }
        throw runtime_error("La pila está vacía.");
    }

    // Obtener el mínimo relativo (menor que el último valor agregado)
    int getMinRel() {
        if (pila.size() < 2) {
            throw runtime_error("No hay suficientes elementos para calcular el mínimo relativo.");
        }
        int topValor = pila.top();
        stack<int> temp = pila;
        temp.pop(); // Quitar el valor superior
        int minRel = numeric_limits<int>::max();
        while (!temp.empty()) {
            if (temp.top() < topValor) {
                minRel = min(minRel, temp.top());
            }
            temp.pop();
        }
        if (minRel == numeric_limits<int>::max()) {
            throw runtime_error("No hay un mínimo relativo disponible.");
        }
        return minRel;
    }
};

// Clase: Cola Implementada con Pilas
class ColaConPilas {
private:
    stack<int> pila1; // Pila para encolar
    stack<int> pila2; // Pila para desencolar

public:
    // Agregar un elemento a la cola
    void encolar(int valor) {
        pila1.push(valor);
    }

    // Eliminar el elemento frontal de la cola
    void desencolar() {
        if (pila2.empty()) {
            // Mover todos los elementos de pila1 a pila2 si pila2 está vacía
            while (!pila1.empty()) {
                pila2.push(pila1.top());
                pila1.pop();
            }
        }

        if (!pila2.empty()) {
            pila2.pop();
        } else {
            throw runtime_error("La cola está vacía.");
        }
    }

    // Obtener el elemento frontal de la cola
    int frente() {
        if (pila2.empty()) {
            // Mover todos los elementos de pila1 a pila2 si pila2 está vacía
            while (!pila1.empty()) {
                pila2.push(pila1.top());
                pila1.pop();
            }
        }

        if (!pila2.empty()) {
            return pila2.top();
        } else {
            throw runtime_error("La cola está vacía.");
        }
    }

    // Verificar si la cola está vacía
    bool vacia() {
        return pila1.empty() && pila2.empty();
    }
};

// Función Principal
void pilaycola() {
    // Pruebas para la Pila con Mínimos
    cout << "=== Pila con Mínimos ===" << endl;
    PilaMinima pila;

    pila.push(5);
    pila.push(2);
    pila.push(8);
    pila.push(1);

    cout << "Mínimo absoluto: " << pila.getMinAbs() << endl;
    cout << "Top actual: " << pila.top() << endl;
    cout << "Mínimo relativo: " << pila.getMinRel() << endl;

    pila.pop();
    cout << "Mínimo absoluto tras pop: " << pila.getMinAbs() << endl;

    cout << endl;

    // Pruebas para la Cola con Pilas
    cout << "=== Cola con Pilas ===" << endl;
    ColaConPilas cola;

    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);

    cout << "Frente: " << cola.frente() << endl; // Debería imprimir 1
    cola.desencolar();

    cout << "Frente tras desencolar: " << cola.frente() << endl; // Debería imprimir 2

    cola.desencolar();
    cola.encolar(4);
    cout << "Frente tras encolar 4: " << cola.frente() << endl; // Debería imprimir 3

    cola.desencolar();
    cout << "Frente tras desencolar: " << cola.frente() << endl; // Debería imprimir 4
}


int intercambio(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
    return a, b;
}

void quickSort (){
    int t;
    cout <<"Seleccione el tamaño de la lista: "; cin >> t;
    int lista[t];
    for (int i = 0; i < t; i++){
        lista[i] = rand() % 100 + 1;
    }
    int size = sizeof(lista) / sizeof(lista[0]);
    cout << "La lista generada es: ";
    for(int i=0; i < size; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
    if (t <= 1){
        cout << "La lista no tiene elementos suficientes para ordenar." << endl;
        return;
    }
    int pivote = lista[0];
    int temp;
    intercambio(lista[0], lista[1]);
    cout << "La lista ordenada es: ";
    for(int i=0; i < size; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
}

void salir(){
    cout << "Gracias por usar este programa." << endl;
}

// Función recursiva para calcular el n-ésimo número de Fibonacci
int fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

// Función iterativa para calcular el n-ésimo número de Fibonacci
int fibonacciIterativo(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Función recursiva para obtener todas las combinaciones de un conjunto
void obtenerCombinaciones(vector<int>& conjunto, vector<int>& combinacion, int inicio, vector<vector<int>>& resultado) {
    if (inicio == conjunto.size()) {
        resultado.push_back(combinacion);
        return;
    }
    
    // No incluir el elemento actual
    obtenerCombinaciones(conjunto, combinacion, inicio + 1, resultado);
    
    // Incluir el elemento actual
    combinacion.push_back(conjunto[inicio]);
    obtenerCombinaciones(conjunto, combinacion, inicio + 1, resultado);
    combinacion.pop_back();
}

// Función para imprimir combinaciones
void imprimirCombinaciones(const vector<vector<int>>& combinaciones) {
    for (const auto& comb : combinaciones) {
        cout << "{ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

// Función principal
void recursividad() {
    // Pruebas para Fibonacci
    int n = 10;
    cout << "Fibonacci recursivo de " << n << " es: " << fibonacciRecursivo(n) << endl;
    cout << "Fibonacci iterativo de " << n << " es: " << fibonacciIterativo(n) << endl;

    // Pruebas para combinaciones
    vector<int> conjunto = {1, 2, 3};
    vector<int> combinacion;
    vector<vector<int>> resultado;

    obtenerCombinaciones(conjunto, combinacion, 0, resultado);

    cout << "Combinaciones del conjunto {1, 2, 3}:" << endl;
    imprimirCombinaciones(resultado);
}

// Definición de un nodo del BST
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Clase del Árbol Binario de Búsqueda
class BST {
private:
    TreeNode* root;

    // Función auxiliar para insertar un nodo
    TreeNode* insertar(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insertar(node->left, val);
        } else {
            node->right = insertar(node->right, val);
        }
        return node;
    }

    // Función auxiliar para buscar un nodo
    bool buscar(TreeNode* node, int val) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == val) {
            return true;
        }
        if (val < node->val) {
            return buscar(node->left, val);
        } else {
            return buscar(node->right, val);
        }
    }

    // Función auxiliar para realizar un recorrido en orden (in-order traversal)
    void inOrder(TreeNode* node, vector<int>& nodes) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left, nodes);
        nodes.push_back(node->val);
        inOrder(node->right, nodes);
    }

    // Función auxiliar para construir un árbol balanceado a partir de un vector ordenado
    TreeNode* construirArbolBalanceado(vector<int>& nodes, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = construirArbolBalanceado(nodes, start, mid - 1);
        node->right = construirArbolBalanceado(nodes, mid + 1, end);
        return node;
    }

public:
    BST() : root(nullptr) {}

    // Función pública para insertar un nodo
    void insertar(int val) {
        root = insertar(root, val);
    }

    // Función pública para buscar un nodo
    bool buscar(int val) {
        return buscar(root, val);
    }

    // Función pública para rebalancear el árbol
    void rebalancear() {
        vector<int> nodes;
        inOrder(root, nodes);
        root = construirArbolBalanceado(nodes, 0, nodes.size() - 1);
    }

    // Función para imprimir el BST en orden
    void imprimirEnOrden() {
        vector<int> nodes;
        inOrder(root, nodes);
        for (int val : nodes) {
            cout << val << " ";
        }
        cout << endl;
    }
};

void arbolBin() {
    BST arbol;

    // Insertar nodos en el BST
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(18);

    // Buscar nodos en el BST
    cout << "Buscar 7: " << (arbol.buscar(7) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 20: " << (arbol.buscar(20) ? "Encontrado" : "No encontrado") << endl;

    // Imprimir el BST en orden
    cout << "BST en orden antes de rebalancear: ";
    arbol.imprimirEnOrden();

    // Rebalancear el BST
    arbol.rebalancear();

    // Imprimir el BST en orden después de rebalancear
    cout << "BST en orden después de rebalancear: ";
    arbol.imprimirEnOrden();
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= right && arr[left] < pivot) {
            left++;
        }
        while (left <= right && arr[right] >= pivot) {
            right--;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[low], arr[right]);
    return right;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void imprimirVector(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

void Sorters() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arrBubble = arr;
    vector<int> arrSelection = arr;
    vector<int> arrQuick = arr;

    // Bubble Sort
    bubbleSort(arrBubble);
    cout << "Bubble Sort: ";
    imprimirVector(arrBubble);

    // Selection Sort
    selectionSort(arrSelection);
    cout << "Selection Sort: ";
    imprimirVector(arrSelection);

    // QuickSort
    quickSort(arrQuick, 0, arrQuick.size() - 1);
    cout << "QuickSort: ";
    imprimirVector(arrQuick);
}

int main(int argc, char const *argv[])
{
    int opc;
    do{
        cout << "1-Lista ligada" << endl; 
        cout << "2-Pilas y colas" << endl; 
        cout << "3-Ordenamiento" << endl;
        cout << "4-Recursividad" << endl;
        cout << "5-Arbol" << endl;
        cout << "6-Complejidad" << endl;
        cout << "7-Salir" << endl;
        cout << "Seleccione una opcion: "; cin>>opc;
        switch (opc) {
            case 1: 
                Lista(); 
                break;
            case 2: 
                pilaycola();
                break;
            case 3: 
                quickSort(); 
                break;
            case 4: 
                recursividad(); 
                break;
            case 5: 
                arbolBin();
                break;
            case 6:
                Sorters();
                break;
            case 7: 
                salir(); 
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        Sleep(3000);
    }while(opc != 7);
    return 0;
}
