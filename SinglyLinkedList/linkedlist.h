#include "list.h"
#include "node.h"
#include <iostream>
using namespace std;

class LinkedList : public List {

    Node *head;
    Node *tail;
    int size;

    void add(int num) {
        Node *newNode = (Node *)calloc(1, sizeof(Node));
        newNode->elem = num;

        // sets the initial new node as both the head and the tail
        if (size == 0) {
            head = newNode;
            tail = newNode;

            // if there's an existing node, insert it to the right (after the current head)
            // then connect current tail to the new node, and update new node as new tail.
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void addHead(int num) {

        Node *newNode = new Node;
        newNode->elem = num;

        if (size == 0) {
            head = newNode;
            tail = newNode;

        } else {

            // Insert new node before the head, so that is the farthest left
            // then connect new Node to the current head

            newNode->next = head;

            // Then update new Node as the new head
            head = newNode;
        }

        size++;
    }

    void addTail(int num) {

        // Call method add since it always adds a new node to the farthest right,
        // that means it adds after the tail
        add(num);
    }

    int get(int pos) {
        if (size == 0) {
            cout << "Nothing to get" << endl;

            return 0;
        }

        if (pos > size) {
            cout << "Out of bounds" << endl;
            return -1;

        } else {
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
        while (curr) {
            if (curr->elem == num) {
                if (curr == head) {
                    head = head->next;
                } else {
                    if (curr == tail) {
                        tail = prev;
                    }
                    prev->next = curr->next;
                }
                size--;
                return ctr;
            }
            prev = curr;
            curr = curr->next;
            ctr++;
        }
        return -1;
    }

    void print() {
        Node *curr = head;
        if (size == 0) {
            cout << "eMpTy" << endl;
        } else {

            do {
                // Print the element
                cout << curr->elem;

                // check if next node is not a nullptr
                if (curr->next) {
                    cout << " -> ";
                } else {
                    cout << endl;
                }
                // update current to next node

                curr = curr->next;

            } while (curr);
        }
    }
};