// George Gabricht
//
// 56735102 - ggabrich

#ifndef HEAPSORTER_HPP

#define HEAPSORTER_HPP

#include "Sorter.hpp"

class HeapSorter : public Sorter {
private:
	// left child
	// O(1)
	int leftChild(int ndx) {
		return 2 * ndx + 1;
	}
	
	// right child
	// O(1)
	int rightChild(int ndx) {
		return 2 * ndx + 2;
	}

	// convert to binary heap
	// O(log N)
	void heapify(int root, int size) {
		int max = root; // 1
		int left = leftChild(root); // 1
		int right = rightChild(root); // 1
		
		if (left < size && words[left] > words[max]) { // 1
			max = left; // 1
		}
		if (right < size && words[right] > words[max]) { // 1
			max = right; // 1
		}

		if (max != root) { // 1
			words[root].swap(words[max]); // 1
			heapify(max, size); // log N 
		}
	}

public:

	HeapSorter(int capacity)
	: Sorter(capacity)
	{}

	// O(N log N)
	virtual void sort() override {
		// convert array to binary heap
		for (int ndx = size / 2 - 1; ndx >= 0; ndx--) { // N / 2
			heapify(ndx, size); // log N
		}

		for (int ndx = size - 1; ndx >= 0; ndx--) { // N
			words[0].swap(words[ndx]); // 1
			// sift-down to move largest val to root
			heapify(0, ndx); // log N
			// place largest value at end of heap
			// decrease heap size by one
			// continue to root
		}
	}

};

#endif // HEAPSORTER_HPP
