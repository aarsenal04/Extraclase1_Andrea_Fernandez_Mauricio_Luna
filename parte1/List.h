#ifndef PRACTICASDATOS2_LIST_H
#define PRACTICASDATOS2_LIST_H
#include "Node.h"
#include "Collector.h"

class List {

public:

    int size;
    Node* head;
    Collector* reciclaje;

    List();

    int getHead();
    void insertLast(int data);
    void insertFirst(int data);
    void printList();

};

#endif