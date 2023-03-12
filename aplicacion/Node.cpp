/**
 * @file Node.cpp
 * @version 1.0
 * @date 11/03/2023
 * @authors Mauricioluna & AndreaFernandez
 * @title Node de la aplicación
 * @brief Almacena un valor de tipo int y un
 * puntero al siguiente así como sus métodos
 * para consultar o modificar sus datos.
 */

#include "Node.h"
#include "List.h"

using namespace std;

/**
 * @brief Su constructor inicializa el dato en 0 y su puntero al siguiente nodo como nulo.
 */
Node::Node() {
    data = 0;
    next = nullptr;
}

/**
 * @brief toma un argumento entero, inicializa el dato a su valor pasado y los punteros al siguiente nodo, luego el eliminado a nulo.
 * @param d
 */
Node::Node(int d) {
    this->data = d;
    next = nullptr;
}
/**
 * @brief Sobrecarga al operador new para la clase Node que permite crear un nuevo obj Node en la memoria dinámica.
 */
void* Node::operator new(size_t size) {
    /**
     * @brief Comprueba si hay objetos Node eliminados en reciclaje
     * Si reciclaje es nulo o si no tiene nodos, se crea un nuevo obj Node
     * size asigna memoria del tamaño requerido
     */
    if (reciclaje == nullptr || reciclaje->getSize() == 0) {
        return ::operator new(size);
    } else {
        /**
         * @brief Si hay nodos en el recolector, se devuelve el primer nodo almacenado en el recolector.
         * (se reutiliza la memoria)
         */
        return reciclaje->giveNode();
    }
}

/**
 * @brief sobrecarga del operador delete para liberar memoria dinámicamente utilizada por los obj Node.
 * @param p
 */
void Node::operator delete(void* p) {
    /**
     * @brief Convierte el puntero genérico como argumento a la función en un puntero específico Node.
     */
    Node* nodeToDelete = static_cast<Node*>(p);
    /**
     * @brief Se comprueba si reciclaje está inicializado.
     */
    if (reciclaje != nullptr){
        /**
         * @brief Se inserta el nodo en el recolector para luego utilizarlo en caso de que exista reciclaje.
         */
        reciclaje->insertNode(nodeToDelete);
    }
    else{
        /**
         * @brief Se libera memoria utilizada por el nodo si no hay recolector.
         */
        ::operator delete(nodeToDelete);
    }
}

/**
 * @brief Método público estático de Node para definir el recolector de tipo Collector para la clase Node.
 * @param collector
 */
void Node::setReciclaje(Collector *collector) {
    reciclaje = collector;
}
/**
 * @brief Se inicializa el puntero estático de Node (reciclaje) como nulo que indica la falta de recolector.
 */
Collector* Node::reciclaje = nullptr;