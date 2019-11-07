// George Gabricht
//
// ggabrich - 56735102


#ifndef LINKEDSTACK_HPP

#define LINKEDSTACK_HPP

#include "Stack.hpp"
using namespace std;

class LinkedStack : public Stack {

private:
	struct StackNode {
		string value;
		StackNode *next;

		StackNode(string & word, StackNode *nxt)
		: value(word), next(nxt)
		{}

		static StackNode * push(string & word, StackNode * nod) { // O(1)
			return new StackNode(word, nod);
		}

		static string pop(StackNode * nod) { // O(1)
			string result = nod->value;
			delete nod;
			return result;
		}

		static string top(StackNode * nod) { // O(1)
			return nod->value;
		}	

		static void recursiveRemove(StackNode * nod) { // O(N)
			if (nod == nullptr) {
				return;
			} else {
				recursiveRemove(nod->next);
				delete nod;
				return;
			}
		}
	};

	StackNode *head;	

public:
	LinkedStack()
	: head(nullptr) 
	{}

	virtual void push(string & word) override { // O(1)
		head = StackNode::push(word, head);
	}

	virtual string pop() override { // O(1)
		if (isEmpty()) {
			char msg[] = "Error: Pop on Empty Stack.";
			throw ContainerUnderflow(msg);
		}
		StackNode * temp = head;
		head = head->next;
		return StackNode::pop(temp);
	}

	virtual string top() override { // O(1)
		if (isEmpty()) {
			char msg[] = "Error: Top on Empty Stack.";
			throw ContainerUnderflow(msg);
		}
		return StackNode::top(head);
	}

	virtual bool isEmpty() override { // O(1)
		return head == nullptr;
	}

	virtual bool isFull() override { // O(1)
		return false;
	}

	~LinkedStack() { // O(N)
		StackNode::recursiveRemove(head);
	}	
};	

#endif // LINKEDSTACK_HPP




