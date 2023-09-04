#include <iostream>
using namespace std;

template <class A> 
class Array {
public:
    int size = 2;
    A *array = new A[size];
    A rightIndex = -1;
    // defined the array with rightIndex targetting the previous address of the first unfilled cell

    void insertElementAtEnd(A val) {
        rightIndex += 1;
        if(rightIndex == size) {
            A *array2 = new A[size*2];
            size = size*2;
            for(int i=0; i<rightIndex; i++) {
                array2[i] = array[i];
            }
            array = array2;
        }
        array[rightIndex] = val;
    }
    
    void insertElementAtStart(A val) {
        rightIndex += 1;
        if(rightIndex == size) {
            A *array2 = new A[size*2];
            size = size*2;
            for(int i=0; i<rightIndex; i++) {
                array2[i] = array[i];
            }
            array = array2;
        }
        for(int i=1; i<=rightIndex; i++) {
            array[i] = array[i-1];
        }
        array[0] = val;
    }

    void deleteElementFromEnd() {
        if(rightIndex == -1) {
            //cout << "Array is empty";
            return;
        }
        
        if(rightIndex < size/4) {
            A *array2 = new A[size/2];
            size /= 2;
            for(int i=0; i<rightIndex; i++) {
                array2[i] = array[i];
            }
            array = array2;
        } 
        rightIndex -= 1;
        
    }    

    void printArray() {
        for(int i=0; i<=rightIndex; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    
    void clear() {
        size = 2;
        rightIndex = -1;
        A *array2 = new A[size];
        array = array2;
    }

};

// int main() {

//     array<int> arr;
//     arr.insertElement(1);
//     arr.insertElement(2);
//     arr.insertElement(3);
//     arr.insertElement(4);
//     arr.printArray();
    
//     arr.deleteElementFromEnd();
//     arr.printArray();
//     arr.deleteElementFromEnd();
//     arr.printArray();
//     arr.deleteElementFromEnd();
//     arr.printArray();
    
//     return 0;
// }