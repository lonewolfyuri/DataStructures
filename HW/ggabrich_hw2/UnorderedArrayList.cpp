#include <iostream>
#include <string>
#include "UnorderedArrayList.hpp"
using namespace std;


// constructor, which, give a capacity, max_len, creates an 
// array list of that capacity.
UnorderedArrayList::UnorderedArrayList(int max_len) // O(1)
	: buf{new string[max_len]}, capacity{max_len}, size{0}
{} 

// creates a new dynamic array of size 2*oldCap and transfers all data.
// deletes oldArray and returns the new one.
string * UnorderedArrayList::resizeArray(int oldCap, string *oldArray) { // O(N)
	string *temp = new string[oldCap * 2];
	for(int i = 0; i < oldCap; i++) {
		temp[i] = oldArray[i];
	}
	delete[] oldArray;
	return temp;
}

// inserts string word into the array list
void UnorderedArrayList::insert(string word) { // O(N)
	if (size == capacity) {
		buf = resizeArray(capacity, buf);
		capacity *= 2;
	}
	buf[size++] = word;
}		

// finds string word in the array list. 
// If found, returns true, else false.
bool UnorderedArrayList::find(string word) { // O(N)
	for (int i = 0; i < size; i++) {
		if (buf[i] == word) {
			return true;
		}
	}
	return false;
}

// removes string word from the array list.
void UnorderedArrayList::remove(string word) { // O(N^2)
	for (int i = 0; i < size; i++) {
		if (buf[i] == word) {
			for(int j = i; j < size - 1; j++) {
				buf[j] = buf[j + 1];
			}
			size--;
			return;
		}
	}
}

// prints each string in the arraylist to out.
void UnorderedArrayList::print(ostream & out) { // O(N)
	for (int i = 0; i < size; i++) {
		cout << buf[i] << endl;
	}
}

// returns true if size == 0, else false.
bool UnorderedArrayList::isEmpty() { // O(1)
	if (size == 0) {
		return true;
	} else {
		return false;
	}
}


// destroys the array list.
UnorderedArrayList::~UnorderedArrayList() { // O(1)
	delete[] buf;
}
