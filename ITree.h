//
// Created by MykolaV on 02.04.2019.
//

#ifndef AVL_TREE_V2__ITREE_H_
#define AVL_TREE_V2__ITREE_H_

class ITree {
 public:
	virtual void insert(int x) = 0;
	virtual void remove(int x) = 0;
	virtual bool search(int x) = 0;
	virtual void display() = 0;
};

#endif //AVL_TREE_V2__ITREE_H_
