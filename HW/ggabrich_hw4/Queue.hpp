// George Gabricht
//
// ggabrich - 56735102


#ifndef QUEUE_HPP

#define QUEUE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "ContainerException.hpp"

class Queue {

public:

	virtual void enq(string & word) = 0;
	
	virtual string deq() = 0;

	virtual string front() = 0;

	virtual bool isEmpty() = 0;

	virtual bool isFull() = 0;
};

void fillAll(Queue * que, ifstream & instream) { // O(N)
	string curLine;
	while (getline(instream, curLine)) {	
		que->enq(curLine);
	}
}

void emptyAll(Queue * que, ofstream & outstream) { // O(N)
	while (!que->isEmpty()) {
		outstream << que->deq() << endl;
	}
}

#endif // QUEUE_HPP
