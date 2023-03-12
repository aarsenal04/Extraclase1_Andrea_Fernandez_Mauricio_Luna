/**
 * @file main.cpp
 * @version 1.0
 * @date 11/03/2023
 * @authors Mauricioluna & AndreaFernandez
 * @title Main de la aplicación
 * @brief El objetivo de esta aplicación es practicar
 * el concepto de gestión de memoria desde la perspectiva
 * de la codificación del software con el lenguaje de
 * programación C++ así como para utilizar punteros en la
 * implementación de estructuras de datos lineales y jerárquicas.
 */
#include <iostream>
#include "Node.h"
#include "List.h"

using namespace std;

int main()
{
    /**
     * @brief ejemplo de cómo utilizar la clase List
     * para trabajar en cómo se insertan, eliminan y
     * muestran datos almacenados en los nodos de la lista.
     */

    Collector* reciclaje = new Collector();
    Node::setReciclaje(reciclaje);
    List list;
    cout<<"Creamos la lista enlazada y agregamos 5 elementos" << endl;
    list.insertFirst(1);
    list.insertLast(5);
    list.insertLast(7);
    list.insertFirst(10);
    list.insertLast(2);

    /**
     * @brief Colector de nodos para reciclar la memoria del nodo eliminado.
     */
    list.printList();
    reciclaje->printCollector();

    cout << endl << "Borramos el nodo con el dato 5 y se guarda al collector"<< endl;

    list.deleteNode(5);
    list.printList();
    reciclaje->printCollector();
    cout << endl << endl << "Añadimos un nuevo nodo con valor 9 a la lista pero reutilizando la dirección de memoria guardada en collector" << endl;
    list.insertLast(9);
    list.printList();
    reciclaje->printCollector();

    return 0;
}