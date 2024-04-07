#include "stack.h"
#include "node.h"
#include <iostream>
using namespace std;

class StackList : public Stack
{

private:
    int stackSize;
    Node *topNode;

public:
    // Constructor
    StackList()
    {
        stackSize = 0;
        topNode = nullptr;
    }

    int isEmpty()
    {
        return topNode == nullptr;
    }

    int size()
    {
        return stackSize;
    }

    void push(int num)
    {
        Node *newNode = new Node;
        newNode->elem = num;
        newNode->next = topNode;
        topNode = newNode;
        stackSize++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "eMpTy" << endl;
            return -1;
        }

        Node *oldTop = topNode;
        int poppedElem = oldTop->elem;
        topNode = oldTop->next;
        delete oldTop;
        stackSize--;

        return poppedElem;
    }

    int peek()
    {

        if (isEmpty())
        {
            cout << "eMpTy NO TOP" << endl;
            return -1;
        }
        return topNode->elem;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "eMpTy HEHE :D" << endl;
            return;
        }

        cout << "Stack: ";
        Node *curr = topNode;
        while (curr)
        {
            cout << curr->elem;
            if (curr->next)
            {
                cout << " -> ";
            }
            curr = curr->next;
        }

        cout << endl;
    }
};
