//
// Created by mauluna52 on 9/03/23.
//

#ifndef PRACTICASDATOS2_NODE_H
#define PRACTICASDATOS2_NODE_H
#include <iostream>

using namespace std;

// Node class to represent
// a node of the linked list.
class Node {
public:

    int data;

    Node* next; // puntero al siguiente nodo
    
    // Default constructor
    Node();

    // Parameterised Constructor
    Node(int data);

    int getData() const;

    void setData(int data);
};


#endif //PRACTICASDATOS2_NODE_H
