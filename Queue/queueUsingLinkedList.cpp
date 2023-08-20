#include <iostream>
#include "SearchElement.cpp"

int maxSize = 10;

template <class Q>
class queueUsingLinkedList {
public:

    LinkedList<int> queue;
    int frontIndex = -1, rearIndex = -1;

    void enqueue(Q val) {
        if(rearIndex != 0 && rearIndex%10 == 0) {
            cout << "Queue is full";
            return;
        }
        if(rearIndex == -1) {
            queue.insertNode(val);
            frontIndex++;
            rearIndex++;
            return;
        }
        
        queue.insertNode(val);
        rearIndex++;
    }

    void dequeue() {
        if(rearIndex%10 < frontIndex%10) {
            cout << "Queue is empty" << endl;
            return;
        }
        queue.deleteNode(frontIndex%10);
        frontIndex++;
    }

  
    void getSize() {
        cout << "Queue size is : " <<  rearIndex - frontIndex + 1 << endl;
    }
};

int main() {
    queueUsingLinkedList<int> q;
    for(int i=0; i<5; i++) {
        q.enqueue(i+1);
    }
    q.dequeue();
    q.getSize();
}
