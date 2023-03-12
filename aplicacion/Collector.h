/**
 * @file Collector.h
 * @version 1.0
 * @date 12/03/2023
 * @authors Mauricioluna & AndreaFernandez
 */

/**
 * @brief Definición de Collector.
 */

/**
 * @brief Comprueba si la macro no está definida y luego la define para evitar que se incluya en otros archivos.
 */
#ifndef PRACTICASDATOS2_COLLECTOR_H
#define PRACTICASDATOS2_COLLECTOR_H

/**
 * @brief se declara la clase Node y comienza la definición de la clase Collector.
 */
class Node;
class Collector {

/**
 * @brief Se declara un puntero al obj Chead que apunta al primer nodo en Collector. size almacena el num de nodos en Collector.
 */
private:
    Node* Chead;
    int size;

public:
    /**
     * @brief Inicializa el puntero Chead a nulo y su tamaño a 0.
     */
    Collector();
    /**
     *
     * @param node se inserta en la lista de Collector.
     */
    void insertNode(Node* node);
    /**
     *
     * @brief obtiene el tamaño actual de Collector
     */
    int getSize();
    /**
     * @brief imprime el contenido en Collector.
     */
    void printCollector() const;
    /**
     *
     * @return nodo desde Collector.
     */
    Node* giveNode();
};

#endif