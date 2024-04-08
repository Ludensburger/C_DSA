class Hash {
public:
    virtual void insert(int key, int value) = 0;
    virtual int remove(int key, int value) = 0;
    virtual void get(int key) = 0;
    virtual void resize(int newSize) = 0;
    virtual int hash(int key) = 0;
    virtual int _size() = 0;
    virtual void print() = 0;
};