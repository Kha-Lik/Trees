//
// Created by MykolaV on 02.04.2019.
//

#ifndef AVL_TREE_V2__TREE_H_
#define AVL_TREE_V2__TREE_H_

#include "ITree.h"
#include "AVLTree.h"
#include "BinnaryTree.h"
#include "BTree.h"

class Tree {
 private:
	ITree *tree;
 public:
	explicit Tree(ITree *i_tree);
	void insert(int x);
	void remove(int x);
	void search(int x);
	void display();
};

#endif //AVL_TREE_V2__TREE_H_
