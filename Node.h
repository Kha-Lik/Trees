//
// Created by MykolaV on 07.04.2019.
//

#ifndef AVL_TREE_V2__NODE_H_
#define AVL_TREE_V2__NODE_H_

class Node {
 private:
	int data;
	int height;
	Node *left_child;
	Node *parent;
	Node *right_child;
 public:
	Node(int val);
	int getBalance();
	int getData();
	int getHeight();
	Node *getLeftChild();
	Node *getParent();
	Node *getRightChild();
	void removeParent();
	Node *setLeftChild(Node *newLeft);
	Node *setRightChild(Node *newRight);
	int updateHeight();
};

#endif //AVL_TREE_V2__NODE_H_
