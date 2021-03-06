//
// Created by MykolaV on 12.04.2019.
//

#ifndef B_TREE__BTREENODE_H_
#define B_TREE__BTREENODE_H_

// A BTree node
class BTreeNode {
	int *keys;
	int t;
	BTreeNode **C;
	int n;
	bool leaf;

 public:

	BTreeNode(int _t, bool _leaf);

	void traverse();

	BTreeNode *search(int k);

	int findKey(int k);

	void insertNonFull(int k);

	void splitChild(int i, BTreeNode *y);

	void remove(int k);

	void removeFromLeaf(int idx);

	void removeFromNonLeaf(int idx);

	int getPred(int idx);

	int getSucc(int idx);

	void fill(int idx);

	void borrowFromPrev(int idx);

	void borrowFromNext(int idx);

	void merge(int idx);

	friend class BTree;
};

#endif //B_TREE__BTREENODE_H_
