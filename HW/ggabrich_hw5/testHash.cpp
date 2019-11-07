// George Gabricht
//
// 56735102 - ggabrich

#include <iostream>
#include <fstream>
#include "ChainedHashTable.hpp"
#include "Timer.h"
using namespace std;

// Worst Case: O(N^2) When N == L
// Typical Case: O(N)
double insertAll(ChainedHashTable & tbl, const char* inputFileName, int numWords) {
	ifstream ifile(inputFileName); // 1
	if (!ifile.is_open()) { // 1
                cout << "File Error!" << endl; // 1
                exit(-1); // 1
        }
	string curLine; // 1
	int ndx = 0; // 1
	Timer t;
	double eTime;
	t.start();
	while (getline(ifile, curLine)) { // N
		if (++ndx > numWords) { // 1
			break; // 1
		} 
		tbl.insert(curLine, 1); // N/L
		/*if (ndx % 1000 == 0) {
			cout << "i";
		}*/
	}
	t.elapsedUserTime(eTime);
	// cout << endl; // 1
	ifile.close(); // 1
	return eTime;
}	

// Worst Case: O(N^2) When N == L
// Typical Case: O(N)
double findAll(ChainedHashTable & tbl, const char* inputFileName, int numWords) {
	ifstream ifile(inputFileName); // 1
	if (!ifile.is_open()) { // 1
                cout << "File Error!" << endl; // 1
                exit(-1); // 1
        }
	string curLine; // 1
	int ndx = 0; // 1
	Timer t;
	double eTime;
	t.start(); 
	while (getline(ifile, curLine)) { // N
		if (++ndx > numWords) { // 1
			break; // 1
		} else if (tbl.find(curLine) < 0) { // N/L
			cout << "Not Found: " << curLine << endl; // 1
		}
		/*if (ndx % 1000 == 0) {
			cout << "f";
		}*/
	}
	t.elapsedUserTime(eTime);
	// cout << endl; // 1
	ifile.close(); // 1
	return eTime;
}

// Worst Case: O(N^2) When N == L
// Typical Case: O(N)
double removeAll(ChainedHashTable & tbl, const char* inputFileName, int numWords) {
	ifstream ifile(inputFileName); // 1
	if (!ifile.is_open()) { // 1
		cout << "File Error!" << endl; // 1
		exit(-1); // 1
	}	
	string curLine; // 1
	int ndx = 0; // 1
	Timer t;
	double eTime;
	t.start();
	while (getline(ifile, curLine)) { // N
		if (++ndx > numWords) { // 1
			break; // 1
		}
		tbl.remove(curLine); // N/L
		/*if (ndx % 1000 == 0) {
			cout << "r";
		}*/
	}
	t.elapsedUserTime(eTime);
	// cout << endl; // 1
	ifile.close(); // 1
	return eTime;
}

//individual method-testing functions//
void testConstructor(Hasher & hasher) { 
 	//create an empty ChainedHashTable object
	ChainedHashTable newTable(900, hasher);
}

void testCopyConstructor(Hasher & hasher) { 
    	//create a ChainedHashTable object
	ChainedHashTable newTable(900, hasher);
  	//create a second object as a copy of the first object
	ChainedHashTable newerTable(newTable);
}

// create tester functions
void testInsert(Hasher & hasher) {
	cout << "Test Insert: " << endl;
	// create new CHT obj
	ChainedHashTable hashTbl(100, hasher);
	// insert a few random words
	hashTbl.insert("apple", 5);
	hashTbl.insert("Akira", 100);
	hashTbl.insert("Kawasaki");
	// traverse each linked list and print key val pairs
	hashTbl.printTable(cout);
	cout << endl;
}

