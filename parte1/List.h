//
// Created by mauluna52 on 9/03/23.
//

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
  //  void deleteNode(Node* node);
    void printList();

};


#endif //PRACTICASDATOS2_LIST_H
