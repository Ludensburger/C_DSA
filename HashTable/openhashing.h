#include "hash.h"
#include "node.h"
#include <iostream>
using namespace std;

class OpenHashing : public Hash {

private:
    int capacity;
    // Array to store the Sentinel nodes
    Node **nodeArray;

    // Nodes inside the array
    Node *sentinel;

public:
    OpenHashing() {
        capacity = 10;
        nodeArray = new Node *[capacity]; // Allocate memory for the array

        // Initialize Sentinel nodes inside array
        for (int i = 0; i < capacity; i++) {
            nodeArray[i] = new Node; // Create a new sentinel node
            nodeArray[i]->key = i;   // Set the key of the sentinel node
            nodeArray[i]->elem = 0;  // zero since sentinels
            nodeArray[i]->size = 0;  // no elements yet
            nodeArray[i]->next = nullptr;
        }
    }

    int _size() {
        return capacity;
    }

    int hash(int key) {
        return key % capacity;
    }

    void insert(int key, int elem) {
        // Get the index for this value given a key
        // then create the node
        int index = hash(key);
        Node *newNode = new Node();
        newNode->key = key;
        newNode->elem = elem;
        newNode->next = nullptr;

        // If the Sentinel node is empty, insert the new node as the first element
        if (nodeArray[index]->size == 0) {
            // insert the new node at sentinel's next, then increment the size of that sentinel
            nodeArray[index]->next = newNode;
            nodeArray[index]->size++;

            // If the Sentinel node is not empty, insert the new node at the end of the list
        } else {
            // start at the sentinel node's next, AKA first node/element
            Node *curr = nodeArray[index]->next;

            // Traverse the list to find the last node
            while (curr->next != nullptr) {
                curr = curr->next;
            }

            // Insert the new node at the end of the list
            // by connecting Current's next to the new node
            // then increment sentinel's size
            curr->next = newNode;
            nodeArray[index]->size++;
            // set new node's next to null indicating it's the last node
            newNode->next = nullptr;
        }
    }

    int remove(int key, int value) {
        int index = hash(key);
        if (nodeArray[index]->size == 0) {
            cout << "Empty ";
            return -1; // If the list is empty, return -1 (no elements to remove
        }

        Node *curr = nodeArray[index]->next; // as the first element, skipping the sentinel
        Node *prev = nodeArray[index];       // Start at the sentinel node
        int removed;                         // Initialize the return value to the sentinel node's value

        //  Traverse the list to find the node to remove
        while (curr) {
            // find that value in the node list
            if (curr->elem == value) {

                // temp is in front of curr
                Node *temp = curr->next;

                // Store the value to be removed
                removed = curr->elem;

                // Skip the current node, effectively removing it from the list
                // prev-> curr -> next[TEMP]
                // prev-> next[TEMP]  | curr
                prev->next = temp;

                // Free the memory occupied by the current node
                delete curr;

                // Decrease the size of the list
                nodeArray[index]->size--;

                // Return the removed value
                return removed;
            }
            // move to the next node
            prev = curr;
            curr = curr->next;
        }

        return removed = -1; // If the value is not found, return -1
    }

    void get(int key) {
        int index = hash(key);
        if (nodeArray[index]->size == 0) {
            return; // If the list is empty, return -1 (no elements to get)
        }

        Node *curr = nodeArray[index]->next;
        printf("Sentinel (%d) : ", index);
        while (curr) {
            cout << curr->elem;
            if (curr->next != nullptr) {
                cout << " -> ";
            }
            curr = curr->next;
        }

        cout << endl;
    }

    void resize(int newSize) {
        // Create a new array with the new size
        Node **newArray = new Node *[newSize];

        // Initialize the new array with sentinel nodes
        for (int i = 0; i < newSize; i++) {
            newArray[i] = new Node;
            newArray[i]->key = i;
            newArray[i]->elem = 0;
            newArray[i]->size = 0;
            newArray[i]->next = nullptr;
        }

        // Keep a reference of the old size
        int oldCapacity = capacity;
        // Update the capacity of the hash table
        capacity = newSize;

        // Traverse the old array and rehash elements into the new array
        for (int i = 0; i < oldCapacity; i++) {
            // start at the sentinel node's next, AKA first node/element
            Node *curr = nodeArray[i]->next;

            // Traverse the list while current is not null
            while (curr) {
                int newIndex = hash(curr->key); // Rehash based on the new capacity
                Node *temp = curr->next;        // Store the next pointer before moving curr

                // Insert the current node into the new array at the appropriate index
                curr->next = newArray[newIndex]->next;
                newArray[newIndex]->next = curr;
                newArray[newIndex]->size++; // Increment the size of the new array

                // Move to the next node in the old array
                curr = temp;
            }

            delete nodeArray[i];
        }

        // Delete the old array
        delete[] nodeArray;

        // Update the array pointer to point to the new array
        nodeArray = newArray;
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            Node *curr = nodeArray[i];
            cout << "Sentinel(" << i << ")" << endl;
            curr = curr->next; // Skip the sentinel node
            if (curr) {
                cout << "\tkey(" << curr->key << ") : ";
                while (curr) {
                    cout << "(" << curr->elem << ")";
                    if (curr->next) {
                        cout << " -> ";
                    }

                    curr = curr->next;
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
};