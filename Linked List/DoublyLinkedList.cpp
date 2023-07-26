#include <iostream>
using namespace std;

// creating node class
template <class L> 
class NodeDLL 
{
public:
	L val;
	NodeDLL<L>* next;
	NodeDLL<L>* prev;
	
	//constructor for initializing a node
	NodeDLL(L data) {
		val = data;
		next = NULL;
		prev = NULL;
	}
};

// creating Doubly linked list
template <class L>
class DoublyLinkedList {
	
public:
	
	//  creating a head node and assigning it NULL initially
	NodeDLL<L>* head;
	DoublyLinkedList<L>() {
		head = NULL;
	}
	
	// creating insertNode function
	
	void insertNode(L data) {
		if(head == NULL) {
			//when there is no element in the linked list
			head = new NodeDLL<L>(data);
		} else {
			// iterate till last element of the linked list
			NodeDLL<L>* temp = new NodeDLL<L>(data);
			NodeDLL<L>* iteratorNode = head;
			while(iteratorNode->next != NULL) {
				iteratorNode = iteratorNode->next;
			}
			iteratorNode->next = temp;
			temp->prev = iteratorNode;
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
		int length = 0;
		NodeDLL<L>* temp = head;
		while(temp != NULL) {
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
			head = head->next;
			head->prev = NULL;
			delete temp;
			return;
		}
		
		//deleting last element of linked list
		if(index == length) {
			NodeDLL<L>* temp1 = head;
			while(temp1->next->next != NULL) {
				temp1 = temp1->next;
			}
			NodeDLL<L>* temp2 = temp1->next;
			temp2->next = NULL;
			delete temp2;
		}
		
		// deleting any other node in the linked list
		NodeDLL<L>* temp1 = head;
		index = index - 1;
		while(index > 1) {
			temp1 = temp1->next;
			index--;
		}
		NodeDLL<L>* temp2 = temp1->next;
		temp1->next = temp2->next;
		temp2->next->prev = temp1;
		delete temp2;
		
		
	}
	
	// creating a function to Search the given element and return it's index. 
	//Function returns -1 if element is not present in the linked list
	int searchElementIndex(L data) {
		// if linked list is empty
		if(head == NULL) {
			return -1;
		}
		
		NodeDLL<L>* temp = head;
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
	
	// print the list
	void printList() {
		NodeDLL<L>* temp = head;
		while(temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
			
		}
		cout << endl;
	}
	
};

int main() {
	
	DoublyLinkedList<int> intDList;
	intDList.insertNode(4);
	intDList.insertNode(3);
	intDList.insertNode(2);
	intDList.insertNode(1);
	intDList.printList();
	ind = intDList.searchElementIndex(3);
	cout << ind << endl;
	intDList.deleteNode(2);
	intDList.printList();
	
	return 0;
}
