// George Gabricht
//
// ggabrich - 56735102


#ifndef LINKEDQUEUE_HPP

#define LINKEDQUEUE_HPP

#include "Queue.hpp"
using namespace std;

class LinkedQueue : public Queue {

private:
	struct QueueNode {
		string value;
		QueueNode * next;
		
		QueueNode(string & word, QueueNode * nxt)
		: value(word), next(nxt)
		{}

		static QueueNode * enq(string & word, QueueNode * nod) { // O(1)
			nod->next = new QueueNode(word, nullptr);
			return nod->next;
		}

		static string deq(QueueNode * nod) { // O(1)
			string result = nod->value;
			delete nod;
			return result;
		}
	
		static string front(QueueNode * nod) { // O(1)
			return nod->value;
		}

		static void recursiveDelete(QueueNode * nod) { // O(N)
			if (nod == nullptr) {
				return;
			} else {
				recursiveDelete(nod->next);
				delete nod;
				return;
			}
		}	

	};

	QueueNode *head, *tail;

public:
	LinkedQueue() 
	: head(nullptr), tail(nullptr)
	{}
	
	virtual void enq(string & word) override { // O(1)
		if (isEmpty()) {
			head = tail = new QueueNode(word, nullptr);
		} else {
			tail = QueueNode::enq(word, tail);
		}
	}
	
	virtual string deq() override { // O(1)
		if (isEmpty()) {
			char msg[] = "Error: Dequeue on Empty Queue";
			throw ContainerUnderflow(msg);
		} else if (head == tail) {
			tail = nullptr;
		}
		QueueNode * temp = head;
		head = head->next;
		return QueueNode::deq(temp);
	}

	virtual string front() override { // O(1)
		if (isEmpty()) {
			char msg[] = "Error: Front on Empty Queue";
			throw ContainerUnderflow(msg);
		}
		return QueueNode::front(head);
	}

	virtual bool isEmpty() override { // O(1)
		return head == nullptr;
	}
	
	virtual bool isFull() override { // O(1)
		return false;
	}

	~LinkedQueue() { // O(N)
		QueueNode::recursiveDelete(head);
	}
};


#endif // LINKEDQUEUE_HPP
