// LIFO - Last In, First Out

class Stack
{
public:
    // We can visualize the Stack in a horizontal list manner like this:
    // the PEEK is at the RIGHT MOST position or the Last Node
    // and the bottom is at the left most position or the first node

    // Insert at the top of the stack
    // [1] <- [2] <- [3]  INSERT HERE
    virtual void push(int) = 0;

    // Remove from the top of the stack
    // [1] <- [2] <- [3]  REMOVE HERE
    virtual int pop() = 0;

    virtual void print() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual int peek() = 0;
};