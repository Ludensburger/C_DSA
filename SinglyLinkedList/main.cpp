#include "linkedlist.h"
#include <iostream>
using namespace std;

int main() {
    // Create a DynamicArrayList object
    List *myList = new LinkedList();

    char op;
    int num;
    int pos;

    do {

        cout << "Op: ";
        cin >> op;

        switch (op) {

            // Add a new node to the head (farthest left)
            // Sample Input: h10
        case 'h':

            cin >> num;
            myList->addHead(num);
            break;

            // Add a new node to the tail (farthest right)
            // Sample Input: h10
        case 't':

            cin >> num;
            myList->addTail(num);
            break;

            // Remove a node from the list
            // Sample Input: h20
        case 'r':

            cin >> num;
            cout << "Remove Position " << myList->remove(num) << endl;
            break;

        case 'g':

            cin >> pos;
            myList->get(pos);
            break;

            // Print the list
        case 'p':
            myList->print();
            break;

            // Exit the program
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