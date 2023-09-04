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
	
	//creating a deleteNode function
	void deleteNodeFromEnd() {
		// indexing must be 1 based
		if(head == NULL) {
			//cout << "List Empty" << endl;
			return;
		}
		
		// finding length of the linked list
		int length = 0;
		Node<L>* temp = head;
		while(temp != NULL) {
			temp = temp->next;
			length++;
		}
		int index = length;
		
		// if index is greater than the length of the linked list
		if(index > length) {
			//cout << "Required index is greater than LinkedList" << endl;
			return;
		}
		
		// if we want to delete the head
		if(index == 1) {
			temp = head;
			head = head->next;
			delete temp;
			return;
		}
		
		// deleting any other node in the linked list
		Node<L>* temp1 = head;
		index = index - 1;
		while(index > 1) {
			temp1 = temp1->next;
			index--;
		}
		Node<L>* temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
		
		
	}
	
	// creating a function to Search the given element and return it's index. 
	//Function returns -1 if element is not present in the linked list
	int searchElementIndex(L data) {
		// if linked list is empty
		if(head == NULL) {
			return -1;
		}
		
		Node<L>* temp = head;
		int index = 1;
		while(temp != NULL) {
			if(temp->val == data) {
				return index;
			}
			temp = temp->next;
			index++;
		}
		// if the element is not present in the linked list
		return -1;
		
	}
	
};

// int main() {
	
// 	return 0;
// }