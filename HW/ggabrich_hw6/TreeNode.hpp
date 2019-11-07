// George Gabricht
//
// 56735102 - ggabrich

#ifndef TREENODE_HPP

#define TREENODE_HPP

#include <string>
#include <iostream>
using namespace std;


template
	<typename KeyType, typename ElementType>
class TreeNode {

private:
	KeyType key;
	ElementType value;
	TreeNode<KeyType, ElementType> *left, *right;

	// Worst Case - O(N) when inserted in nearly sorted order
	// Typical Case - O(Log N)
	static TreeNode * binarySearch (KeyType key, TreeNode *node) { // O(Log N)
		TreeNode * cur = node; // 1
		while (cur != nullptr) { // log N
			if (key < cur->key) { 
				if (cur->left == nullptr) {
					return cur;
				} else if (cur->left->key == key) {
					return cur;
				}
				cur = cur->left;
			} else if (key > cur->key) {
				if (cur->right == nullptr) {
					return cur;
				} else if (cur->right->key == key) {
					return cur;
				}
				cur = cur->right;
			} else {
				return cur;
			}
		}
		return cur;
	}

	// Worst Case - O(N) when inserted in nearly sorted order
	// Typical Case - O(Log N)
	static TreeNode * findPred (TreeNode *node) { // O(Log N)
		TreeNode *cur = node->left;
		while (cur->right != nullptr) {
			cur = cur->right;
		}
		return cur;
	}

	// Worst Case - O(N) when inserted in nearly sorted order
        // Typical Case - O(Log N)
	static TreeNode * findSuc (TreeNode *node) { // O(Log N)
		TreeNode *cur = node->right;
		while (cur->left != nullptr) {
			cur = cur->left;
		}
		return cur;
	}

	// Always - O(1)
	static TreeNode * newNode (KeyType k, ElementType v, TreeNode *l = nullptr, TreeNode *r = nullptr) {
		return new TreeNode<KeyType, ElementType>(k, v, l, r);
	}

public:
	TreeNode (KeyType k, ElementType v, TreeNode *l, TreeNode *r) 
	: key(k), value(v), left(l), right(r)
	{}

	ElementType & getValue() {
		return value;
	}

	KeyType & getKey() {
		return key;	
	}

	TreeNode * getLeft() {
		return left;
	}
	
	TreeNode * getRight() {
		return right;
	}

	// Worst Case - O(N) when inserted in nearly sorted order
        // Typical Case - O(Log N)
	static TreeNode * insert (KeyType k, TreeNode *node, ElementType v = ElementType()) {
		TreeNode *result = binarySearch(k, node);
		if (result == nullptr) {
			return newNode(k, v);
		} else if (k < result->key) {
			if (result->left && k == result->left->key) {
				result->left->value = v;
			} else {
				result->left = newNode(k, v);
			}
		} else if (k > result->key) {
			if (result->right && k == result->right->key) {
				result->right->value = v;
			} else {
				result->right = newNode(k, v);
			}
		} else {
			result->value = v;
		}
		return node;
	}

	// Worst Case - O(N) when inserted in nearly sorted order
        // Typical Case - O(Log N)
	static TreeNode * find (KeyType k, TreeNode *node) {
		TreeNode *result = binarySearch(k, node);
		if (result == nullptr) {
			return nullptr;
		} else if (k != result->key) {
			if (k < result->key && result->left) {
				return result;
			} else if (k > result->key && result->right) {
				return result;
			}
			return nullptr;
		}
		return result;
	}

	// O(N) - Always because traversing whole list (N items)
	static void countLengths(int * lens, TreeNode * node) {
		if (node == nullptr) {
			return;
		} else {
			countLengths(lens, node->left);
			lens[node->key.size() - 1]++;
			countLengths(lens, node->right);
		}	
	}

	// Worst Case - O(N) when inserted in nearly sorted order
        // Typical Case - O(Log N)
	static TreeNode * remove (KeyType k, TreeNode *node) {
		TreeNode *result = binarySearch(k, node), *cur; // log N
		if (result == nullptr) { // 1
			return result;
		} else if (result == node) { // 1
			if (k < result->key) { // 1
				cur = result->left;
			} else if (k > result->key) { // 1
				cur = result->right;
			} else { // 1
				cur = result;
			}
		} else if (k < result->key) { // 1
			if (result->left == nullptr) { // 1
				return node;
			}	
			cur = result->left;
		} else if (k > result->key) { // 1
			if (result->right == nullptr) { // 1
				return node;
			}
			cur = result->right;
		}
		// Awaiting answers on Piazza...
		// no children
		if (cur->left == nullptr) { // 1
			if (cur->right == nullptr) { // 1
				if (cur == result->left) { // 1
					result->left = nullptr;
				} else { // 1
					result->right = nullptr;
				}
				deleteNode(cur);
			} else { // 1
				if (cur == result->left) { // 1
					result->left = cur->right;
				} else { // 1
					result->right = cur->right;
				}
				deleteNode(cur);
			}				
		} else if (cur->right == nullptr) { // 1 - 1 child
			if (cur == result->left) { // 1
				result->left = cur->left;
			} else { // 1
				result->right = cur->left;
			}
			deleteNode(cur);
		} else { // 1 - 2 children
			TreeNode *pred = findPred(cur);
			/*if (pred->right == nullptr) {
				suc = findSuc(cur);
				cur->key = suc->key;
				cur->value = suc->value;
				remove(k, suc);
			}*/
			KeyType tempK = cur->key;
			ElementType tempV = cur->value;
			cur->key = pred->key;
			cur->value = pred->value;
			pred->key = tempK;
			pred->value = tempV;
			remove(k, cur);
		}
		return node;
	}

	// Always O(1)
	static void deleteNode (TreeNode *node) {
		delete node;
	}

	// Always O(N) because traverses whole list.
	static void deleteTree (TreeNode *node) {
		if (node != nullptr) {
			deleteTree(node->left);
			deleteTree(node->right);
			deleteNode(node);
		}
	}

};

#endif // TREENODE_HPP
