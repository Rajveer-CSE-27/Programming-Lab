#include <iostream>
#include "SearchElement.cpp"

int maxSize = 10;

template <class S>
class stackUsingLinkedList {
public:

    LinkedList<int> stack;
    int topIndex = -1;

    void push(S val) {
        if(topIndex == maxSize) {
            cout << "Stack already full" << endl;
            return;
        }

        topIndex += 1;
        stack.insertNode(val);
    }

    void pop() {
        if(topIndex == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
	stack.deleteNode(topIndex);
        topIndex -= 1;
    }

  
    void getSize() {
        cout << "Stack size is : " << topIndex + 1 << endl;
    }
};

int main() {
	stackUsingLinkedList<int> st;
	for(int i=0; i<5; i++) {
		st.push(i+1);
	}
	st.pop();
	st.getSize();
}
