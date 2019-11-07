// George Gabricht
//
// 56735102 - ggabrich


#ifndef CHAINEDHASHTABLE_HPP

#define CHAINEDHASHTABLE_HPP
#include <string>
#include <cmath>
using namespace std;

int not_found = -1;

//an abstract struct to parent your various hasher classes//
struct Hasher {
        virtual int hash(string s, int N) = 0;
};

//your first working hashing class//
struct GeneralStringHasher: Hasher {
	// Worst Case: O(1)
	// Typical Case: O(1)
        virtual int hash(string key, int N) override { 
		const unsigned shift = 6; // 1
		const unsigned zero = 0; // 1
		unsigned mask = ~zero >> (32 - shift); // 1
		unsigned result = 0; // 1
		int len = min((int)key.size(), 6); // 1
		for (int ndx = 0; ndx < len; ndx++) { // 1
			result = (result << shift) | (key[ndx] & mask); // 1
		}
		return result % N; // 1
	}
};

//A rough idea of these Hashers - //
//some modifications may be needed//
struct SumHasher : Hasher {
	// Worst Case: O(1)
	// Typical Case: O(1)
	virtual int hash(string key, int N) override {
		int result = 0, len = key.size(); // O(1)
		for (int ndx = 0; ndx < len; ndx++) // O(1)
			result += key[ndx]; // O(1)
		return abs(result) % N; // O(1)
	}
};

struct ProdHasher : Hasher {
	// Worst Case: O(1)
	// Typical Case: O(1)
	int hash(string key, int N) { 
		int result = 1, len = key.size(); // 1
		for (int ndx = 0; ndx < len; ndx++) // 1
			result *= key[ndx]; // 1
		return abs(result) % N; // 1
	}
};


class ChainedHashTable {
private:
	//data members
  	
	struct TableNode {
	private:
		string key;
		int value;
		TableNode *next;
	
	public:
		TableNode(string k, unsigned int v, TableNode *nxt = nullptr) 
		: key(k), value(v), next(nxt)
		{}
	
		// Worst Case: O(1)
		// Typical Case: O(1)
		static int * getValue(TableNode *cur) { // O(1)
			if (cur) { // 1
				return &cur->value; // 1
			} else {
				return &not_found; // 1
			}
		}
	
		static void recursiveDelete(TableNode *cur) { // O(N)
			if (cur == nullptr) {
				return;
			} else {
				recursiveDelete(cur->next);
				delete cur;
			}
		}

		static int listLength(TableNode *cur) {
			int result = 0;
			for (TableNode *ndx = cur; ndx != nullptr; ndx = ndx->next) {
				result++;
			}
			return result;	
		}

		// Worst Case: O(L)
		// Typical Case: O(L)
		static TableNode * insert(string key, unsigned int val, TableNode *cur) {
			TableNode *result = recursiveFind(key, cur); // L
			if (result == nullptr) { // 1
				cur = new TableNode(key, val, cur); // 1
			} else {
				result->value = val; // 1
			}
			return cur; // 1
		}

		// Worst Case: O(L)
		// Typical Case: O(L)
		static TableNode * recursiveFind(string key, TableNode *cur) {
			if ((cur == nullptr) || (cur->key == key)) { // 1
				return cur; // 1
			} else {
				return recursiveFind(key, cur->next); // L
			}
		}

		// Worst Case: O(L)
		// Typical Case: O(L)
		static TableNode * remove(string key, TableNode *cur) {
			TableNode *temp; // 1
			if (cur == nullptr) { // 1
				return nullptr; // 1
			} else if (cur->key == key) { // 1
				temp = cur->next; // 1
				delete cur; // 1
				return temp; // 1
			}

			// L
			for (TableNode *ndx = cur; ndx->next != nullptr; ndx = ndx->next) {
				if (ndx->next->key == key) { // 1
					temp = ndx->next; // 1
					ndx->next = temp->next; // 1
					delete temp; // 1
					return cur; // 1
				}
			}
	
			return cur; // 1
		}
	
		// Worst Case: O(L)
		// Typical Case: O(L)
		static void recursivePrintPass(TableNode * cur, ostream & out) {
			if (cur == nullptr) { // 1
				return; // 1
			} else {
				out << "Key: " << cur->key << " Val: " << cur->value << endl;// 1
				return recursivePrintPass(cur->next, out); // L
			}
		}

