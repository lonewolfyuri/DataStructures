// George Gabricht
//
// 56735102 - ggabrich

#ifndef BINARYSEARCHTREE_HPP

#define BINARYSEARCHTREE_HPP

#include <stack>
#include "TreeNode.hpp"
using namespace std;

template
	<typename KeyType, typename ElementType>
class BinarySearchTree {

private:
	TreeNode <KeyType, ElementType> *root;

public:
	BinarySearchTree (TreeNode<KeyType, ElementType> *rt = nullptr) 
	: root(rt)
	{}

	// Worst Case - O(N) when inserted in nearly sorted order
        // Typical Case - O(Log N)
	void insert (KeyType key, ElementType value) {
		root = TreeNode<KeyType, ElementType>::insert(key, root, value);
	}

	// Worst Case - O(N) when inserted in nearly sorted order
        // Typical Case - O(Log N)
	ElementType find (KeyType key) {
		TreeNode <KeyType, ElementType> *result = TreeNode <KeyType, ElementType>::find(key, root);
		ElementType val = result->getValue();
		return val;
	}

	// Worst Case - O(N) when inserted in nearly sorted order
        // Typical Case - O(Log N)
	ElementType & operator[] (KeyType key) {
		TreeNode <KeyType, ElementType> *result = TreeNode<KeyType, ElementType>::find(key, root); // log N
		if (result == nullptr) {
			root = TreeNode <KeyType, ElementType>::insert(key, root);
			result = root;
		} else if (key < result->getKey()) {
			result = result->getLeft();
		} else if (key > result->getKey()) {
			result = result->getRight();
		}

		if (result == nullptr) { // 1
			try {
				root = TreeNode<KeyType, ElementType>::insert(key, root); // log N
				return TreeNode<KeyType,ElementType>::find(key, root)->getValue(); // log N
			} catch (...) {
				cout << "Could not insert on [] operator" << endl;
				TreeNode<KeyType, ElementType>::deleteTree(root);
				exit(-1);
			}
		}
		return result->getValue();
	}

	// Worst Case - O(N) when inserted in nearly sorted order
        // Typical Case - O(Log N)
	void remove (KeyType key) {
		TreeNode<KeyType, ElementType>::remove(key, root);
	}	
	
	// O(N) - because traverses whole tree
        void countLengths() {
                int lens[100];
                for (int ndx = 0; ndx < 100; ndx++) {
                        lens[ndx] = 0;
                }
                TreeNode<KeyType, ElementType>::countLengths(lens, root);
                for (int ndx = 0; ndx < 100; ndx++) {
                        if (lens[ndx] > 0) {
                                // handle print output
                                cout << "\tlength " << ndx + 1 << ": ";
                                cout << lens[ndx] << " words" << endl;
                        }
                }
        }

	// O(N) - because traverses whole tree
	~BinarySearchTree() {
		if (root != nullptr) {
			TreeNode<KeyType, ElementType>::deleteTree(root);
		}
	}

};

#endif // BINARYSEARCHTREE_HPP

