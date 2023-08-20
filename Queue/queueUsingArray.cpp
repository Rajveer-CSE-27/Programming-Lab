#include <iostream>
#include "arrayFinal.cpp"

int maxSize = 10;

template <class Q>
class queueUsingArray {
public:

    array<int> queue;
    int frontIndex = -1, rearIndex = -1;
    
    void enqueue(Q val) {
        if(rearIndex != 0 && rearIndex%10 == 0) {
            cout << "Queue is full";
            return;
        }
        
        if(rearIndex == -1) {
            queue.insertElement(val);
            frontIndex++;
            rearIndex++;
            return;
        }
        
        queue.insertElement(val);
        rearIndex++;
    }

    void dequeue() {
        if(rearIndex%10 < frontIndex%10 or frontIndex == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        queue.deleteElement(frontIndex);
        frontIndex++;
    }

  
    void getSize() {
        cout << "Queue size is : " << rearIndex - frontIndex + 1 << endl;
    }
};

int main() {
    queueUsingArray<int> q;
    for(int i=0; i<5; i++) {
        q.enqueue(i+1);
    }
    
    q.dequeue();
    q.getSize();
}