		// Worst Case: O(L)
		// Typical Case: O(L)
		static TableNode * copyList(TableNode *src) {
                        if (src == nullptr) { // 1
				return nullptr; // 1
			}
			TableNode *newHead; // 1
			// L
                        for (TableNode *cur = src; cur != nullptr; cur = cur->next) {
                                newHead = TableNode::insert(cur->key, cur->value, newHead); // 1
                        }   
                        return newHead; // 1
		}
	};

	int capacity, buckets, *chained_list_lengths;
	Hasher & hashr;
	TableNode ** table;	

	//hint: have a data member that is a Hasher REFERENCE
	//(make sure you understand why!!!)
public:
	//implement your constructor
       	ChainedHashTable(int capacity, Hasher & myHasher) 
	: capacity(capacity), buckets(capacity / 9), chained_list_lengths(new int[capacity / 9]), hashr(myHasher), table(new TableNode*[capacity / 9])
	{
		for (int ndx = 0; ndx < buckets; ndx++) {
			table[ndx] = nullptr;
			chained_list_lengths[ndx] = 0;
		}
	}   

     	//implement your copy constructor
	ChainedHashTable(ChainedHashTable& src)
	: capacity(src.capacity), buckets(src.buckets), chained_list_lengths(new int[src.buckets]), hashr(src.hashr), table(new TableNode*[src.buckets])
	{
		for (int ndx = 0; ndx < buckets; ndx++) {
			table[ndx] = TableNode::copyList(src.table[ndx]);
			chained_list_lengths[ndx] = src.chained_list_lengths[ndx];
		}
	}

	// Worst Case: O(1)
	// Typical Case: O(1)
	int hash(string key) {
		return hashr.hash(key, buckets); // 1
	}

	// Worst Case: O(N) When N == L
	// Typical Case: O(L)
	void insert(string key, unsigned int value = 1) {
		int ndx = hash(key); // 1
		table[ndx] = TableNode::insert(key, value, table[ndx]); // L	
		chained_list_lengths[ndx] = TableNode::listLength(table[ndx]);
	}

	// Worst Case: O(N) When N == L
	// Typical Case: O(L)
	int & operator[](string key) {
		TableNode *result = TableNode::recursiveFind(key, table[hash(key)]); // L 
		if (result == nullptr) { // 1
			if (not_found >= -1) { // 1
				not_found = -5; // 1
			}
			return not_found; // 1
		} else {
			return (int &) *TableNode::getValue(result); // 1
		}
	}

	// Worst Case: O(N) When N == L
	// Typical Case: O(L)
	int find(string key) {
		TableNode *result = TableNode::recursiveFind(key, table[hash(key)]); // L
		return *TableNode::getValue(result); // 1
	}

	// Worst Case: O(N) When N == L
	// Typical Case: O(L)
	void remove(string key) {
		int hsh = hash(key); // 1
		table[hsh] = TableNode::remove(key, table[hsh]); // L
		chained_list_lengths[hsh] = TableNode::listLength(table[hsh]);
	}
	
	// Worst Case: O(N)
	// Typical Case: O(N)
	void printTable(ostream & out) {
		for (int ndx = 0; ndx < buckets; ndx++) { // N
			TableNode::recursivePrintPass(table[ndx], out); // L
		}
	}

	int min() {
		int result = chained_list_lengths[0];
		for (int ndx = 1; ndx < buckets; ndx++) {
			if (chained_list_lengths[ndx] < result) {
				result = chained_list_lengths[ndx];
			}
		}
		return result;
	}

	int max() {
		int result = chained_list_lengths[0];
		for (int ndx = 0; ndx < buckets; ndx++) {
			if (chained_list_lengths[ndx] > result) {
				result = chained_list_lengths[ndx];
			}
		}
		return result;
	}

	double avg() {
		int sum = 0;
		for (int ndx = 0; ndx < buckets; ndx++) {
			sum += chained_list_lengths[ndx];
		}
		return ((double)sum) / buckets;
	}

	double dev() {
		double variance_sum = 0, average = avg();
		for (int ndx = 0; ndx < buckets; ndx++) {
			double temp = chained_list_lengths[ndx] - average;
			variance_sum += temp * temp;
		}
		double variance = variance_sum / buckets;
		return sqrt(variance);
	}

	//implement your destructor
	~ChainedHashTable() {
		for(int ndx = 0; ndx < buckets; ndx++) {
			TableNode::recursiveDelete(table[ndx]);
		}
		delete[] table;
		delete[] chained_list_lengths;
	}
};

#endif // CHAINEDHASHTABLE_HPP
