#include <iostream>
#include "Node.h"
#include "List.h"

using namespace std;

int main()
{
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