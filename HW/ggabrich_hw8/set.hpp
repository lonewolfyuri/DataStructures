// George Gabricht
//
// ggabrich - 56735102

#ifndef SET_HPP

#define SET_HPP

#include <iostream>
using namespace std;

struct setNode {
	setNode *parent;
	int id, rank, size;

	setNode()
	: parent(this), id(0), rank(0), size(0)
	{} 
};

struct Set {
	int cap;
	setNode *elements;

	Set(int sz) 
	: cap(sz), elements(new setNode[sz])
	{}

	// O(1)
	bool validId(int id) {
		if (id < 0 || id >= cap) { // 1
			return false; // 1
		}
		return true; // 1
	}

	// O(1)
	void makeSet(int id) {
		if (!validId(id)) { // 1
			cerr << "ID out of bounds!" << endl; // 1
			exit(-1); // 1
		}

		setNode *curNode = &elements[id]; // 1
		curNode->parent = curNode; // 1
		curNode->rank = 0; // 1
		curNode->size = 1; // 1	
	}

	// O(H) where H is height of set
	setNode * findParent(setNode *node) {
		if (node->parent != node) { // 1
			node->parent = findParent(node->parent); // H
		}
		return node->parent; // 1
	}

	// O(H) where H is height of set
	setNode * find(int id) {
		if (!validId(id)) { // 1
			cerr << "ID out of bounds!" << endl; // 1
			exit(-1); // 1
		}
		
		setNode *curNode = &elements[id]; // 1
		return findParent(curNode); // H
	}

	// O(1)
	void unionSet(int id1, int id2) {
		setNode *root1 = find(id1), *root2 = find(id2); // 1
		
		if (root1 != root2) { // 1
			if (root1->size < root2->size) { // 1
				setNode *curNode = root1; // 1
				root1 = root2; // 1
				root2 = curNode; // 1
			}
	
			root2->parent = root1; // 1
			root1->size = root1->size + root2->size; // 1
		}
				
	}
	
	~Set() {
		delete[] elements;
	}
};


#endif // SET_HPP

