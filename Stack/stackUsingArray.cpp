#include <iostream>
#include "arrayFinal.cpp"

int maxSize = 10;

template <class S>
class stackUsingArray {
public:

    array<int> stack;
    int topIndex = -1;    
    
    void push(S val) {
        if(topIndex == maxSize) {
            cout << "Stack already full" << endl;
            return;
        }

        topIndex += 1;
        stack.insertElement(val);
    }

    void pop() {
        if(topIndex == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        stack.deleteElement(topIndex);
        topIndex -= 1;
    }

  
    void getSize() {
        cout << "Stack size is : " << topIndex + 1 << endl;
    }
};

int main() {
    stackUsingArray<int> st;
    for(int i=0; i<5; i++) {
        st.push(i+1);
    }
    
    st.pop();
    st.getSize();
}
