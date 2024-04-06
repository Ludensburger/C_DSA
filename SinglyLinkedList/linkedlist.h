#include "list.h"
#include "node.h"
#include <iostream>
using namespace std;

class LinkedList : public List {
public:
    Node *head;
    Node *tail;
    int size;

    // Base function
    // Add a new node to the farthest right
    void add(int num) {
        Node *newNode = new Node;
        newNode->elem = num;

        if (size == 0) {
            // Set new node as both head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Insert new node to the right of the current tail
            // Update new node as tail
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    // Add a new node to the farthest left
    void addHead(int num) {

        Node *newNode = new Node;
        newNode->elem = num;

        if (size == 0) {
            // Set new node as both head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Insert new node to the left of the current head
            // Update new node as head
            newNode->next = head;
            head = newNode;
        }

        size++;
    }

    void addTail(int num) {
        // Call add method since it always adds a new node to the farthest right
        // That means it adds after the tail
        add(num);
    }

    int get(int pos) {

        // If the list is empty, return -1
        if (size == 0) {
            cout << "List is Empty" << endl;
            return -1;

        }
        // If the position is out of bounds, return -1
        else if (pos > size) {
            cout << "Out of bounds" << endl;
            return -1;

        }

        // If the position is within bounds, return the element at that position
        else {
            Node *curr = head;
            int ctr = 1;

            while (ctr < pos) {
                curr = curr->next;
                ctr++;
            }

            return curr->elem;
        }
    }

    int remove(int num) {

        Node *curr = head;
        Node *prev;
        int ctr = 1;
        // If the list is empty, return -1
        if (size == 0) {
            cout << "List is Empty" << endl;
            return -1;
        }

        // Traverse the list
        while (curr) {
            // If the element is found
            if (curr->elem == num) {

                // check if the element is the head
                // then Just update head to the next node
                if (curr == head) {
                    head = head->next;
                }

                // check if the element is the tail
                // then update tail to the previous node
                else {
                    if (curr == tail) {
                        tail = prev;
                    }
                    // if the element is in the middle
                    // then update the previous node's next to the current node's next
                    // effectively removing the current node
                    prev->next = curr->next;
                }

                // Decrement Size and return the removed element's position
                size--;
                return ctr;
            }

            prev = curr;
            curr = curr->next;
            ctr++;
        }

        // if the element is not found, return -1
        return -1;
    }

    void print() {
        Node *curr = head;
        if (size == 0) {
            cout << "eMpTy" << endl;
        }

        else {

            do {
                // Print the element
                cout << curr->elem;

                // check if next node is not a nullptr
                // this is similar to commas in Arrays
                if (curr->next) {
                    cout << " -> ";
                    // So if theres no next node, print a new line instead
                } else {
                    cout << endl;
                }
                // Update current to next node
                curr = curr->next;
            } while (curr);
        }
    }
};