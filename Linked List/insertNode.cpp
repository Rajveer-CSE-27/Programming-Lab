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
	
	// creating insertNode function
	
	void insertNode(L data) {
		if(head == NULL) {
			//when there is no element in the linked list
			head = new Node<L>(data);
		} else {
			// iterate till last element of the linked list
			Node<L>* temp = new Node<L>(data);
			Node<L>* iteratorNode = head;
			while(iteratorNode->next != NULL) {
				iteratorNode = iteratorNode->next;
			}
			iteratorNode->next = temp;
		}
	}
	
	
};

int main() {
	
	return 0;
}
