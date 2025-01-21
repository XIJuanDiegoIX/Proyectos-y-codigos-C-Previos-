#include <iostream>
#include <vector>
#include <random>
#include <stack>
#include <limits>
#include <stdexcept>
#include <windows.h>

using namespace std;

// --- Lista Ligada ---

// Nodo de la lista ligada
struct Node {
    int data; // Valor del nodo
    Node* next; // Apuntador al siguiente nodo

    // Constructor para inicializar un nodo
    Node(int val) : data(val), next(nullptr) {}
};

// Convierte los valores de la lista a su suma acumulativa
void transformarSumaAcumulativa(Node* head) {
    int sumaAcumulativa = 0;
    Node* current = head;

    // Recorre la lista y actualiza los valores
    while (current != nullptr) {
        sumaAcumulativa += current->data;
        current->data = sumaAcumulativa;
        current = current->next;
    }
}

// Imprime todos los nodos de la lista
void imprimirLista(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Agrega un nodo al final de la lista
void agregarNodo(Node*& head, int val) {
    if (head == nullptr) {
        head = new Node(val); // Si la lista está vacía, crea el primer nodo
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(val); // Agrega un nuevo nodo al final
    }
}

// Menú interactivo para trabajar con la lista ligada
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

        switch (opc) {
            case 1: // Agregar un nodo con un valor dado
                cout << "Ingrese el valor del nodo: "; cin >> val;
                agregarNodo(head, val); 
                break;
            case 2: // Agregar múltiples nodos
                cout << "Ingrese la cantidad de nodos: "; cin >> cant;
                cout << "¿Desea generarlos de manera aleatoria?" << endl;
                cout << "1-Si   2-No" << endl;
                cout << "Ingrese una opcion: "; cin >> res;
                if (res == 1) { // Generar valores aleatorios
                    for (int i = 0; i < cant; i++) {
                        val = rand() % 100 + 1; // Número aleatorio entre 1 y 100
                        agregarNodo(head, val);
                    }
                } else if (res == 2) { // Solicitar valores manualmente
                    for (int i = 0; i < cant; i++) {
                        cout << "Ingrese el valor del nodo " << (i + 1) << ": "; cin >> val;
                        agregarNodo(head, val);
                    }
                } else {
                    cout << "Opcion invalida." << endl;
                }
                break;
            case 3: // Imprimir la lista
                cout << "La lista es: ";
                imprimirLista(head);
                break;
            case 4: // Convertir e imprimir la suma acumulativa
                transformarSumaAcumulativa(head);
                cout << "Lista transformada: ";
                imprimirLista(head);
                break;
            case 5: // Salir
                cout << "\nSaliendo del menú de lista ligada." << endl;
                Sleep(2000);
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opc != 5);
}

// --- Pilas y Colas ---
// Clase para trabajar con pilas que también permite obtener el mínimo
class MinStack {
private:
    stack<int> stk; // Pila principal
    stack<int> minStk; // Pila auxiliar para almacenar los mínimos

public:
    void push(int val) {
        stk.push(val);
        if (minStk.empty() || val <= minStk.top()) {
            minStk.push(val); // Actualiza el mínimo si es necesario
        }
    }

    void pop() {
        if (!stk.empty()) {
            if (stk.top() == minStk.top()) {
                minStk.pop(); // Elimina el mínimo si coincide
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
};

// Clase que implementa una cola usando dos pilas
class QueueUsingStacks {
private:
    stack<int> stk1; // Pila para almacenar nuevos elementos
    stack<int> stk2; // Pila para eliminar elementos

public:
    void enqueue(int val) {
        stk1.push(val); // Agrega el elemento a la primera pila
    }

    void dequeue() {
        if (stk2.empty()) {
            while (!stk1.empty()) { // Transfiere elementos si la segunda pila está vacía
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
        }
        throw runtime_error("La cola está vacía.");
    }

    bool isEmpty() {
        return stk1.empty() && stk2.empty(); // Verifica si ambas pilas están vacías
    }
};

// Función para mostrar el menú completo estático... 
// Más adelante puedo fragmentar toda parte user copiladores
// --- Ordenamiento ---

// Imprime los elementos de un vector
void imprimirVector(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Ordenamiento por Burbuja (Bubble Sort)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // Recorre el vector varias veces
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Intercambia elementos si están en desorden
            }
        }
    }
}

// Ordenamiento por Selección (Selection Sort)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    // Encuentra el menor elemento y lo coloca al inicio
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Encuentra el índice del elemento mínimo
            }
        }
        swap(arr[i], arr[minIndex]); // Intercambia el menor con la posición actual
    }
}

// Función para particionar el vector (usada en QuickSort)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // Selecciona el primer elemento como pivote
    int left = low + 1, right = high;

    // Coloca elementos menores al pivote a la izquierda y mayores a la derecha
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
    swap(arr[low], arr[right]); // Coloca el pivote en su posición final
    return right;
}

