//
// Created by MykolaV on 12.04.2019.
//

#include <iostream>
#include "BTree.h"

using namespace std;

void BTree::insert(int k) {

	if (root == nullptr) {

		root = new BTreeNode(t, true);
		root->keys[0] = k;
		root->n = 1;
	} else {

		if (root->n == 2 * t - 1) {

			BTreeNode *s = new BTreeNode(t, false);

			s->C[0] = root;

			s->splitChild(0, root);

			int i = 0;
			if (s->keys[0] < k)
				i++;
			s->C[i]->insertNonFull(k);

			root = s;
		} else
			root->insertNonFull(k);
	}
}

void BTree::remove(int k) {
	if (!root) {
		cout << "The tree is empty\n";
		return;
	}

	root->remove(k);

	if (root->n == 0) {
		BTreeNode *tmp = root;
		if (root->leaf)
			root = nullptr;
		else
			root = root->C[0];

		delete tmp;
	}
	return;
}

BTreeNode *BTree::_search(int k) {
	return (root == nullptr) ? nullptr : root->search(k);
}

BTree::BTree(int _t) {
	root = nullptr;
	t = _t;
}

void BTree::display() {
	if (root != nullptr) root->traverse();
}

bool BTree::search(int k) {
	return _search(k) != nullptr;
}
