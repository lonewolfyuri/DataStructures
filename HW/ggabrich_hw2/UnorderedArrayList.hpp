// Name - George A Gabricht
//
// UCI ID# - 56735102

#ifndef UNORDEREDARRAYLIST_HPP
#define UNORDEREDARRAYLIST_HPP

#include <string>
using namespace std;

class UnorderedArrayList {
private:
	string * buf; // stores the dynamic string array
	int capacity; // stores the capacity of buf (max)
	int size; // stores the actual count of strings in buf

	// creates a new dynamic array of size 2*oldCap and transfers all data.
	// deletes oldArray and returns the new one.
	string * resizeArray(int oldCap, string *oldArray); // O(N)


public:
	// constructor, which, give a capacity, max_len, creates an array list
	// of that capacity.
	UnorderedArrayList(int max_len); // O(1)

	// inserts string word into the array list
	void insert(string word); // O(N)

	// finds string word in the array list. 
	// If found, returns true, else false.
	bool find(string word); // O(N)

	// removes string word from the array list.
	void remove(string word); // O(N^2)

	// prints each string in the arraylist to out.
	void print(ostream & out); // O(N)

	// returns true if size == 0, else false.
	bool isEmpty(); // O(1)

	// destroys the array list.
	~UnorderedArrayList(); // O(1)
};


#endif // UNORDEREDARRAYLIST_HPP
