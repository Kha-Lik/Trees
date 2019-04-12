//
// Created by MykolaV on 12.04.2019.
//

#ifndef B_TREE__BTREE_H_
#define B_TREE__BTREE_H_

#include "BTreeNode.h"
#include "ITree.h"

class BTree : public ITree
{
	BTreeNode *root; // Pointer to root node
	int t; // Minimum degree
	// function to search a key in this tree
	BTreeNode* _search(int k)
	{
		return (root == nullptr)? nullptr : root->search(k);
	}
 public:

	// Constructor (Initializes tree as empty)
	BTree(int _t)
	{
		root = nullptr;
		t = _t;
	}

	void display() override
	{
		if (root != nullptr) root->traverse();
	}

	bool search (int k) override{
		return _search(k) != nullptr;
	}


	// The main function that inserts a new key in this B-Tree
	void insert(int k);

	// The main function that removes a new key in thie B-Tree
	void remove(int k);

};


#endif //B_TREE__BTREE_H_
