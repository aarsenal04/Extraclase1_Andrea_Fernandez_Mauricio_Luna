#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next; // puntero al siguiente nodo

    // constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // constructor con parametros
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    int getData() const {
        return data;
    }

    void setData(int data) {
        Node::data = data;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

    void* operator new(size_t size);

    void operator delete (void* ptr);


};

class Linkedlist {
    Node* head;

public:

    Linkedlist() { head = NULL; }

    void insertNode(int);

    Node *getHead() const;

    void setHead(Node *head);

    void printList();

    void deleteNode(int);
};

void Linkedlist::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    // tamaño de la lista enlazada
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    // revisando la posición de la lista
    if (ListLen < nodeOffset) {
        cout << "Index out of range"
             << endl;
        return;
    }

    // Declaración de temp1
    temp1 = head;

    // borrar head
    if (nodeOffset == 1) {

        // modificar head
        head = head->next;
        delete temp1;
        return;
    }

    // encontrar el nodo en la lista para modificarlo
    while (nodeOffset-- > 1) {


        temp2 = temp1;


        temp1 = temp1->next;
    }

    // cambiar el puntero
    temp2->next = temp1->next;

    // borrar el nodo
    delete temp1;
}

// insertar nuevo nodo
void Linkedlist::insertNode(int data)
{
    // Crear nuevo nodo
    Node* newNode = new Node(data);

    // Asignación al head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // revisar hasta el final de la lista
    Node* temp = head;
    while (temp->next != NULL) {

        // modificar temp
        temp = temp->next;
    }

    // insertar por último
    temp->next = newNode;
}

// Función para imprimir los nodos de la lista
void Linkedlist::printList()
{
    Node* temp = head;

    // revisar lista vacía
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // revisar lista
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *Linkedlist::getHead() const {
    return head;
}

void Linkedlist::setHead(Node *head) {
    Linkedlist::head = head;
}

int main()
{
    Linkedlist list;

    // insertando nodos
    list.insertNode(1);
    list.insertNode(5);

    cout << "Elements of the list are: ";

    // imprimir lista
    list.printList();
    cout << endl;

    cout << list.getHead() << endl;
    return 0;
}
