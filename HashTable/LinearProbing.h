#include "node.h"
#include "hash.h"
#include <iostream>
using namespace std;

class LinearProbing : public Hash
{

private:
    int capacity;
    Node *sentinel;
    Node **nodeArray;

public:
    LinearProbing()
    {
        capacity = 10;
        nodeArray = new Node *[capacity]; // Allocate memory for the array

        // Initialize Sentinel nodes inside array
        for (int i = 0; i < capacity; i++)
        {
            nodeArray[i] = new Node; // Create a new sentinel node
            nodeArray[i]->key = i;   // Set the key of the sentinel node
            nodeArray[i]->elem = 0;  // zero since sentinels
            nodeArray[i]->next = nullptr;
        }
    }

    int hash(int key)
    {
        cout << key % capacity;
        return 0;
    }

    void insert(int key, int elem)
    {
        // Get the index for this value given a key
        // then create the node
        int index = hash(key);
        Node *newNode = new Node();
        newNode->key = key;
        newNode->elem = elem;
        newNode->next = nullptr;

        // If the index is empty, insert the node next to the sentinel
        if (nodeArray[index]->next == nullptr)
        {
            nodeArray[index]->next = newNode;
        }

        // If the index is not empty, insert the node at the end of the list
        else
        {
            // Traverse the list to find the last node
            Node *curr = nodeArray[index];
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    void print()
    {
        for (int i = 0; i < capacity; ++i)
        {

            Node *curr = nodeArray[i]->next; // Skip the sentinel node
            if (curr != nullptr)
            {
                cout << "Stnl" << i << "(k" << curr->key << ") -> ";
                while (curr != nullptr)
                {
                    cout << curr->elem;
                    if (curr->next != nullptr)
                    {
                        cout << " -> ";
                    }
                    curr = curr->next; // Move to the next node in the list
                }
            }

            cout << endl;
        }
    }
};