#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List list;

    // Inserta nodos
    list.insertFirst(1);
    list.insertLast(5);
    list.insertLast(7);
    list.insertFirst(10);
    list.insertLast(2);

    // imprime la lista
    list.printList();
    cout << endl;

    cout << "Direcciones de memoria de los primeros tres nodos" << endl;
    cout << list.head << endl;
    cout << list.head->next << endl;
    cout << list.head->next->next << endl;

    return 0;
}