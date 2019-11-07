// George Gabricht
//
// 56735102 - ggabrich

#ifndef SORTER_HPP

#define SORTER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Timer.h"
using namespace std;

class Sorter {
public:
	int capacity, size;
	string *words;

	Sorter(int capacity)
	: capacity(capacity), size(0), words(new string[capacity])
	{}

	// O(NlogN -> N^2) Depends on Sorting Algorithm
	double insertAllFromFile(int partition, char *fileName) {
		ifstream ifile(fileName); // 1
		if (!ifile.is_open()) { // 1
			cerr << "File: " << fileName << " couldn't be opened." << endl;
			return -1;
		}		

		string curLine;
		for (int ndx = 0; ndx < partition && getline(ifile, curLine); ndx++) { // N
			words[size++] = curLine; // 1
		}
	
		Timer tme; // 1
		double eTime; // 1

		tme.start(); // 1
		sort(); // Depends on Sorting Algorithm
		tme.elapsedUserTime(eTime); // 1
		
		ifile.close(); // 1
		return eTime;
	}

	void print(ostream & out) {
		for(int ndx = 0; ndx < size; ndx++) {
			out << words[ndx] << endl;
		}
	}

	virtual void sort() = 0;

	~Sorter() {
		delete[] words;
	}

};


#endif // SORTER_HPP

