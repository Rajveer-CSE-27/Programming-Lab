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

// creating Linked List class
template <class L>
class LinkedList {
	
public:
	
	//  creating a head node and assigning it NULL initially
	Node<L>* head;
	LinkedList<L>() {
		head = NULL;
	}
	
	
	
};

int main() {
	
	return 0;
}
