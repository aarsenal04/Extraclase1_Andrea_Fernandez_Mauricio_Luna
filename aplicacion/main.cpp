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

    /**
     * @brief Se crea una instancia de la clase Collector y la asigna al puntero reciclaje para almacenar los nodos eliminados de la lista para poder reciclar memoria.
     */
    Collector* reciclaje = new Collector();
    /**
     * @brief se llama a setReciclaje de la clase Node y pasa el obj reciclaje como argumento (Node accede a Collector para almacenar nodos eliminados).
     */
    Node::setReciclaje(reciclaje);
    /**
     * @brief Instancia de la clase List y luego se insertan nuevos nodos en la lista con el valor indicado.
     */
    List list;
    cout<<"Creamos la lista enlazada y agregamos 5 elementos" << endl;
    list.insertFirst(1);
    list.insertLast(5);
    list.insertLast(7);
    list.insertFirst(10);
    list.insertLast(2);

    /**
     * @brief Imprime los valores almacenados en cada nodo de la lista.
     */
    list.printList();
    /**
     * @brief Imprime los valores almacenados en Collector.
     */
    reciclaje->printCollector();
    cout << endl << "Borramos el nodo con el dato 5 y se guarda al collector"<< endl;
    /**
     * @brief Elimina el nodo con el valor indicado de la lista y lo almacena en Collector.
     */
    list.deleteNode(5);
    /**
     * @brief Imprime los valores almacenados en cada nodo de la lista actualizada después de eliminar el nodo con el valor indicado.
     */
    list.printList();
    /**
     * @brief Imprime los valores almacenados en Collector actualizado luego de añadir el nodo con el valor indicado.
     */
    reciclaje->printCollector();
    cout << endl << endl << "Agregamos un nuevo nodo con valor 9 a la lista pero reutilizando la direccion de memoria guardada en collector" << endl;
    /**
     * @brief Agrega un nuevo nodo con el valor indicado al final de la lista, reutiliza la dirección de memoria disponible desde Collector.
     */
    list.insertLast(9);
    /**
     * @brief Imprime los valores almacenados en cada nodo de la lista actualizada luego de agregar el nodo con el valor indicado.
     */
    list.printList();
    /**
     * @brief Imprime los valores almacenado en Collector actualizado luego de agregar el nodo con el valor indicado.
     */
    reciclaje->printCollector();

    return 0;
}