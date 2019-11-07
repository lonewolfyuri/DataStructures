

#ifndef ORDEREDLIST_HPP

#define ORDEREDLIST_HPP

#include <string>
using namespace std;

// Abstract base class for Ordered List types with 
// capabilities to insert, find and remove items.
class OrderedList {

public:

	// finds the appropriate place to insert into list and does so.
	virtual void insert(string word) = 0;

	// finds if given word is in list and returns True if is, else False.
	virtual bool find(string word) = 0;

	// finds and removes given word from list, else does nothing.
	virtual void remove(string word) = 0;

	// prints all items in ordered list.
	virtual void print(ostream & out) = 0;

	// prints a header for testing purposes
	virtual void printTest(ostream & out) = 0;
};

#endif // ORDEREDLIST_HPP
