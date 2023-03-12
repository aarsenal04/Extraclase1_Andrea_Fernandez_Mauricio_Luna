/**
 * @file List.h
 * @version 1.0
 * @date 12/03/2023
 * @authors Mauricioluna & AndreaFernandez
 *
 */

/**
 * @brief Definición de List.
 */

/**
 * @brief Comprueba que el header no se incluya varias veces en su mismo origen.
 * entonces si no se ha definido, los demás archivos pueden funcionar, si no entonces omite su funcionamiento.
 */
#ifndef PRACTICASDATOS2_LIST_H
#define PRACTICASDATOS2_LIST_H

#include "Node.h"
#include "Collector.h"

/**
 * @brief declaración de la clase List y permisos a Collector para que tenga aceeso al private de la clase List.
 */
class List {
    friend class Collector;


public:
/**
 * @brief Constructor y destructor de List.
 */
    List();
    ~List();

    /**
     *
     * @param data se inserta al final, principio de la lista.
     * @brief Luego se elimina un nodo value de la lista y se imprimen los valores de todos los nodos de la Lista.
     */
    void insertLast(int data);
    void insertFirst(int data);
    void deleteNode(int value);
    void printList() const;

private:
/**
 * @brief Puntero a un nodo (head de la lista).
 * size contiene el número de nodos en la lista.
 */
    Node* head;
    int size;
};

#endif