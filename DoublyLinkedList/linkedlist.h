#include "list.h"
#include "node.h"
#include <iostream>
using namespace std;

class LinkedList : public List {

    Node *head, *tail;
    int size;

public:
    // Constructor code
    LinkedList() {
        cout << "HI" << endl;

        // Allocate memory for head and tail
        // HERE: head and tail are sentinels
        head = new Node();
        tail = new Node();

        head->elem = 0; // Or some other default value
        tail->elem = 0; // Or some other default value

        // so we start at
        // head's next and tail's prev
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Adding Elements
    // Utility function to add nodes
    // used by addFirst, addLast and addAt
    void addBetween(int elem, Node *pred, Node *succ) {
        // Create a new Node
        Node *newNode = new Node();
        newNode->elem = elem;
        newNode->next = succ;
        newNode->prev = pred;

        pred->next = newNode;
        succ->prev = newNode;

        size++;
    }

    void addFirst(int elem) {
        addBetween(elem, head, head->next);
    }

    void addLast(int elem) {
        addBetween(elem, tail->prev, tail);
    }

    void addAt(int elem, int pos) {

        Node *curr = head->next;
        int ctr = 1;
        // Traverse the list to find the position
        // where the new Node will be inserted

        while (ctr != pos && curr != tail) {
            curr = curr->next;
            ctr++;
        }

        // set pred as currs previous Node
        // set succ as curr initially because we want to insert the new Node between pred and succ
        // making the new Node the new curr

        // PREDECESSOR -> CURR = SUCCESSOR

        Node *pred = curr->prev;
        Node *succ = curr;
        // add the new Node between pred and succ

        // PREDECESSOR -> NEW Node -> SUCCESSOR

        addBetween(elem, pred, succ);
    }

    // Utility function
    // used by removeFirst, removeLast and remov
    void removeNode(Node *n) {

        // get the previous and next nodes of n
        Node *pred = n->prev;
        Node *succ = n->next;

        // disconnect n from the list
        // by connecting pred to succ (skipping n)
        // and conntecting succ to pred (skipping n)
        pred->next = succ;
        succ->prev = pred;

        // then free the memory allocated for n
        // and set n to NULL
        free(n);
        n = NULL;

        // finally decrement the size of the list
        // and return
        size--;
        return;
    }

    int remove(int elem) {

        // If the list is empty
        if (size == 0) {
            return -1;
        }

        Node *curr = head->next;
        int pos = 1;

        while (curr != tail) {
            if (curr->elem == elem) {
                removeNode(curr);
                return pos;
            }
            curr = curr->next;
            pos++;
        }
        return -1;
    }

    void removeFirst() {
        if (size == 0) {
            cout << "List is empty, cannot remove the first element." << endl;
            return;
        }

        // First node is the node after headSentinel
        Node *firstNode = head->next;
        // HEAD <-> FIRSTNODE <-> FIRSTNODE.NEXT

        // disconnect
        head->next = firstNode->next;
        // HEAD <-> FIRSTNODE.NEXT

        // FIRSTNODE (disconnected)

        // if there is a node after the first node
        if (firstNode->next != nullptr) {
            // update the prevNode of the disconnectedNode as new first node
            firstNode->next->prev = head;
        }

        // free the disconnected Node
        free(firstNode);
        size--;

        // So we initially disconnected its left pointer by reassigning heads conenction
        // then finally we remove its right pointer by updating head
    }

    void removeLast() {
        if (size == 0) {
            cout << "List is empty, cannot remove the last element." << endl;
            return;
        }

        // Last node is the node before tailSentinel
        Node *lastNode = tail->prev;
        // LASTNODE.PREV <-> LASTNODE <-> TAIL

        // disconnect
        tail->prev = lastNode->prev;
        // LASTNODE.PREV <-> TAIL

        // LASTNODE (disconnected)

        // if there is a node before the last node
        if (lastNode->prev != nullptr) {
            // update the nextNode of the disconnectedNode as new last node
            lastNode->prev->next = tail;
        }

        // free the disconnected Node
        free(lastNode);
        size--;

        // So we initially disconnected its right pointer by reassigning tails conenction
        // then finally we remove its left pointer by updating tail
    }

    // Helper Functions
    int get(int pos) {
        Node *curr = head;
        int ctr = 1;
        while (ctr != pos) {
            curr = curr->next;
            ctr++;
        }
        return curr->elem;
    }

    void print() {

        if (size == 0) {
            cout << "Empty" << endl;
            return;
        }

        // Print elements from HEAD to TAIL
        cout << "From HEAD: ";
        Node *curr = head->next;
        while (curr != tail) {
            cout << curr->elem;
            if (curr->next != tail) {
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;

        // Print elements from TAIL to HEAD
        cout << "From TAIL: ";
        curr = tail->prev;
        while (curr != head) {
            cout << curr->elem;
            if (curr->prev != head) {
                cout << " <- ";
            }
            curr = curr->prev;
        }
        cout << endl;
    }
};