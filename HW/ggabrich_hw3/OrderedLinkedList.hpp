// Name - George Andrew Gabricht
//
// Student ID# - 56735102


#ifndef ORDEREDLINKEDLIST_HPP
#define ORDEREDLINKEDLIST_HPP

#include <iostream>
#include <string>
#include "OrderedList.hpp"
using namespace std;

class OrderedLinkedList : public OrderedList {
	// struct defining the nodes in the linked list
	struct ListNode {
		string info; // string containing node's info
		ListNode * next; // node pointer to next node in list
		
		// constructs new ListNode
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

		// inserts a new node in lexicographical order.
		static void insert(string word, ListNode *L) { // O(N)
			for (ListNode * cur = L; cur != nullptr; cur = cur->next) {
				if (cur->info > word) {
					cur->next = new ListNode(cur->info, cur->next);
					cur->info = word;
					break;
				} else if (cur->next == nullptr) {
					cur->next = new ListNode(word, nullptr);
					break;
				}
			}
		}

		// finds a node with info value of string word,
		// returns ptr to this node.
		static ListNode* find(string word, ListNode *L) { // O(N)
			if (L == nullptr) {
				return nullptr;
			} else if (L->info == word) {
				return L;
			} else {
				for (ListNode* cur = L; cur != nullptr; cur = cur->next) {
					if (cur->info == word) {
						return cur;
					}

				}
				return nullptr;
				//return find(word, L->next);
				//recursive approach 3x slower...
			}
		}

		// removes node with info value of string word.
		static ListNode * remove(string word, ListNode *L) { // O(N)
			if (L == nullptr) {
                                return nullptr;
                        } else if (L->info == word) {
                                ListNode *temp = L;
                                L = L->next;
                                delete temp;
                                return L;
                        } else {
                                for (ListNode *cur = L; cur->next != nullptr; cur = cur->next) {
                                        if (cur->next->info == word) {
                                                ListNode *temp = cur->next;
                                                cur->next = cur->next->next;
                                                delete temp;
                                                return L;
                                        }
                                }
				return L;
                        }
		} 

		// Revursively clears all nodes, used with destructor.
		static void recursiveClear(ListNode *L) { // O(N)
			if (L) {
				recursiveClear(L->next);
				delete L;
			}
		}
	};
	
	ListNode * head; // a ListNode pointer to the head of the linked list.
public:
	// a constructor for a new linked list with no parameters
	OrderedLinkedList(); // O(1)

	// inserts a new node in lexicographical order in 
	// linked list with value of string word
	virtual void insert(string word) override; // O(N)

	// searches through the linked list for a node with info == string word.
	// returns true if found else false.
	virtual bool find(string word) override; // O(N)

	// searches through the linked list for node with info == string word
	// and deletes the node, handling edge cases appropriately
	virtual void remove(string word) override; // O(N)

	// prints each node in the linked list.
	virtual void print(ostream & out) override; // O(N)

        // prints a header for testing purposes
        virtual void printTest(ostream & out) override; // O(1)

	// returns true if head == nullptr else true.
	bool isEmpty(); // O(1)
	
	// returns false always
	bool isFull(); // O(1)

	// destroys all nodes in linked list.
	~OrderedLinkedList(); // O(N)
};

#endif // ORDEREDLINKEDLIST_HPP
