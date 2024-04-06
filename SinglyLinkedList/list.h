class List {
public:
    virtual void add(int) = 0;
    virtual void addHead(int) = 0;
    virtual void addTail(int) = 0;
    virtual void print() = 0;
    virtual int get(int) = 0;
    virtual int remove(int) = 0;
};