#include <cmath>
#include <iostream>
using namespace std;

// Abstract class for ArrayList
class ArrayList

{
public:
    virtual void add(int element) = 0;
    virtual void remove(int index) = 0;
    virtual int get(int index) = 0;
    virtual int size() = 0;
};

// DynamicArrayList class that implements the ArrayList interface
class DynamicArrayList : public ArrayList {
private:
    int *arr;
    int capacity;
    int currentSize;

public:
    DynamicArrayList() {
        capacity = 5;
        currentSize = 0;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = '?'; // ASCII value for '?'
        }
    }

    void add(int element) {
        if (currentSize >= capacity * 0.75) {

            int newSize = floor(1.5 * capacity);
            int *temp = new int[newSize];

            for (int i = 0; i < currentSize; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity = newSize;
            arr = temp;
        }
        arr[currentSize] = element;
        currentSize++;
    }

    void remove(int value) {
        // Base case: if the array is empty, there's nothing to remove
        if (currentSize == 0) {
            cout << "Cannot remove element. The array is empty." << endl;
            return;
        }

        bool found = false;
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] == value) {
                // Shift elements to the left
                for (int j = i; j < currentSize - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                currentSize--;
                found = true;
                break; // Exit the loop after removing the first occurrence of the value
            }
        }

        // Base case: if the value was not found in the array, inform the user
        if (!found) {
            cout << "Cannot remove element. The value was not found in the array." << endl;
            return;
        }

        // If currentSize is less than a quarter of capacity, reduce capacity
        if (currentSize > 0 && currentSize < capacity / 4) {
            int *temp = new int[capacity / 2];
            for (int k = 0; k < currentSize; k++) {
                temp[k] = arr[k];
            }
            delete[] arr;
            capacity /= 2;
            arr = temp;
        }
    }

    int size() {
        return currentSize;
    }

    int get(int index) {
        if (index < currentSize) {
            return arr[index];
        }
        return -1;
    }

    void print() {
        for (int i = 0; i < 5; i++) // Always print at least 5 elements
        {
            if (i < currentSize) {
                cout << arr[i] << " ";
            } else {
                cout << "? ";
            }
        }
        cout << endl;
    }
};

int main() {
    DynamicArrayList myList;
    char op;
    int num;

    do {
        cout << "Op: ";
        cin >> op;

        switch (op) {
        case 'a':

            cin >> num;
            myList.add(num);
            break;
        case 'r':

            cin >> num;
            myList.remove(num);
            break;
        case 'p':
            myList.print();
            break;
        case 'x':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid operation." << endl;
            break;
        }
    } while (op != 'x');

    return 0;
}