#include <iostream>
using namespace std;

int n = 10;

int searchArray(int arr[] , int element , int size) {
	// returns -1 if element is not found
	// returns 1 based index of element in array if found
	for(int i=0; i<size; i++) {
		if(arr[i] == element) {
			return i+1;
		}
	}
	return -1;
}

void insertElement(int arr[] , int location , int element , int size) {
	//the location and size are 1 based indexing
	if(location > size || location < 1) {
		cout << "Loacation out of array";
		return;
	}
	
	// move all the elements that are right to location 1 step right and enter the element at the correct location
	for(int i=size-1; i>=location; i--) {
		arr[i] = arr[i-1];
	}
	arr[location-1] = element;
}


void deleteElement(int arr[] , int location , int size) {
	//the location and size are 1 based indexing
	if(location > size || location < 1) {
		cout << "Loacation out of array";
		return;
	}
	
	// move all the elements that are right to location 1 step left and delete the last element
	for(int i=location-1; i<size-1; i++) {
		arr[i] = arr[i+1];
	}
	n--;
	delete &arr[size-1];
	
}

int main() {
	
	int arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int e; // element to be searched
	cout << "Enter the element to search";
	cin >> e;
	int resultOfSearch = searchArray(arr,e,n);
	cout << resultOfSearch << endl;
	
	
	
	
	
	return 0;
}
