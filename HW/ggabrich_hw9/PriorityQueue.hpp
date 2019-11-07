// George Gabricht
//
// 56735102 - ggabrich


#ifndef PRIORITYQUEUE_HPP

#define PRIORITYQUEUE_HPP

#define ROOT 0
#define UNDF -1

#include <fstream>
#include <iostream>
using namespace std;

// THIS IS A TEMPLATED CLASS THAT RELIES ON THE TYPE BEING STORED POSSESSING THESE ATTRIBUTES:
// 1) getVal() Method that returns the value to be compared
// 2) getKey() method that returns the key being compared
struct vNode {

public:
	int vertex, weightSum;

	// O(1)
	vNode() : vertex(UNDF), weightSum(INT_MAX) {}

	// O(1)
	vNode(int v, int sum) : vertex(v), weightSum(sum) {}

	// O(1)
	int getKey() {
		return vertex;
	}

	// O(1)
	int getVal() {
		return weightSum;
	}

};

template <typename Type>
class PriorityQueue {

//private:
public:
	int capacity, size, *ndxs;
	Type *values;
	bool newVal;

	// O(1)
	static int parent(int ndx) {
		return (ndx - 1) / 2;
	}

	// O(1)
	static int leftChild(int ndx) {
		return 2 * ndx + 1;
	}

	// O(1)
	static int rightChild(int ndx) {
		return 2 * ndx + 2;
	}

	// O(1)
	void swap(int left, int right) {
		Type temp = values[left];
		values[left] = values[right];
		values[right] = temp;
	}

	// O(log N)
	void insert(Type val) {
		if (isFull()) { // 1
			cerr << "Error, Priority Queue is Full!" << endl;
			return;	
		}	

		values[size] = val; // 1
		ndxs[val.getKey()] = size; // 1
		PriorityQueue<Type>::siftUp(size++); // log N 
	} 

	// O(log N)
	Type extractMin() {
		if (isEmpty()) { // 1
			cerr << "Could not extract min! Priority Queue is Empty!" << endl; // 1
			return Type(); // 1
		}

		Type min = values[ROOT]; // 1
		ndxs[values[ROOT].getKey()] = UNDF; // 1
		values[ROOT] = values[--size];	// 1

		PriorityQueue<Type>::heapify(ROOT); // log N 
		return min; // 1
	}

	// O(log N)
	void decreaseKey(int ndx, Type val) {
		ndxs[val.getKey()] = ndx; // 1
		values[ndx] = val; // 1
		PriorityQueue<Type>::siftUp(ndx); // log N 
	}

	// O(log N)
	void siftUp(int ndx) {
		int parNdx = parent(ndx); // 1
		// cout << "Ndx: " << ndx <<  " - Parent: " << parNdx << endl;
		for (int curNdx = ndx; curNdx > 0; curNdx = parNdx, parNdx = parent(curNdx)) { // log N
			if (values[curNdx].getVal() > values[parNdx].getVal()) { // 1
				break; // 1
			}
		
			swap(curNdx, parNdx); // 1
			std::swap(ndxs[values[curNdx].getKey()], ndxs[values[parNdx].getKey()]); // 1
		}
	}

	// O(log N)
	void heapify(int ndx) {
		int min = ndx; // 1
		int left = leftChild(ndx); // 1
		int right = rightChild(ndx); // 1

		if (left < size && values[left].getVal() < values[min].getVal()) { // 1
			min = left; // 1
		}

		if (right < size && values[right].getVal() < values[min].getVal()) { // 1
			min = right; // 1
		}

		if (min != ndx) { // 1
			PriorityQueue<Type>::swap(min, ndx); // 1
			std::swap(ndxs[values[min].getKey()], ndxs[values[ndx].getKey()]); // 1
			PriorityQueue<Type>::heapify(min); // log N
		}
	}

// public:
	// O(1)
	PriorityQueue(int cap)
	: capacity(cap), size(0), ndxs(new int[cap]), values(new Type[cap]) {
		for (int ndx = 0; ndx < capacity; ndx++) {
			ndxs[ndx] = UNDF;
		}
	}

	// O(1)
	int length() {
		return size;
	}

	/*
	// O(1)
	int & operator[] (int ndx) {
		return values[ndxs[ndx]]; // 1
	}
	*/

	// O(1)
	int getCapacity() {
		return capacity;
	}

	// O(1)
	bool isEmpty() {
		return size == 0;
	}

	// O(1)
	bool isFull() {
		return size == capacity;
	}

	// O(log N)
	void enqueue(Type newVal) {
		int ndx = ndxs[newVal.getKey()]; // 1
		if (ndx > UNDF) { // 1
			PriorityQueue<Type>::decreaseKey(ndx, newVal); // log N
			return; // 1
		}

		PriorityQueue<Type>::insert(newVal); // log N	
	}

	// O(log N)
	Type dequeue() {
		// cout << "Size: " << size << endl;
		return PriorityQueue<Type>::extractMin(); // log N		
	}

	// O(1)
	Type peek() {
		return values[ROOT]; // 1
	}

	// O(N)
	void print(ostream & out) {
		out << "PQ: " << endl; // 1
		for (int ndx = 0; ndx < size; ndx++) { // N
			out << "Ndx: " << ndx << "\tVal: " << values[ndx].getKey(); // 1
			out << "\t" << values[ndx].getVal() << endl; // 1
		} 
		out << endl; // 1
	}

	// O(1)
	~PriorityQueue() {
		delete[] values;
		delete[] ndxs;
	}
};

#endif // PRIORITYQUEUE_HPP

