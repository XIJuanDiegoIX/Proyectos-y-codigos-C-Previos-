#include <iostream>
#include <vector>
#include <random>
#include <stack>
#include <limits>
#include <stdexcept>
#include <windows.h>

using namespace std;

// --- Lista Ligada ---

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

    while (current != nullptr) {
        sumaAcumulativa += current->data;
        current->data = sumaAcumulativa;
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

// Menú interactivo para Lista Ligada
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

    int getMinRel() {
        if (stk.size() < 2) {
            throw runtime_error("No hay suficientes elementos para calcular el mínimo relativo.");
        }
        int topVal = stk.top();
        stack<int> temp = stk;
        temp.pop();
        int minRel = numeric_limits<int>::max();
        while (!temp.empty()) {
            if (temp.top() < topVal) {
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

    bool isEmpty() {
        return stk1.empty() && stk2.empty();
    }
}

// Menú interactivo para Pila y Cola
void menuPilaCola() {
    MinStack pila;
    QueueUsingStacks cola;
    int opc, val;

    do {
        cout << "\n1-Push en Pila" << endl;
        cout << "2-Pop en Pila" << endl;
        cout << "3-Top de Pila" << endl;
        cout << "4-Min absoluto en Pila" << endl;
        cout << "5-Min relativo en Pila" << endl;
        cout << "6-Encolar en Cola" << endl;
        cout << "7-Desencolar en Cola" << endl;
        cout << "8-Frente de Cola" << endl;
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
                try {
                    cout << "Min relativo de Pila: " << pila.getMinRel() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
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
                try {
                    cout << "Frente de Cola: " << cola.front() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
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

// Menú interactivo para Ordenamiento
void menuOrdenamiento() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arrBubble = arr;
    vector<int> arrSelection = arr;
    vector<int> arrQuick = arr;
    int opc;

    do {
        cout << "\n1-Bubble Sort" << endl;
        cout << "2-Selection Sort" << endl;
        cout << "3-QuickSort" << endl;
        cout << "4-Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> opc;

        switch (opc) {
            case 1:
                bubbleSort(arrBubble);
                cout << "Bubble Sort: ";
                imprimirVector(arrBubble);
                break;
            case 2:
                selectionSort(arrSelection);
                cout << "Selection Sort: ";
                imprimirVector(arrSelection);
                break;
            case 3:
                quickSort(arrQuick, 0, arrQuick.size() - 1);
                cout << "QuickSort: ";
                imprimirVector(arrQuick);
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
void obtenerCombinaciones(vector<int>& set, vector<int>& comb, int start, vector<vector<int>>& res) {
    if (start == set.size()) {
        res.push_back(comb);
        return;
    }
    
    obtenerCombinaciones(set, comb, start + 1, res);
    
    comb.push_back(set[start]);
    obtenerCombinaciones(set, comb, start + 1, res);
    comb.pop_back();
}

// Función para imprimir combinaciones
void imprimirCombinaciones(const vector<vector<int>>& combs) {
    for (const auto& comb : combs) {
        cout << "{ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

// Menú interactivo para Recursividad
void menuRecursividad() {
    int opc, n;
    vector<int> set = {1, 2, 3};
    vector<int> comb;
    vector<vector<int>> res;

    do {
        cout << "\n1-Fibonacci Recursivo" << endl;
        cout << "2-Fibonacci Iterativo" << endl;
        cout << "3-Combinaciones de un Conjunto" << endl;
        cout << "4-Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingrese el valor de n: "; cin >> n;
                cout << "Fibonacci recursivo de " << n << " es: " << fibonacciRecursivo(n) << endl;
                break;
            case 2:
                cout << "Ingrese el valor de n: "; cin >> n;
                cout << "Fibonacci iterativo de " << n << " es: " << fibonacciIterativo(n) << endl;
                break;
            case 3:
                obtenerCombinaciones(set, comb, 0, res);
                cout << "Combinaciones del conjunto {1, 2, 3}:" << endl;
                imprimirCombinaciones(res);
                break;
            case 4:
                cout << "Saliendo del menú de Recursividad." << endl;
                Sleep(2000);
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opc != 4);
}

// --- Árbol Binario de Búsqueda ---

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

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

    void inOrder(TreeNode* node, vector<int>& nodes) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left, nodes);
        nodes.push_back(node->val);
        inOrder(node->right, nodes);
    }

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

    void insertar(int val) {
        root = insertar(root, val);
    }

    bool buscar(int val) {
        return buscar(root, val);
    }

    void rebalancear() {
        vector<int> nodes;
        inOrder(root, nodes);
        root = construirArbolBalanceado(nodes, 0, nodes.size() - 1);
    }

    void imprimirEnOrden() {
        vector<int> nodes;
        inOrder(root, nodes);
        for (int val : nodes) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Menú interactivo para Árbol Binario de Búsqueda
void menuArbol() {
    BST arbol;
    int opc, val;

    do {
        cout << "\n1-Insertar en Árbol" << endl;
        cout << "2-Buscar en Árbol" << endl;
        cout << "3-Imprimir Árbol" << endl;
        cout << "4-Rebalancear Árbol" << endl;
        cout << "5-Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingrese el valor: "; cin >> val;
                arbol.insertar(val);
                break;
            case 2:
                cout << "Ingrese el valor a buscar: "; cin >> val;
                cout << (arbol.buscar(val) ? "Encontrado" : "No encontrado") << endl;
                break;
            case 3:
                cout << "Árbol en orden: ";
                arbol.imprimirEnOrden();
                break;
            case 4:
                arbol.rebalancear();
                cout << "Árbol rebalanceado." << endl;
                break;
            case 5:
                cout << "Saliendo del menú de Árbol Binario." << endl;
                Sleep(2000);
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opc != 5);
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
        cout << "5-Arbol Binario" << endl;
        cout << "6-Salir" << endl;
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
                menuArbol();
                break;
            case 6: 
                salir(); 
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
        Sleep(3000);
    } while (opc != 6);
    return 0;
}
