// Name - George A Gabricht
//
// UCI ID# - 56735102

#ifndef ORDEREDARRAYLIST_HPP
#define ORDEREDARRAYLIST_HPP

#include <string>
#include "OrderedList.hpp"
using namespace std;

class OrderedArrayList : public OrderedList {
private:
	string * buf; // stores the dynamic string array
	int capacity; // stores the capacity of buf (max)
	int size; // stores the actual count of strings in buf

	// creates a new dynamic array of size 2*oldCap and transfers all data.
	// deletes oldArray and returns the new one.
	string * resizeArray(int oldCap, string *oldArray); // O(N)

	// uses recursive binary search algorithm to find and return index of key
	// else returns index of where key belongs in sorted array. 
	int binary_search(string key, int min, int max); // O(log N)

	// copies all items from index hole down to the end of the array
	// leaving a hole at index hole for insertion.
	void copy_down(int hole); // O(N)

	// copies all items from size-1 down to index cover,
	// removing item at index cover from list and decrementing size;
	void copy_up(int cover); // O(N)
	

public:
	// constructor, which, give a capacity, max_len, creates an array list
	// of that capacity.
	OrderedArrayList(int max_len); // O(1)

	// inserts string word into the array list
	virtual void insert(string word) override; // O(N)

	// finds string word in the array list. 
	// If found, returns true, else false.
	virtual bool find(string word) override; // O(log N)

	// removes string word from the array list.
	virtual void remove(string word) override; // O(N)

	// prints each string in the arraylist to out.
	virtual void print(ostream & out) override; // O(N)

        // prints a header for testing purposes
        virtual void printTest(ostream & out) override; // O(1)

	// returns true if size == 0, else false.
	bool isEmpty(); // O(1)

	// returns true if size == capacity, else false.
	bool isFull();	// O(1)

	// destroys the array list.
	~OrderedArrayList(); // O(1)
};


#endif // ORDEREDARRAYLIST_HPP
