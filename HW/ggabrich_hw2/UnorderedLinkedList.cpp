#include <string>
#include "UnorderedLinkedList.hpp"
using namespace std;

// a constructor for a new linked list with no parameters
UnorderedLinkedList::UnorderedLinkedList() // O(1) 
	: head(nullptr)
{}

// inserts a new node at head of linked list with value of string word,
// sets head to this new node.
void UnorderedLinkedList::insert(string word) { // O(1)
	head = ListNode::insert(word, head);
}

// searched through the linked list for a node with info == string word.
// returns true if found else false.
bool UnorderedLinkedList::find(string word) { // O(N)
	return ListNode::find(word, head);
}

// searched through the linked list for node with info == string word
// and deleted the node, handling edge cases appropriately
void UnorderedLinkedList::remove(string word) { // O(N)
	head = ListNode::remove(word, head);
}

// prints each node in the linked list.
void UnorderedLinkedList::print(ostream & out) { // O(N)
	ListNode::print(out, head);
}

// returns true if head == nullptr else true.
bool UnorderedLinkedList::isEmpty() { // O(1)
	if (head == nullptr) {
		return true;
	} else {
		return false;
	}
}

// destroys all nodes in linked list.
UnorderedLinkedList::~UnorderedLinkedList() { // O(N)
	ListNode::recursiveClear(head);
}
