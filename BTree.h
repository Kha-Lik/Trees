//
// Created by MykolaV on 12.04.2019.
//

#ifndef B_TREE__BTREE_H_
#define B_TREE__BTREE_H_

#include "BTreeNode.h"
#include "ITree.h"

class BTree : public ITree {
	BTreeNode *root;
	int t;

	BTreeNode *_search(int k);
 public:

	explicit BTree(int _t);

	void display() override;

	bool search(int k) override;

	void insert(int k);

	void remove(int k);

};

#endif //B_TREE__BTREE_H_
