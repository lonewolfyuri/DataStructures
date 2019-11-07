#include <string>
#include "OrderedLinkedList.hpp"
using namespace std;

// a constructor for a new linked list with no parameters
OrderedLinkedList::OrderedLinkedList() // O(1) 
	: head(nullptr)
{}

// inserts a new node in lexicographical order in 
// linked list with value of string word
void OrderedLinkedList::insert(string word) { // O(N)
	if (isEmpty()) {
		head = new ListNode(word, nullptr);
	} else {
		ListNode::insert(word, head);
	}
}

// searches through the linked list for a node with info == string word.
// returns true if found else false.
bool OrderedLinkedList::find(string word) { // O(N)
	return (ListNode::find(word, head) != nullptr);
}

// searches through the linked list for node with info == string word
// and deleted the node, handling edge cases appropriately
void OrderedLinkedList::remove(string word) { // O(N)
	head = ListNode::remove(word, head);
}

// prints each node in the linked list.
void OrderedLinkedList::print(ostream & out) { // O(N)
	ListNode::print(out, head);
}

// prints a header for testing purposes
void OrderedLinkedList::printTest(ostream & out) { // O(1)
	out << "Testing OrderedLinkedList:" << endl;
}

// returns true if head == nullptr else true.
bool OrderedLinkedList::isEmpty() { // O(1)
	return (head == nullptr);
}

// returns false always
bool OrderedLinkedList::isFull() { // O(1)
	return false;
}

// destroys all nodes in linked list.
OrderedLinkedList::~OrderedLinkedList() { // O(N)
	ListNode::recursiveClear(head);
}
