// Author: Ryu R. Mendoza
// Date: April 6, 2024
// Description: A program that demonstrates the implementation of a dynamic array list.

#include "myArrayList.h"
#include <iostream>
using namespace std;

int main() {
    DynamicArrayList myList;
    char op;
    int num;

    do {
        cout << "Op: ";
        cin >> op;

        switch (op) {
        case 'a':

            cin >> num;
            myList.add(num);
            break;
        case 'r':

            cin >> num;
            myList.remove(num);
            break;
        case 'p':
            myList.print();
            break;
        case 'x':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid operation." << endl;
            break;
        }
    } while (op != 'x');

    return 0;
}