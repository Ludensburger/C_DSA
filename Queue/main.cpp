#include <iostream>
#include "queuelist.h"
using namespace std;

int main()
{
    Queue *myQueue = new QueueList();
    char op;
    int num;

    cout << "\nMenu:\n";
    cout << "a: Enqueue an element\n";
    cout << "r: Dequeue an element\n";
    cout << "p: Print the queue\n";
    cout << "x: Exit the program\n";

    do
    {

        cout << "Op: ";
        cin >> op;

        switch (op)
        {
        case 'a':
            cin >> num;
            myQueue->enqueue(num);

            break;

        case 'r':
            num = myQueue->dequeue();
            if (num != -1)
            {
                cout << "Dequeued: " << num << endl;
            }
            break;

        case 'p':
            myQueue->print();
            break;

        case 'x':
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid operation." << endl;
            break;
        }

    } while (op != 'x');

    delete myQueue;
    return 0;
}
