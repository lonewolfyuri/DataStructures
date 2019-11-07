// George Gabricht
//
// 56735102 - ggabrich

#ifndef QUICKSORTER_HPP

#define QUICKSORTER_HPP

#include "Sorter.hpp"

class QuickSorter : public Sorter {
private:
	// O(N^2)
	void insertionSort(int low, int high) {
		for (int sorted = low + 1; sorted < high + 1; sorted++) { // N
			// N
			for (int ndx = sorted; ndx > low && words[ndx - 1] > words[ndx]; ndx--) {
				words[ndx].swap(words[ndx - 1]); // 1
			}
		}
	}

	// O(1)
	string findPivot(int low, int high) {
		int mid = low + (high - low) / 2; // 1
		string temp; // 1

		if (words[mid] < words[low]) { // 1
			words[mid].swap(words[low]); // 1
		}
		if (words[high] < words[low]) { // 1
			words[high].swap(words[low]); // 1
		}
		if (words[mid] < words[high]) { // 1
			words[mid].swap(words[high]); // 1
		}
		return words[high]; // 1
	}

	// O(N)
	int partition(int low, int high, string piv) {
		int bot = low, top = high - 1; // 1
		while(true) { // 1
			while(words[bot] < piv) { // O(N)
				bot++; // 1
			}
			while(piv < words[top]) { // O(N)
				top--; // 1
			}
			if(bot < top) { // 1
				words[bot++].swap(words[top--]); // 1
			} else { // 1
				break; // 1
			}
		}
		words[bot].swap(words[top]); // 1
		return bot; // 1
	}

	// O(N log N)
	void quickSort(int low, int high) {
		if (high - low < 16) { // log N
			insertionSort(low, high); // 1
		} else { // N log N	
			string piv = findPivot(low, high); // 1
			int ndx = partition(low, high, piv); // N log N
			quickSort(low, ndx - 1); // log N
			quickSort(ndx + 1, high); // log N
		}
	}

public:

	QuickSorter(int capacity)
	: Sorter(capacity)
	{}

	// O(N log N)
	virtual void sort() override {
		quickSort(0, size - 1);
	}

};

#endif // QUICKSORTER_HPP
