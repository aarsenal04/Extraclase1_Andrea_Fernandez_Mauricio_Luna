/**
 * @file Node.h
 * @version 1.0
 * @date 12/03/2023
 * @authors Mauricioluna & AndreaFernandez
 */

/**
 * @brief Definición de Node.
 */

/**
 * @brief Comprueba que el header no se incluya varias veces en su mismo origen.
 * entonces si no se ha definido, los demás archivos pueden funcionar, si no entonces omite su funcionamiento.
 */
#ifndef PRACTICASDATOS2_NODE_H
#define PRACTICASDATOS2_NODE_H

#include <iostream>

using namespace std;

/**
 * @brief Se declaran las clases List y Collector por usar en la definición de la clase Node.
 */
class List;
class Collector;

/**
 * @brief Se define la clase Node con su lista enlazada.
 */
class Node {
    /**
     * @brief Las clases List y Collector pueden acceder a private de la clase Node.
     */
    friend class List;
    friend class Collector;

public:
    /**
     * @brief Constructor por defecto.
     * @param data con argumento int
     */
    Node();
    Node(int data);
    /**
     *
     * @brief Sobrecarga del operador new para permitir la asignación de memoria dinámica.
     */
    void* operator new(size_t size);
    /**
     *
     * @brief Sobrecarga del operador delete para liberar la memoria asignada dinámicamente.
     */
    void operator delete(void* p);
   /**
    *
    * @param collector recicla memoria desde función estática que lo define.
    */
    static void setReciclaje(Collector* collector);
    /**
     * @brief Puntero estático al obj Collector para reciclar memoria.
     */
    static Collector* reciclaje;

    /**
     * @brief data representa el valor almacenado en el nodo y next el puntero al siguiente nodo en la lista.
     */
private:
    int data;
    Node* next;
};

#endif