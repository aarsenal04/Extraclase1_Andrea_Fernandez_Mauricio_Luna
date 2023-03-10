// C++ program for the above approach
#include <iostream>
#include "List.h"
using namespace std;


int main()
{
    List list;

    // Inserting nodes
    list.insertFirst(1);
    list.insertLast(5);
    list.insertLast(7);
    list.insertFirst(10);
    list.insertLast(2);

    // Print the list
    list.printList();
    cout << endl;

    // Delete node at position 2.
    //  list.deleteNode(2);
    cout << "Direcciones de memoria de los primeros tres nodos" << endl;
    cout << list.head << endl;
    cout << list.head->next << endl;
    cout << list.head->next->next << endl;

    return 0;
}
