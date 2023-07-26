#include <iostream>
using namespace std;

// creating node class
template <class L>
class Node {
public:
	L val;
	Node<L>* next;
	
	// constructor for initializing a node
	Node(L data) {
		val = data;
		next = NULL;
	}
};



int main() {
	
	return 0;
}
