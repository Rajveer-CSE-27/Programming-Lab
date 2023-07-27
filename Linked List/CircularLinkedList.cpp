#include <iostream>
using namespace std;

template <class L> 
class NodeCircularLinkedList {
public:
	L val;
	NodeCircularLinkedList<L>* next;
	
	//constructor for initializing a node
	NodeCircularLinkedList(L data) {
		val = data;
		next = NULL;
	}
};


// creating circular linked list class
// creating Linked List class
template <class L>
class CircularLinkedList {
	
public:
	
	//  creating a head node and assigning it NULL initially
	NodeCircularLinkedList<L>* head;
	CircularLinkedList<L>() {
		head = NULL;
	}
	
	// creating insertNode function
	
	void insertNode(L data) {
		if(head == NULL) {
			//when there is no element in the linked list
			head = new NodeCircularLinkedList<L>(data);
			head->next = head;
			
		} else {
			// iterate till last element of the linked list
			NodeCircularLinkedList<L>* temp = new NodeCircularLinkedList<L>(data);
			NodeCircularLinkedList<L>* iteratorNode = head;
			while(iteratorNode->next != head) {
				iteratorNode = iteratorNode->next;
			}
			iteratorNode->next = temp;
			temp->next = head;
		}
	}
	
	//creating a deleteNode function
	void deleteNode(int index) {
		// indexing must be 1 based
		if(head == NULL) {
			cout << "List Empty" << endl;
			return;
		}
		
		// finding length of the linked list
		int length = 1;
		NodeCircularLinkedList<L>* temp = head->next;
		
		while(temp != head) {
			temp = temp->next;
			length++;
		}
		
		
		// if index is greater than the length of the linked list
		if(index > length) {
			cout << "Required index is greater than LinkedList" << endl;
			return;
		}
		
		// if we want to delete the head
		if(index == 1) {
			temp = head;
			NodeCircularLinkedList<L>* temp2 = head;
			while(temp2->next != head) {
				temp2 = temp2->next;
			}
			temp2->next = head->next;
			head = temp2->next;
			delete temp;
		}
		
		// deleting any other node in the linked list
		NodeCircularLinkedList<L>* temp1 = head;
		index = index - 1;
		while(index > 1) {
			temp1 = temp1->next;
			index--;
		}
		NodeCircularLinkedList<L>* temp2 = temp1->next;
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
		
		NodeCircularLinkedList<L>* temp = head;
		if(temp->val == data) {
			return 1;
		}
		temp = temp->next;
		int index = 2;
		while(temp != head) {
			if(temp->val == data) {
				return index;
			}
			temp = temp->next;
			index++;
		}
		// if the element is not present in the linked list
		return -1;
		
	}
	
	// print the list
	void printList() {
		NodeCircularLinkedList<L>* temp = head->next;
		if(temp == NULL) {
			return;
		}
		cout << temp->val << " ";
		while(temp != head) {
			cout << temp->val << " ";
			temp = temp->next;
			
		}
		cout << endl;
	}
	
};




int main() {
	
	
	CircularLinkedList<int> intCList;
	intCList.insertNode(4);
	intCList.insertNode(3);
	intCList.insertNode(2);
	intCList.insertNode(1);
	intCList.printList();
	ind = intCList.searchElementIndex(3);
	cout << ind << endl;
	intCList.deleteNode(2);
	intCList.printList();
	
	return 0;
}
