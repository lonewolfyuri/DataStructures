// Name - George Andrew Gabricht
//
// Student ID# - 56735102


#ifndef UNORDEREDLINKEDLIST_HPP
#define UNORDEREDLINKEDLIST_HPP

#include <iostream>
#include <string>
using namespace std;

class UnorderedLinkedList 
{
	// struct defining the nodes in the linked list
	struct ListNode {
		string info; // string containing node's info
		ListNode * next; // node pointer to next node in list
		
		// constructs new ListNode at front of list
		ListNode(string new_info, ListNode *new_next) // O(1)
			 : info(new_info), next(new_next) 
		{}
		
		// prints each node from this node until nullptr
		static void print(ostream & out, ListNode *L) { // O(N)
			if (L) {
				out << L->info << endl;
				print(out, L->next);
			}
		}

		// inserts a new node at the front of the list and returns new head.
		static ListNode* insert(string word, ListNode *L) { // O(1)
			ListNode *newNode = new ListNode(word, L);
			return newNode;
		}

		// finds a node with info value of string word,
		// returns true if found else false.
		static bool find(string word, ListNode *L) { // O(N)
			for (ListNode *cur = L; cur != nullptr; cur = cur->next) {
				if (cur->info == word) {
					return true;
				}
			}
			return false;
		}

		// removes node with info value of string word.
		static ListNode* remove(string word, ListNode *L) { // O(N)
			if (L == nullptr) {
				return nullptr;
			} else if (L->info == word) {
				ListNode *temp = L;
				L = L->next;
				delete temp;
				return L;
			} else {
				for (ListNode *cur = L; cur->next != nullptr; cur++) {
					if (cur->next->info == word) {
						ListNode *temp = cur->next;
						cur->next = cur->next->next;
						delete temp;
						return L;
					}
				}
			}
		} 

		// Revursively clears all nodes, used with destructor.
		static void recursiveClear(ListNode *L) { // O(N)
			if (L == nullptr) {
				return;
			} else {
				recursiveClear(L->next);
				delete L;
			}
		}
	};
	
	ListNode * head; // a ListNode pointer to the head of the linked list.
public:
	// a constructor for a new linked list with no parameters
	UnorderedLinkedList(); // O(1)

	// inserts a new node at head of linked list with value of string word,
	// sets head to this new node.
	void insert(string word); // O(1)

	// searched through the linked list for a node with info == string word.
	// returns true if found else false.
	bool find(string word); // O(N)

	// searched through the linked list for node with info == string word
	// and deleted the node, handling edge cases appropriately
	void remove(string word); // O(N)

	// prints each node in the linked list.
	void print(ostream & out); // O(N)

	// returns true if head == nullptr else true.
	bool isEmpty(); // O(1)

	// destroys all nodes in linked list.
	~UnorderedLinkedList(); // O(N)
};

#endif // UNORDEREDLINKEDLIST_HPP
