#ifndef PRACTICASDATOS2_LIST_H
#define PRACTICASDATOS2_LIST_H

#include "Node.h"
#include "Collector.h"

class List {
    friend class Collector;

public:
    List();
    ~List();

    void insertLast(int data);
    void insertFirst(int data);
    void deleteNode(int value);
    void printList() const;

    //static Collector* reciclaje;
private:
    // Puntero al collector
    Node* head;
    int size;
};

#endif