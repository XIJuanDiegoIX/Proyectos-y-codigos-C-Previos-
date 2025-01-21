#include <iostream>

class Pila {
public:
    Pila() { siguiente = nullptr; }
    Pila(int dato) { siguiente = nullptr; this->dato = dato; }
    int dato;
    Pila* siguiente;
};

class Lista {
public:
    Lista() { head = nullptr; }
    void push(int dato);
    void pop(int dato);
    void peek();
    void print();
    Pila* head;
};

void Lista::push(int dato) {
    Pila* v = new Pila(dato);
    v->siguiente = head;
    if (head == nullptr) {
        head= v;
    }
    head = v;
}

void Lista::pop(int dato){
    if(head==nullptr){
       std::cout<<"no hay cabeza que eliminar"<<std::endl;
    }
    else{
        Pila* temp=head;
        head=head->siguiente;
        delete temp;
    }
}

void Lista::peek()
{
    Pila* temp = head;
    if (temp == nullptr) {
        std::cout << "Empty List" << std::endl;
        return;
    }
    else{
        std::cout << temp->dato << " "<<std::endl;
    }

}

int main() {
    Lista* list = new Lista();
    list->push(1);
    list->push(2);
    list->push(3);
    list->peek();
    list->pop(0);
    list->peek();
    list->pop(0);
    list->peek();
    list->pop(0);
    list->peek();

    return 0;
}
