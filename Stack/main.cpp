#include <iostream>
#include "stacklist.h"
using namespace std;

int main()
{
    Stack *myStack = new StackList();

    char op;
    int num;

    cout << "Menu:" << endl;
    cout << "a: Add an element to the stack." << endl;
    cout << "r: Remove the top element from the stack." << endl;
    cout << "?: Check if stack is empty." << endl;
    cout << "t: Find the top/peek element in the stack." << endl;
    cout << "p: Print the stack." << endl;
    cout << "x: Exit the program." << endl;

    do
    {
        cout << "Op: ";
        cin >> op;

        switch (op)
        {
        case 'a':
            // cout << "Enter a number to add to the stack: ";
            cin >> num;
            myStack->push(num);
            break;
        case 'r':
            cout << "Popped: " << myStack->pop() << endl;
            break;
        case 'p':
            myStack->print();
            break;

        case 't':
            cout << "Top " << myStack->peek() << endl;
            break;
        case '?':
            cout << "Empty? ";
            if (myStack->isEmpty())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            break;
        case 'x':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid operation." << endl;
            break;
        }
    } while (op != 'x');

    delete myStack;
    return 0;
}