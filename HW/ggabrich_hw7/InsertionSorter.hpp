// George Gabricht
//
// 56735102 - ggabrich

#ifndef INSERTIONSORTER_HPP

#define INSERTIONSORTER_HPP

#include "Sorter.hpp"

class InsertionSorter : public Sorter {
public:

	InsertionSorter(int capacity)
	: Sorter(capacity) 
	{}

	// O(N^2)
	virtual void sort() override {
		for (int sorted = 1; sorted < size; sorted++) { // N
			for (int ndx = sorted; ndx > 0 && words[ndx - 1] > words[ndx]; ndx--) {//N
				string temp = words[ndx]; // 1
				words[ndx] = words[ndx - 1]; // 1
				words[ndx - 1] = temp; // 1
			}
		}
	}
};

#endif // INSERTIONSORTER_HPP

