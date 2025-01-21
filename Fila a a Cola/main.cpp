
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
    Lista() { head = tail = nullptr; }
    void enqueue(int dato);

    void dequeue(int dato);

    void print();
    void front();
	void rear();
    Pila* head;
    Pila* tail;
};


void Lista::enqueue(int dato) {
    Pila* v = new Pila(dato);
    if (tail == nullptr) {
        head = tail = v;
    } else {
        tail->siguiente = v;
        tail = v;
    }
}


void Lista::dequeue(int dato){
    if(head==nullptr){
       std::cout<<"no hay cabeza que eliminar"<<std::endl;
    }
    else{
        Pila* temp=head;
        head=head->siguiente;
        delete temp;
    }
}

void Lista::front() {
    Pila* temp = head;
    if (temp == nullptr) {
        std::cout << "Empty List" << std::endl;
        return;
    }
    else{
        std::cout << temp->dato << " "<<std::endl;
        }

    std::cout << std::endl;
}
void Lista::rear() {
    Pila* temp = tail;
    if (temp == nullptr) {
        std::cout << "Empty List" << std::endl;
        return;
    }
    else{
        std::cout << temp->dato << " "<<std::endl;
        }

    std::cout << std::endl;
}
void Lista::print() {
    Pila* temp = head;
    if (temp == nullptr) {
        std::cout << "Empty List" << std::endl;
        return;
    }
    while (temp != nullptr) {
        std::cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}

int main() {
    Lista* list = new Lista();
    list->enqueue(1);
    list->enqueue(2);
    list->enqueue(3);
    list->enqueue(4);
    list->enqueue(5);
    list->front();
    list->rear();
    list->dequeue(0);
    list->front();
    list->dequeue(0);
    list->front();
    list->dequeue(0);
    list->front();
    list->dequeue(0);
    list->front();
    list->dequeue(0);
    list->front();

    return 0;
}
