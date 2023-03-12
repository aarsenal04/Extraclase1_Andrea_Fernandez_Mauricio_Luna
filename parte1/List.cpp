/**
 * @file List.cpp
 * @version 1.0
 * @date 11/03/2023
 * @authors Mauricioluna & AndreaFernandez
 * @title Lista de la aplicación
 * @brief Lista enlazada simple formada por objetos de tipo Node.
 */

#include "List.h"


using namespace std;

/**
 * @brief Este es el constructor, el cual inicializa el tamaño de la lista size en 0, su head en nullptr y crea un nuevo obj Collector guardándolo en el puntero de reciclaje.
 * @return no devuelve valor.
 */
List::List() {
    size = 0;
    head = nullptr;
}

List::~List() {}

/**
 *
 * @brief en este método se inserta un nuevo nodo al final de la lista con el valor data.
 * @param data El valor que se le asignará al nuevo nodo.
 * @return No devuelve valor
 */
void List::insertLast(int data) {
/**
 * @brief primero se verifica si existe un nodo disponible en Collector con el metódo available().
 */
    Node* newNode = new Node(data);
    /**
     * @brief entonces si Collector está vacío, se crea un nuevo nodo newNode con el valor data y se agrega al final de la lista.
     */
    if (head == nullptr){
        head = newNode;
        size++;
        return;
    }
    /**
     * @brief pero si Collector tiene nodos disponibles, los utiliza reciclaje->darNodo() y lo agrega al final de la lista.
     */
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

/**
 *
 * @brief En este método se inserta un nuevo nodo al inicio de la lista con el valor data.
 * @param data EL valor por asignar al nuevo nodo.
 * @return no devuelve valor.
 */
void List::insertFirst(int data) {
/**
 * @brief primero verifica si existe un nodo disponible en Collector con available().
 */
    Node* newNode = new Node(data);
    /**
     * @brief entonces si Collector está vacío, crea un nuevo nodo newNode() con el valor data.
     */
    if (head == nullptr){
        head = newNode;
        size++;
        return;
        /**
             * @brief si no, entonces agrega un nuevo nodo al inicio de la lista.
             */
    } else{
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        size++;
    }
}

/**
 *
 * @brief se utiliza para eliminar un nodo de la lista dependiendo de lo que contenga data.
 */
void List::deleteNode(int value) {
    if (head == nullptr){
        cout << "lista vacía" << endl;
    }

    if (head->data == value) {
        Node* deleted_node = head;
        head = head->next;
        deleted_node->next = nullptr;
        cout << deleted_node << endl;
        delete deleted_node;
        return;
    }

    // Buscar el nodo que contiene el valor
    Node* curr_node = head;
    while (curr_node->next != nullptr) {
        if (curr_node->next->data == value) {
            Node* deleted_node = curr_node->next;
            curr_node->next = curr_node->next->next;
            deleted_node->next = nullptr;
            delete deleted_node;
            return;
        }
        curr_node = curr_node->next;
    }

    // Si no se encuentra el valor en la lista
    cout << "El valor no se encontró en la lista" << endl;


    /**
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr){
        if (current->data == data){
            if (prev == nullptr){
                head = current->next;
            } else {
                prev->next = current->next;
            }
            cout << current->data;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
     */
}

/**
 * @brief En esta función se comienza con la declaración de un puntero al nodo temp inicializado con temp.
 * @return devuelve el contenido de la lista.
 */
void List::printList() const {
    Node* temp = head;
    /**
     * @brief revisa si la lista está vacía.
     * @return devuelve un mensaje de lista vacía y vuelve a printList().
     */
    if (head == nullptr){
        cout << "lista vacía" << endl;
        return;
    }
    cout << "Lista: ";
    /**
     * @brief si no está vacía.
     * @return devuelve el valor de data de cada nodo en la lista desde head.
     */
    while (temp != nullptr) {
        cout << "Valor: "<< temp->data << " Memoria: "<< temp << endl;
        temp = temp->next;
    }
}
