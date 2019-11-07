// Name - George Andrew Gabricht
//
// Student ID# - 56735102

#include <fstream>
#include <iostream>
#include "Timer.h"
#include "OrderedList.hpp"
#include "OrderedArrayList.hpp"
#include "OrderedLinkedList.hpp"
using namespace std;

ostream & operator << (ostream & out, OrderedList & L)
{
	L.print(out); return out;
}


void insert_all_words(string file_name, OrderedList & L) // O(N^2)
{
	double eTime;
	Timer t;// declare timer object
	
	ifstream wordFile;
	string newWord;

	wordFile.open(file_name);
	
	if (wordFile.is_open()) {
		t.start();// start timer		

		while (getline(wordFile, newWord)) {
			L.insert(newWord);
		}

		t.elapsedUserTime(eTime);// stop timer		

		wordFile.close();
	}

	cout << eTime << endl;// report time
}

void find_all_words(string file_name, OrderedList & L) // O(N^2) or O{N log N) for array
{ 
	double eTime;
	Timer t;// declare timer object
	
	ifstream wordFile;
	string newWord;

	wordFile.open(file_name);

	if (wordFile.is_open()) {
		t.start();// start timer

		while (getline(wordFile, newWord)) {
			L.find(newWord);
		}

		t.elapsedUserTime(eTime);// stop timer

		wordFile.close();
	}

	cout << eTime << endl;// report time
}

void remove_all_words(string file_name, OrderedList & L) // O(N^2)
{
	double eTime;
	Timer t;// declare timer object
	
	ifstream wordFile;
	string newWord;

	wordFile.open(file_name);

	if(wordFile.is_open()) {
		t.start();// start timer

		while (getline(wordFile, newWord)) {
			L.remove(newWord);
		}

		t.elapsedUserTime(eTime);// stop timer

		wordFile.close();
	}

	cout << eTime << endl;// report time
}

void test_OrderedList_methods(string file_name, OrderedList & L) // O(N^2)
{
	L.printTest(cout);
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
	cout << endl;
}

void print_test(string file_name, OrderedList & L) { // O(N^2)
	L.printTest(cout);
	insert_all_words(file_name, L);
	cout << L << endl;
	remove_all_words(file_name, L);
	cout << endl;
}	

int main(int argc, char * argv[]) // O(N^2)
{
	const char * input_file = argc == 2 ? argv[1] : "random.txt";
	bool printIndices = argc == 2 ? true : false;
	
	OrderedArrayList OAL(45500);
	if (printIndices) {
		print_test(input_file, OAL);
	} else {
		test_OrderedList_methods(input_file, OAL);
	}	

	OrderedLinkedList OLL;
	if (printIndices) {
		print_test(input_file, OLL);
	} else {
		test_OrderedList_methods(input_file, OLL);
	}

	return 0;
}

