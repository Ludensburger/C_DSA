#include <iostream>
#include "node.h"
#include "queue.h"
using namespace std;

class QueueList : public Queue
{
private:
    int queueSize;
    Node *head;
    Node *tail;

public:
    QueueList()
    {
        queueSize = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void enqueue(int num)
    {
        Node *newNode = new Node;
        newNode->elem = num;
        newNode->next = nullptr;

        if (queueSize == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        queueSize++;
    }

    int dequeue()
    {
        Node *oldHead = head;
        int dequeueElem = oldHead->elem;
        head = oldHead->next;
        delete oldHead;
        queueSize--;

        return dequeueElem;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "eMpTy HEHE :D" << endl;
            return;
        }

        cout << "Queue: ";
        Node *curr = head;
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

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return head->elem;
    }

    int size()
    {
        return queueSize;
    }
};