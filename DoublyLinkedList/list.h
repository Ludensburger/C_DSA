class List {
public:
    virtual void addAt(int, int) = 0;
    virtual int get(int pos) = 0;
    virtual int remove(int num) = 0;
    virtual void print() = 0;
    virtual void addFirst(int) = 0;
    virtual void addLast(int) = 0;
};