#include <iostream>
#include <string>
#include "OrderedArrayList.hpp"
using namespace std;


// constructor, which, give a capacity, max_len, creates an 
// array list of that capacity.
OrderedArrayList::OrderedArrayList(int max_len) // O(1)
	: buf{new string[max_len]}, capacity{max_len}, size{0}
{} 

// creates a new dynamic array of size 2*oldCap and transfers all data.
// deletes oldArray and returns the new one.
string * OrderedArrayList::resizeArray(int oldCap, string *oldArray) { // O(N)
	string *temp = new string[oldCap * 2];
	for(int i = 0; i < oldCap; i++) {
		temp[i] = oldArray[i];
	}
	delete[] oldArray;
	return temp;
}


// uses recursive binary search algorithm to find and return index of key
// else returns index of where key belongs in sorted array. 
int OrderedArrayList::binary_search(string key, int min, int max) { // O(log N)
	int mid = min + (max - min) / 2;

	if (min > max) {
		return mid;
	} else if (key < buf[mid]) {
		return binary_search(key, min, mid - 1);
	} else if (key > buf[mid]) {
		return binary_search(key, mid + 1, max);
	} else {
		return mid;
	}
} 

// copies all items from index hole down to the end of the array
// leaving a hole at index hole for insertion.
void OrderedArrayList::copy_down(int hole) { // O(N)
	for (int ndx = size; ndx > hole; ndx--) {
		buf[ndx] = buf[ndx - 1];
	}
	++size;
}

// copies all items from size-1 down to index cover,
// removing item at index cover from list and decrementing size;
void OrderedArrayList::copy_up(int cover) { // O(N)
	for (int ndx = cover; ndx < size - 1; ndx++) {
		buf[ndx] = buf[ndx + 1];
	}
	size--;
}

// inserts string word into the array list
void OrderedArrayList::insert(string word) { // O(N)
	if (size >= 0.8*capacity) {
		buf = resizeArray(capacity, buf);
		capacity *= 2;
	} else if (isEmpty()) {
		buf[size++] = word;
	} else {
		int result = binary_search(word, 0, size - 1);
		copy_down(result);
		buf[result] = word;
	}
	
}		

// finds string word in the array list. 
// If found, returns true, else false.
bool OrderedArrayList::find(string word) { // O(log N)
	int result = binary_search(word, 0, size - 1);
	return word == buf[result];
}

// removes string word from the array list.
void OrderedArrayList::remove(string word) { // O(N)
	int result = binary_search(word, 0, size - 1);
	if (word == buf[result]) {
		copy_up(result);
	}
}

// prints each string in the arraylist to out.
void OrderedArrayList::print(ostream & out) { // O(N)
	for (int i = 0; i < size; i++) {
		out << buf[i] << endl;
	}
}

// prints a header for testing purposes
void OrderedArrayList::printTest(ostream & out) { // O(1)
	out << "Testing OrderedArrayList:" << endl;
}

// returns true if size == 0, else false.
bool OrderedArrayList::isEmpty() { // O(1)
	return size == 0;
}

// returns true if size == capacity, else false.
bool OrderedArrayList::isFull() { // O(1)
	return (size == capacity);
}

// destroys the array list.
OrderedArrayList::~OrderedArrayList() { // O(1)
	delete[] buf;
}
