//
// Created by MykolaV on 07.04.2019.
//

#ifndef AVL_TREE_V2__AVLTREE_H_
#define AVL_TREE_V2__AVLTREE_H_

#include "ITree.h"
#include "Node.h"

class AVLTree : public ITree {
 private:
	Node *root;
	void balanceAtNode(Node *n);
	Node *findNode(int val);
	void printSubtree(Node *subtree, int depth, int offset, bool first);
	void rotateLeft(Node *n);
	void rotateRight(Node *n);
	void setRoot(Node *n);
	int spacing(int offset);
	int getHeight();
 public:
	AVLTree();
	AVLTree(int val);
	bool search(int val);
	void insert(int val);
	void display();
	void remove(int val);
};

#endif //AVL_TREE_V2__AVLTREE_H_
