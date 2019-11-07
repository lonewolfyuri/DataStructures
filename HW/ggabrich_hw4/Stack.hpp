// George Gabricht
//
// ggabrich - 56735102


#ifndef STACK_HPP

#define STACK_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "ContainerException.hpp"
using namespace std;

class Stack {
	
public:
	virtual void push(string & word) = 0;

	virtual string pop() = 0;
	
	virtual string top() = 0;

	virtual bool isEmpty() = 0;

	virtual bool isFull() = 0;

	// virtual ~Stack();
};

void fillAll(Stack * stk, ifstream & instream) { // O(N)
	string curLine;
	while (getline(instream, curLine)) {
		stk->push(curLine);
	}
}

void emptyAll(Stack * stk, ofstream & outstream) { // O(N)
	while (!stk->isEmpty()) {
		outstream << stk->pop() << endl;
	}
}

#endif // STACK_HPP	
