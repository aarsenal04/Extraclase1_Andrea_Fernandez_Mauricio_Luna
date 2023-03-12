#ifndef PRACTICASDATOS2_COLLECTOR_H
#define PRACTICASDATOS2_COLLECTOR_H

class Node;

class Collector {


private:
    Node* Chead;
    int size;

public:


    Collector();

    void insertNode(Node* node);

    int getSize();

    void printCollector() const;

    Node* giveNode();

};



#endif