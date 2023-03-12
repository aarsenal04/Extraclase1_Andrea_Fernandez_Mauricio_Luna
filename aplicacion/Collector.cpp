/**
 * @file Collector.cpp
 * @version 1.0
 * @date 12/03/2023
 * @authors Mauricioluna & AndreaFernandez
 *
 */

/**
 * @brief Es el responsable de reciclar la memoria liberada en List.
 */

#include "Collector.h"
#include "Node.h"

using namespace std;

/**
 * @brief Inicializa un objeto Collector poniendo el puntero al primer nodo nulo y tamaño cero.
 */
Collector::Collector() {
    Chead = nullptr;
    size = 0;
}

/**
 * @brief insertNode() agrega un nodo al inicio de la lista enlazada del objeto Collector.
 * @param node nuevo head en la lista si se encuentra vacía.
 */
void Collector::insertNode(Node *node) {
    if (Chead == nullptr){
        Chead = node;
        size++;
        return;
    } else{
        node->next = Chead;
        Chead = node;
        size++;
    }

}

/**
 * @brief printCollector() imprime los nodos almacenado en Collector.
 */
void Collector::printCollector() const {
    /**
     * @brief Puntero temporal al head del Collector.
     */
    Node* temp = Chead;
    /**
     * @return mensaje que avisa cuando el head en Collector es nulo.
     */
    if (Chead == nullptr){
        cout << "Collector vacio" << endl;
        return;
    }

    cout << "Collector: ";
    /**
     * @brief Recorre la lista enlazada desde el nodo Chead al siguiente nodo en cada iteración hasta el final.
     */
    while (temp != nullptr) {
        /**
         * @return dirección de memoria del nodo actual.
         */
        cout << temp << " ";
        temp = temp->next;
    }
}

/**
 * @brief elimina un nodo empezando la lista.
 * @return si el collector está vacío devuelve nulo, si no, devuelve el nodo por reutilizar.
 */
Node* Collector::giveNode() {
    if (Chead == nullptr){
        return nullptr;
    } else{
        /**
         * @brief nuevo puntero nodeTogive en Chead (primer nodo en Collector).
         */
        Node* nodeToGive = Chead;
        /**
         * @brief se actualiza Chead para el siguiente nodo en Collector.
         */
        Chead = Chead->next;
        /**
         * @brief Se establece el puntero next del nodo a devolver en nulo (separado de la lista enlazada).
         */
        nodeToGive->next = nullptr;
        /**
         * @brief Contador de tamaño del Collector se reduce en 1.
         */
        size--;
        /**
         * @brief Vuelve al nodo recuperado.
         */
        return nodeToGive;
    }
}

/**
 *
 * @brief getSize() obtiene el tamaño de nodos almacenados en Collector.
 * @return valor actual de size en Collector.
 * size se actualiza cuando se insertan/eliminan nodos de Collector.
 */
int Collector::getSize() {
    return size;
}