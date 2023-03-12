#include "List.h"
#include "Collector.h"
#include "Node.h"

using namespace std;

List::List() {
    size = 0;
    head = nullptr;
}

int List::getHead() {
    if (size != 0){
        return head->getData();
    } else{
        cout << "La lista se encuentra vacía" << endl;
    }
}

void List::insertLast(int data) {
    //Falta implementar funcion que verifique si hay una memoria disponible en collector
    Node* newNode = new Node(data);
    if (head == nullptr){
        head = newNode;
        size++;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    size++;
}

void List::insertFirst(int data) {
    //Falta implementar funcion que verifique si hay una memoria disponible en collector
    Node* newNode = new Node(data);
    if (head == nullptr){
        head = newNode;
        size++;
        return;
    } else{
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        size++;
    }
}

void List::printList() {
    Node* temp = head;

    if (head == nullptr){
        cout << "lista vacía" << endl;
        return;
    }

    cout << "Lista: ";

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}