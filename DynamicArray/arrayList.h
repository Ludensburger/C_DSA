// Abstract class for ArrayList
class ArrayList {
public:
    virtual void add(int element) = 0;
    virtual void remove(int index) = 0;
    virtual int get(int index) = 0;
    virtual int size() = 0;
};