void testFind(Hasher & hasher) {
	cout << "Test Find: " << endl;
	// create new CHT obj
	ChainedHashTable hashTbl(100, hasher);
	cout << hashTbl.find("blah") << endl;
	cout << hashTbl["blah"] << endl;
        // insert a few random words
        hashTbl.insert("apple", 5);
        hashTbl.insert("Akira", 100);
        hashTbl.insert("Kawasaki");
	// find each word
	cout << hashTbl.find("Akira") << endl;
	cout << hashTbl.find("blah") << endl;
	cout << hashTbl.find("Kawasaki") << endl;
	cout << hashTbl.find("apple") << endl; 
	// increment by reference
	hashTbl["Akira"]++;
	cout << hashTbl["Akira"] << endl;
	cout << ++hashTbl["apple"] << endl;
	hashTbl["blah"]++;
	cout << hashTbl["blah"] << endl;
	// find each word again
	cout << hashTbl.find("Akira") << endl;
        cout << hashTbl.find("blah") << endl;
        cout << hashTbl.find("Kawasaki") << endl;
        cout << hashTbl.find("apple") << endl; 
	cout << endl;
}

void testRemove(Hasher & hasher) {
	cout << "Test Remove: " << endl;
	// create new CHT obj
	ChainedHashTable hashTbl(100, hasher);
	// insert a few random words
	hashTbl.insert("apple", 5);
        hashTbl.insert("Akira", 100);
        hashTbl.insert("Kawasaki");
	hashTbl.printTable(cout);
	// remove some of those words
	hashTbl.remove("blah");
	hashTbl.remove("Kawasaki");
	// find the words
	cout << hashTbl.find("apple") << endl;
	cout << hashTbl.find("Kawasaki") << endl;
	cout << hashTbl.find("blah") << endl;
	cout << hashTbl.find("Akira") << endl;
	// remove the rest
	hashTbl.remove("apple");
	hashTbl.remove("Akira");
	// find the words
	hashTbl.printTable(cout);
	cout << endl;
}

//overall tester function//
void testHash(const char *inputFileName, Hasher & hasher, int numWords) { 
 	//call test functions

	/*
	testConstructor(hasher);
	testCopyConstructor(hasher);	

	testInsert(hasher);
	testFind(hasher);
	testRemove(hasher);
	*/
	
	cout << inputFileName << endl;

	double timers[10][3], mn, mx, av, dv;
	for (int ndx = 0; ndx < 10; ndx++) {
		timers[ndx][0] = 0;
		timers[ndx][1] = 0;
		timers[ndx][2] = 0;
	}
	for (int ndx = 1; ndx <= 10; ndx++) {
		int words = ndx * (numWords / 10);
	
		ChainedHashTable hashTbl(words, hasher);

		timers[ndx - 1][0] = insertAll(hashTbl, inputFileName, words);
		cout << "Words: " << words << " In: " << timers[ndx-1][0];
		if (ndx == 10) {
                        mn = hashTbl.min();
                        mx = hashTbl.max();
                        av = hashTbl.avg();
                        dv = hashTbl.dev();
                }   
		timers[ndx - 1][1] = findAll(hashTbl, inputFileName, words);
		cout << " Find: " << timers[ndx-1][1];
		timers[ndx - 1][2] = removeAll(hashTbl, inputFileName, words);	
		cout << " Remove: " << timers[ndx-1][2] << endl;
	}
	
	cout << "Hash function chain length statistics:" << endl;
	cout << "\tmin = " << mn << "; max = " << mx << "; average = " << av << "; std_dev = " << dv << endl;  
	cout << "\tinsertAll = " << timers[9][0] << " sec" << endl;
	cout << "\tfindAll = " << timers[9][1] << " sec" << endl;
	cout << "\tremoveAll = " << timers[9][2] << " sec" << endl;
}

int main(int argc, char *argv[])  {
	const char *infileName = argc == 2 ? argv[1] : "random.txt";
	const char *infileName2 = argc == 3 ? argv[2] : "words.txt";

	cout << "Test General:" << endl;
  	GeneralStringHasher g;
  	testHash(infileName, g, 45000);
	testHash(infileName2, g, 45000);

	cout << "Test Sum:" << endl;
	SumHasher s;
	testHash(infileName, s, 45000);
	testHash(infileName2, s, 45000);

	cout << "Test Prod:" << endl;
	ProdHasher p;
	testHash(infileName, p, 45000);
	testHash(infileName2, p, 45000);

	
}


