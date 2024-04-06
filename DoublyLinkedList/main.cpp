// Author: Ryu R. Mendoza
// Date: April 6, 2024

#include "linkedlist.h"
#include <iostream>

int main() {
    LinkedList *myDList = new LinkedList();
    int num, pos;
    char op;

    cout << "Menu:" << endl;
    cout << "h: Add an element to the beginning of the list." << endl;
    cout << "t: Add an element to the end of the list." << endl;
    cout << "@: Add an element at a specific position in the list." << endl;
    cout << "r: Remove an element from the list by value." << endl;
    cout << "F: Remove the first element from the list." << endl;
    cout << "L: Remove the last element from the list." << endl;
    cout << "g: Get an element from a specific position in the list." << endl;
    cout << "p: Print the list." << endl;
    cout << "x: Exit the program." << endl;

    do {
        cout << "Op: ";
        cin >> op;

        switch (op) {

        case 'h':
            cin >> num;
            myDList->addFirst(num);
            break;
        case 't':
            cin >> num;
            myDList->addLast(num);
            break;
        case '@':
            cin >> num >> pos;
            myDList->addAt(num, pos);
            break;
        case 'r':
            cin >> num;
            cout << "Remove pos " << myDList->remove(num) << endl;
            break;
        case 'F':
            myDList->removeFirst();
            break;
        case 'L':
            myDList->removeLast();
            break;
        case 'g':
            cin >> num;
            cout << myDList->get(num) << endl;
            break;
        case 'p':
            myDList->print();
            break;
        case 'x':
            cout << "Exiting" << endl;
            break;
        }
    } while (op != 'x');

    delete myDList; // Don't forget to deallocate memory

    return 0;
}
