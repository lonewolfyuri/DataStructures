// George Gabricht
//
// 56735102 - ggabrich

#include <fstream>
#include "BinarySearchTree.hpp"
#include "Timer.h"
using namespace std;

void insertAllWords (BinarySearchTree <string, int> &T, int numWords, const char *filename) {
	ifstream ifile(filename);
	if (!ifile.is_open()) {
		cout << "File Error!" << endl;
		exit(-1);
	}
	string curLine;
	Timer t;
	double eTime;
	t.start();
	for (int ndx = 0; getline(ifile, curLine) && ndx < numWords; ndx++) {
		T.insert(curLine, 1);
	}
	t.elapsedUserTime(eTime);
	ifile.close();
	cout << "File: " << filename << ". Num Words: " << numWords << ".\t Function: insertAllWords.\tTime: " << eTime << "s" << endl; 	
}

void findAllWords (BinarySearchTree <string, int> &T, int numWords, const char *filename) {
	ifstream ifile(filename);
        if (!ifile.is_open()) {
                cout << "File Error!" << endl;
                exit(-1);
        }
        string curLine;
        Timer t;
        double eTime;
        t.start();
        for (int ndx = 0; getline(ifile, curLine) && ndx < numWords; ndx++) {
                int result = T.find(curLine);
		if (result <= 0) {
			cout << "Couldn't Find: " << curLine << endl;
		}/* else if (ndx % 1000 == 0) {
			// cout << curLine << endl;
		}*/
        }
        t.elapsedUserTime(eTime);
        ifile.close();
        cout << "File: " << filename << ". Num Words: " << numWords << ".\t Function: findAllWords.\tTime: " << eTime << "s" << endl;
}

void removeAllWords (BinarySearchTree <string, int> &T, int numWords, const char *filename) {
	ifstream ifile(filename);
        if (!ifile.is_open()) {
                cout << "File Error!" << endl;
                exit(-1);
        }
        string curLine;
        Timer t;
        double eTime;
        t.start();
        for (int ndx = 0; getline(ifile, curLine) && ndx < numWords; ndx++) {
		/*if (ndx % 100 == 0) {
			// cout << curLine << endl;
      		}*/
		T.remove(curLine);
	}
	// cout << curLine << endl;
        t.elapsedUserTime(eTime);
        ifile.close();
        cout << "File: " << filename << ". Num Words: " << numWords << ".\t Function: removeAllWords.\tTime: " << eTime << "s" << endl;
}

void measureAll (const char *filename, int totalWords) {
	for (int ndx = 1; ndx <= 10; ndx++) {
		BinarySearchTree <string, int> T;

		insertAllWords(T, totalWords / 10 * ndx, filename);
		findAllWords(T, totalWords / 10 * ndx, filename);
		removeAllWords(T, totalWords / 10 * ndx, filename);
	
	}
}

void lengthTest(const char *filename) {
	ifstream ifile(filename);
	if (!ifile.is_open()) {
		cout << "File Error!" << endl;
		exit(-1);
	}
	BinarySearchTree<string, int> T;
	for (string curLine; getline(ifile, curLine);) {
		T.insert(curLine, 1);
	}
	cout << endl << " Words in " << filename << " of:" << endl;
	T.countLengths();
}

int main(int argc, char *argv[]) {
	const char *infileName = argc >= 2 ? argv[1] : "random.txt";
	const char *lenFileName = argc >= 3 ? argv[2] : "random_small.txt";

	measureAll(infileName, 45000);

	lengthTest(lenFileName);

	return 0;
}


