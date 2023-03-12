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
 * @brief Constructor de la clase List, inicializa el tamaño de la lista en 0 y el puntero al head de la lista como nulo.
 */
List::List() {
    size = 0;
    head = nullptr;
}

/**
 * @brief Destructor de la clase List.
 */
List::~List() {}

/**
 * @brief Método para insertar un nuevo nodo al final de la lista.
 * @param data
 */
void List::insertLast(int data) {
    /**
     * @brief Creación de un nuevo nodo con el valor indicado.
     */
    Node* newNode = new Node(data);
    /**
     * @brief Si head es nulo, se define el nuevo nodo como nuevo head en la lista.
     */
    if (head == nullptr){
        head = newNode;
        /**
         * @brief Entonces se incrementa el tamaño de la lista.
         */
        size++;
        return;
    }
    /**
     * @brief si no entonces recorre la lista hasta encontrar el último nodo y se define el nuevo nodo como el siguiente.
     */
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

/**
 * @brief Método para insertar un nuevo nodo al principio de la lista.
 * @param data
 */
void List::insertFirst(int data) {
    /**
     * @brief Se crea un nuevo nodo con el valor indicado.
     */
    Node* newNode = new Node(data);
    /**
     * Si head es nulo, se define el nuevo nodo como la cabeza de la lista.
     */
    if (head == nullptr){
        head = newNode;
        /**
         * @brief entonces se incrementa el tamaño de la lista.
         */
        size++;
        return;
    /**
     * @brief si no, entonces se define el siguiente nodo del nuevo nodo como head.
     */
    } else{
        newNode->data = data;
        newNode->next = head;
        /**
         * @brief y se define el nuevo nodo como head de la lista.
         */
        head = newNode;
        size++;
    }
}

/**
 * @brief deleteNode elimina un nodo con un valor específico de la lista.
 * @param value se desea eliminar de la lista.
 */
void List::deleteNode(int value) {
    /**
     * @brief Se verifica si la lista está vacía
     * @return mensaje que indica el estado de la lista
     */
    if (head == nullptr){
        cout << "lista vacia" << endl;
    }

    /**
     * @brief se verifica si el valor por eliminar se encuentra en el primer nodo de la lista.
     */
    if (head->data == value) {
        /**
         * @brief Se crea un puntero que apunta a head , asigna el nodo siguiente de head como nuevo nodo del mismo.
         */
        Node* deleted_node = head;
        head = head->next;
        /**
         * @brief Se establece el siguiente nodo como nulo.
         * @return dirección de memoria de delte_node.
         */
        deleted_node->next = nullptr;
        cout << deleted_node << endl;
        /**
         * @brief y finalmente se elimina
         */
        delete deleted_node;
        return;
    }

    /**
     * @brief Si el valor no se encuentra en el primer nodo, dentro del bucle while se busca el nodo que contiene el valor indicado.
     */
    Node* curr_node = head;
    while (curr_node->next != nullptr) {
        /**
         * @brief Si se encuentra entonces se crea un puntero deleted_node que apunta al nodo que contiene el valor, se define el siguiente nodo del nodo actual como el siguiente nodo del que contiene el valor.
         */
        if (curr_node->next->data == value) {
            Node* deleted_node = curr_node->next;
            curr_node->next = curr_node->next->next;
            /**
             * @brief se define el siguiente nodo de deleted_node como nulo
             * @return dirección de memoria de deleted_node.
             */
            deleted_node->next = nullptr;
            /**
             * @brief finalmente se elimina.
             */
            delete deleted_node;
            return;
        }
        curr_node = curr_node->next;
    }

    /**
     * @return Si no se encuentra el valor en la lista, se imprime un mensaje indicando que el valor no se encontró.
     */
    cout << "El valor no se encontro en la lista" << endl;
}

/**
 * @brief printList recorre la lista.
 * @return cada valor y su dirección de memoria.
 */
void List::printList() const {
    Node* temp = head;
    /**
     * @brief verifica si se encuentra la lista vacía.
     * @return mensaje que lo indica y devuelve la función.
     */
    if (head == nullptr){
        cout << "lista vacia" << endl;
        return;
    }
    cout << "Lista: ";
    /**
     * @brief Recorre la lista. Cuando temp es nulo, termina el bucle y la función se devuelve.
     * @return en cada iteración imprime el valor y dirección de memoria de temp.
     */
    while (temp != nullptr) {
        cout << "Valor: "<< temp->data << " Memoria: "<< temp << endl;
        temp = temp->next;
    }
}