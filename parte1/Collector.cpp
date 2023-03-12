#include "Collector.h"
#include "Node.h"
using namespace std;


Collector::Collector() {
    Chead = nullptr;
    size = 0;
}

void Collector::insertNode(Node *node) {
    if (Chead == nullptr){
        Chead = node;
        size++;
        return;
    } else{
   //     node->data = data;
        node->next = Chead;
        Chead = node;
        size++;
    }

}


void Collector::printCollector() const {
    Node* temp = Chead;

    if (Chead == nullptr){
        cout << "Collector vacío" << endl;
        return;
    }

    cout << "Collector: ";

    while (temp != nullptr) {
        cout << temp << " ";
        temp = temp->next;
    }
}

Node* Collector::giveNode() {
    if (Chead == nullptr){
        return nullptr;
    } else{
        Node* nodeToGive = Chead;
        Chead = Chead->next;
        nodeToGive->next = nullptr;
        size--;
        return nodeToGive;
    }
}

int Collector::getSize() {
    return size;
}

