

/**
 * @file Node.cpp
 * @version 1.0
 * @date 11/03/2023
 * @authors Mauricioluna & AndreaFernandez
 * @title Node de la aplicación
 * @brief Almacena un valor de tipo int y un
 * puntero al siguiente así como sus método
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

Node::Node(int d) {
    this->data = d;
    next = nullptr;
}
/**
 * @brief implementación el operador que reserva memoria requerida para crear un nuevo nodo con malloc.
 */

void* Node::operator new(size_t size) {
    if (reciclaje == nullptr || reciclaje->getSize() == 0) {
        return ::operator new(size); //Este size se puede modificar para asignar el espacio que se desea
    } else {
        return reciclaje->giveNode();
    }
}

void Node::operator delete(void* p) {
    Node* nodeToDelete = static_cast<Node*>(p);
    if (reciclaje != nullptr){
        reciclaje->insertNode(nodeToDelete);
    }
    else{
        ::operator delete(nodeToDelete);
    }
}

void Node::setReciclaje(Collector *collector) {
    reciclaje = collector;
}
Collector* Node::reciclaje = nullptr;

