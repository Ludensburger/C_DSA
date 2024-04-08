/*
Based on your implementation of a separate chaining hash table with open hashing:

Best Case:

The best-case scenario occurs when all hash functions distribute the elements uniformly across the buckets, resulting in short linked lists or ideally no collisions.
In this case, insertion, deletion, and search operations all have a time complexity of O(1), as they require constant time to access and modify the elements.
Average Case:

The average-case scenario assumes a reasonably good distribution of elements across the buckets, resulting in moderate-length linked lists and occasional collisions.
In this case, insertion, deletion, and search operations typically have a time complexity of O(1) on average. However, if the load factor increases and longer linked lists form, these operations may degrade to O(n), where n is the average length of the linked lists.
Worst Case:

The worst-case scenario occurs when all elements hash to the same bucket, forming a single long linked list.
In this case, insertion, deletion, and search operations may all have a time complexity of O(n), where n is the number of elements in the linked list.
However, it's important to note that the worst case is less likely to occur with a well-designed hash function and appropriate load factor management.
*/

#include "openhashing.h"
#include <iostream>
using namespace std;

int main() {
    Hash *lp = new OpenHashing();
    char op;
    int newSize;
    int key, elem;

    cout << "Menu:" << endl;
    cout << "a - Add an entry" << endl;
    cout << "r - Remove an entry" << endl;
    cout << "p - Print the hash table" << endl;
    cout << "x - Exit" << endl;

    do {
        cout << "Op: ";
        cin >> op;

        switch (op) {
        case 'a': {

            cin >> key >> elem;
            lp->insert(key, elem);
            break;
        }
        case 'r': {
            int key, elem;
            cin >> key >> elem;
            cout << "Removed " << lp->remove(key, elem) << endl;
            break;
        }
        case 'p':
            cout << "Hash Table:" << endl;
            cout << "Capacity: " << lp->_size() << endl;
            lp->print();
            break;

        case 'h':
            cin >> key;
            cout << "Hashing " << lp->hash(key) << endl;
            break;

        case 's':
            cin >> newSize;
            cout << "Resizing to " << newSize << "..." << endl;
            lp->resize(newSize);
            cout << "Capacity: " << lp->_size() << endl
                 << endl;
            break;

        case 'g':
            cin >> key;
            cout << "Getting " << key << "..." << endl;
            lp->get(key);
            break;

        case 't':
            cout << "Running Testing..." << endl;
            lp->insert(0, 3);
            lp->insert(0, 4);
            lp->insert(0, 8);
            lp->insert(1, 10);
            lp->insert(1, 20);
            lp->insert(2, 20);
            lp->insert(3, 30);
            lp->insert(4, 40);

            // putang ina theres a bug, dapat sa sentinel 7 ning boang FIXED
            // cout << "GUBA ";
            lp->insert(1567, 79);
            // cout << endl;
            // lp->print();
            // // cout << "Hash call: ";
            // // lp->hash(1567);
            // // cout << endl;
            // cout << "removed " << lp->remove(1, 10) << endl;
            // cout << "removed " << lp->remove(1, 10) << endl;
            // lp->print();

            break;

        case 'y':
            cout << "Running Testing..." << endl;
            lp->insert(12, 34);
            lp->insert(45, 67);
            lp->insert(89, 123);
            lp->insert(456, 789);
            lp->insert(321, 654);
            lp->insert(987, 654);
            lp->insert(543, 210);
            lp->insert(876, 543);
            lp->insert(234, 876);
            lp->insert(567, 432);

            break;

        case 'x':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (op != 'x');

    return 0;
}
