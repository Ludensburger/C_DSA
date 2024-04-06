// Author: Ryu R. Mendoza
// Date: April 6, 2024

#include "linkedlist.h"
#include <iostream>
using namespace std;

int main() {

    List *mySList = new LinkedList();

    char op;
    int input, pos;

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
            mySList->get(pos);
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