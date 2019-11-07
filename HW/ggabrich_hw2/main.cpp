// Name - George Andrew Gabricht
//
// Student ID# - 56735102

#include <fstream>
#include <iostream>
#include "Timer.h"
#include "UnorderedArrayList.hpp"
#include "UnorderedLinkedList.hpp"
using namespace std;

ostream & operator << (ostream & out, UnorderedArrayList & L)
{
	L.print(out); return out;
}

ostream & operator << (ostream & out, UnorderedLinkedList & L)
{
	L.print(out); return out;
}

void insert_all_words(string file_name, UnorderedArrayList & L) // O(N^2)
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

void find_all_words(string file_name, UnorderedArrayList & L) // O(N^2)
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

void remove_all_words(string file_name, UnorderedArrayList & L) // O(N^3)
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

void insert_all_words(string file_name, UnorderedLinkedList & L) // O(N)
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

void find_all_words(string file_name, UnorderedLinkedList & L) // O(N^2)
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

void remove_all_words(string file_name, UnorderedLinkedList & L) // O(N^2)
{
        double eTime;
	Timer t;// declare timer object

        ifstream wordFile;
        string newWord;

        wordFile.open(file_name);

        if(wordFile.is_open()) {
                t.start();// start timer

                while (getline(wordFile, newWord)) {
                        L.insert(newWord);
                }

                t.elapsedUserTime(eTime);// stop timer

                wordFile.close();
        }

        cout << eTime << endl;// report time
}

void test_UnorderedArrayList_methods(string file_name, UnorderedArrayList & L) // O(N^3)
{
	cout << "Testing UnorderedArrayList:" << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}

void test_UnorderedLinkedList_methods(string file_name, UnorderedLinkedList & L) // O(N^2)
{
	cout << "Testing UnorderedLinkedList:" << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}

int main(int argc, char * argv[]) // O(N^3)
{
	const char * input_file = argc == 2 ? argv[1] : "random.txt";
	UnorderedArrayList UAL(45500);
	test_UnorderedArrayList_methods(input_file, UAL);
	UnorderedLinkedList ULL;
	test_UnorderedLinkedList_methods(input_file, ULL);
	return 0;
}

