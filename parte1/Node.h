#ifndef PRACTICASDATOS2_NODE_H
#define PRACTICASDATOS2_NODE_H
#include <iostream>

using namespace std;

// clase nodo con lista enlazada
class Node {
public:

    int data;

    Node* next; // puntero al siguiente nodo
    
    // Constructor
    Node();

    // Constructor con parámetros
    Node(int data);

    int getData() const;

    void setData(int data);
};


#endif
