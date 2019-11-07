// George Gabricht
//
// ggabrich - 56735102


#ifndef ARRAYSTACK_HPP

#define ARRAYSTACK_HPP

#include "Stack.hpp"

class ArrayStack : public Stack {

private:
	string * buf;
	int size;
	int capacity;

public:
	ArrayStack(int init_size = 100)
	: buf(new string[init_size]), size(0), capacity(init_size)
	{}

	virtual void push(string & word) override { // O(1)
		if (isFull()) {
			char msg[] = "Error: Push on Full Stack";
			throw ContainerOverflow(msg);
		}
		buf[size++] = word;
	} 

	virtual string pop() override { // O(1)
		if (isEmpty()) {
			char msg[] = "Error: Pop on Empty Stack";
			throw ContainerUnderflow(msg);
		}
		return buf[--size];
	}

	virtual string top() override { // O(1)
		if (isEmpty()) {
			char msg[] = "Error: Top on Empty Stack";
			throw ContainerUnderflow(msg);
		}
		return buf[size - 1];
	}

	virtual bool isEmpty() override { // O(1)
		return size == 0;
	}
	
	virtual bool isFull() override { // O(1)
		return size == capacity;
	}

	~ArrayStack() { // O(1)
		delete[] buf;
	}
};


#endif // ARRAYSTACK_HPP