// Ordenamiento rápido (QuickSort)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partición del vector
        quickSort(arr, low, pi - 1); // Ordena la mitad izquierda
        quickSort(arr, pi + 1, high); // Ordena la mitad derecha
    }
}

// Menú interactivo para trabajar con métodos de ordenamiento
void menuOrdenamiento() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arrBubble = arr, arrSelection = arr, arrQuick = arr;
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

// Calcula el n-ésimo número de Fibonacci de forma recursiva
int fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n; // Caso base
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

// Calcula el n-ésimo número de Fibonacci de forma iterativa
int fibonacciIterativo(int n) {
    if (n <= 1) {
        return n; // Caso base
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Obtiene todas las combinaciones posibles de un conjunto
void obtenerCombinaciones(vector<int>& set, vector<int>& comb, int start, vector<vector<int>>& res) {
    if (start == set.size()) {
        res.push_back(comb); // Agrega la combinación actual
        return;
    }

    // Excluye el elemento actual
    obtenerCombinaciones(set, comb, start + 1, res);

    // Incluye el elemento actual
    comb.push_back(set[start]);
    obtenerCombinaciones(set, comb, start + 1, res);
    comb.pop_back(); // Elimina el elemento para explorar otras combinaciones
}

// Imprime todas las combinaciones de un conjunto
void imprimirCombinaciones(const vector<vector<int>>& combs) {
    for (const auto& comb : combs) {
        cout << "{ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

// Menú interactivo para trabajar con recursividad
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

// --- Árbol Binario de Búsqueda (BST) ---

// Nodo del Árbol Binario de Búsqueda
struct TreeNode {
    int val; // Valor del nodo
    TreeNode* left; // Subárbol izquierdo
    TreeNode* right; // Subárbol derecho

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Clase que implementa un Árbol Binario de Búsqueda
class BST {
private:
    TreeNode* root; // Raíz del árbol

    // Inserta un valor en el árbol (de manera recursiva)
    TreeNode* insertar(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val); // Crea un nodo nuevo si la posición está vacía
        }
        if (val < node->val) {
            node->left = insertar(node->left, val); // Inserta en el subárbol izquierdo
        } else {
            node->right = insertar(node->right, val); // Inserta en el subárbol derecho
        }
        return node;
    }

    // Busca un valor en el árbol (de manera recursiva)
    bool buscar(TreeNode* node, int val) {
        if (node == nullptr) {
            return false; // Valor no encontrado
        }
        if (node->val == val) {
            return true; // Valor encontrado
        }
        if (val < node->val) {
            return buscar(node->left, val); // Busca en el subárbol izquierdo
        } else {
            return buscar(node->right, val); // Busca en el subárbol derecho
        }
    }

    // Recorre el árbol en orden (In-Order Traversal)
    void inOrder(TreeNode* node, vector<int>& nodes) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left, nodes); // Recorre el subárbol izquierdo
        nodes.push_back(node->val); // Visita el nodo
        inOrder(node->right, nodes); // Recorre el subárbol derecho
    }

    // Reconstruye un árbol balanceado a partir de un vector ordenado
    TreeNode* construirArbolBalanceado(vector<int>& nodes, int start, int end) {
        if (start > end) {
            return nullptr; // Caso base
        }
        int mid = start + (end - start) / 2; // Encuentra el elemento medio
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = construirArbolBalanceado(nodes, start, mid - 1); // Construye el subárbol izquierdo
        node->right = construirArbolBalanceado(nodes, mid + 1, end); // Construye el subárbol derecho
        return node;
    }

public:
    BST() : root(nullptr) {}

    // Inserta un valor en el árbol
    void insertar(int val) {
        root = insertar(root, val);
    }

    // Busca un valor en el árbol
    bool buscar(int val) {
        return buscar(root, val);
    }

    // Rebalancea el árbol
    void rebalancear() {
        vector<int> nodes;
        inOrder(root, nodes);
        root = construirArbolBalanceado(nodes, 0, nodes.size() - 1);
    }

    // Imprime los valores del árbol en orden
    void imprimirEnOrden() {
        vector<int> nodes;
        inOrder(root, nodes);
        for (int val : nodes) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// Menú interactivo para trabajar con árboles binarios
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

// Función para mostrar mensaje de despedida
void salir() {
    cout << "Gracias por usar este programa." << endl;
}

// --- Programa Principal ---
int main() {
    int opc;

    do {
        cout << "\n1-Lista ligada" << endl;
        cout << "2-Pilas y colas" << endl;
        cout << "3-Ordenamiento" << endl;
        cout << "4-Recursividad" << endl;
        cout << "5-Árbol Binario" << endl;
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
                cout << "Opción inválida." << endl;
        }
        Sleep(3000); // Pausa de 3 segundos antes de mostrar el menú nuevamente
    } while (opc != 6);

    return 0;
}
