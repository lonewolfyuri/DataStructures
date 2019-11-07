// George Gabricht
//
// 56735102 - ggabrich

#include <iomanip>
#include "InsertionSorter.hpp"
#include "QuickSorter.hpp"
#include "HeapSorter.hpp"
using namespace std;

void measureSort(double *eTime, int partSize, const char *fileName) {
	InsertionSorter iSort(partSize);
	QuickSorter qSort(partSize);
	HeapSorter hSort(partSize);

	eTime[0] = iSort.insertAllFromFile(partSize, (char *) fileName);
	eTime[1] = qSort.insertAllFromFile(partSize, (char *) fileName);
	eTime[2] = hSort.insertAllFromFile(partSize, (char *) fileName);

	/*	
	cerr << "iSort: " << endl;
	iSort.print(cerr);
	cerr << endl;
	*/

	/*
	cerr << "qSort: " << endl;
	qSort.print(cerr);
	cerr << endl;
	*/

	/*	
	cerr << "hSort: " << endl;
	hSort.print(cerr);	
	cerr << endl;
	*/
}

void measure(int partition, int totalWords, const char *fileName) {
        double times[3];
	
	times[0] = 0;
	times[1] = 0;
	times[2] = 0;

	int partSize = totalWords / 10 * partition;
        measureSort(times, partSize, fileName);
        cout << setprecision(5) << fixed;
	cout << "Partition: " << partition << " \t| InsertionSort: ";
        cout << times[0] << "\t| QuickSort: " << times[1] << "\t| HeapSort: " << times[2] << endl;
}

int main(int argc, char *argv[]) {
	const char *randFile = argc >= 2 ? argv[1] : "random.txt";
	const char *sortFile = argc >= 3 ? argv[2] : "words.txt";

	cout << "Measuring Sorting of " << randFile << endl;
	for (int ndx = 1; ndx <= 10; ndx++) {
		measure(ndx, 45293, randFile);
	}
	cout << endl;

	cout << "Measuring Sorting of " << sortFile << endl;
	for (int ndx = 1; ndx <= 10; ndx++) {
		measure(ndx, 45293, sortFile);
	}

	return 0;
}

