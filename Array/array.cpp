#include <iostream>
using namespace std;

template <class A> 
class array {
public:

    A *array = new A[10];
    A rightIndex = -1;
    // defined the array with rightIndex targetting the previous address of the first unfilled cell

    void insertElement(A val) {
        rightIndex += 1;
        if(rightIndex == 10) {
            cout << "Array already full";
            return;
        }
        array[rightIndex] = val;
    }

    void deleteElement(A val) {

        if(rightIndex == -1) {
            cout << "Array is empty";
            return;
        }

        int valueIndex = -1;
        for(int i=0; i<=rightIndex; i++) {
            if(array[i] == val) {
                valueIndex = i;
                break;
            }
        }

        if(valueIndex == -1) {
            cout << "Element not in array";
            return;
        }

        for(int i = valueIndex; i<rightIndex; i++) {
            array[i] = array[i+1];
        }
        rightIndex -= 1;
    }    

    void searchElement(A val) {
        for(int i=0; i<=rightIndex; i++) {
            if(array[i] == val) {
                cout << "Value at : " << i+1 << " position.";
                return;
            }
        }
        cout << "Value not in array";
    }



    void printArray() {
        for(int i=0; i<=rightIndex; i++) {
            cout << array[i] << " ";
        }
    }

};

int main() {

    array<int> arr;
    for(int i=0; i<6; i++) {
        arr.insertElement(i+1);
    }

    arr.searchElement(4);
    arr.deleteElement(3);
    arr.printArray();

    return 0;
}
