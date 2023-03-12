#ifndef PRACTICASDATOS2_NODE_H
#define PRACTICASDATOS2_NODE_H
#include <iostream>

using namespace std;

class List;

class Collector;

// clase nodo con lista enlazada
class Node {
    friend class List;
    friend class Collector;
public:
    Node();
    // Constructor con parámetros
    Node(int data);

    void* operator new(size_t size);

    void operator delete(void* p);
    static void setReciclaje(Collector* collector);
    static Collector* reciclaje;


private:
    int data;
    Node* next; // puntero al siguiente nodo

};


#endif
