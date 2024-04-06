// Author: Ryu R. Mendoza
// Date: April 6, 2024

#include "linkedlist.h"
#include <iostream>
using namespace std;

int main() {

    List *mySList = new LinkedList();

    char op;
    int input, pos;

    cout << "Menu:" << endl;
    cout << "a: Add an element to the list." << endl;
    cout << "h: Add an element to the head of the list." << endl;
    cout << "t: Add an element to the tail of the list." << endl;
    cout << "g: Get an element from a specific position in the list." << endl;
    cout << "r: Remove an element from the list by value." << endl;
    cout << "p: Print the list." << endl;
    cout << "x: Exit the program." << endl;

    do {
        cout << "Op: ";
        cin >> op;

        switch (op) {

            // Add case a first before executing other cases
        case 'a':
            cin >> input;
            mySList->add(input);

            break;
        case 'h':
            cin >> input;
            mySList->addHead(input);
            break;
        case 't':
            cin >> input;
            mySList->addTail(input);
            break;
        case 'g':
            cin >> pos;
            cout << "Element at position " << mySList->get(pos) << endl;
            break;
        case 'r':
            cin >> input;
            cout << "Remove position " << mySList->remove(input) << endl;
            break;

        case 'p':
            mySList->print();
            break;
        }

    } while (op != 'x');

    return 0;
}