// FIFO - First In, First Out

class Queue
{
public:
    // We can visualize the Queue in a horizontal list manner like this:
    // the REAR (INSERTION) is at the RIGHTMOST position or the last node
    // the FRONT (REMOVAL) is at the LEFTMOST position or the first node

    // insert from last
    // [1] <- [2] <- [3]  INSERT HERE
    virtual void enqueue(int num) = 0;

    // remove from first
    // REMOVE HERE -> [1] <- [2] <- [3]
    virtual int dequeue() = 0;

    virtual void print() = 0;
    virtual int front() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
};