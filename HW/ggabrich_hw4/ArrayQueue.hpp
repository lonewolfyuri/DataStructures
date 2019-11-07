// George Gabricht
//
// ggabrich - 56735102

#ifndef ARRAYQUEUE_HPP

#define ARRAYQUEUE_HPP

#include "Queue.hpp"

class ArrayQueue : public Queue {

private:
	string * buf;
	int capacity, top, bot;

public:
	ArrayQueue(int init_size) 
	: buf(new string[init_size + 1]), capacity(init_size), top(0), bot(0)
	{}

	virtual void enq(string & word) override { // O(1)
		if (isFull()) {
			char msg[] = "Error: Enqueue on Full Queue";
			throw ContainerOverflow(msg);
		}
		buf[bot] = word;
		bot = (bot + 1) % capacity;
	}
	
	virtual string deq() override { // O(1)
		if (isEmpty()) {
			char msg[] = "Error: Dequeue on Empty Queue";
			throw ContainerUnderflow(msg);
		}
		string result = buf[top];
		top = (top + 1) % capacity;
		return result;
	}
	
	virtual string front() override { // O(1)
		return buf[top];
	}
	
	virtual bool isEmpty() override { // O(1)
		return top == bot;
	}
	
	virtual bool isFull() override { // O(1)
		return (bot + 1) % capacity == top;
	}
	
	~ArrayQueue() { // O(1)
		delete[] buf;
	}
};


#endif // ARRAYQUEUE_HPP

