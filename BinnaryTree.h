#pragma once
#include "Element.h"
#include "ITree.h"

class BinnaryTree : public ITree {
 private:
	Element *root;
	Element *temp;
	Element *node;
	Element *add(/*int key,*/ int value, Element *root);
	Element *minValueNode(Element *node);
	Element *remove(int key, Element *root);
	void print(Element *root);
	Element *search(int key, Element *root);

 public:
	void insert(/*int key,*/ int value);
	void remove(int key);
	bool search(int key);
	void display();

	BinnaryTree();
	~BinnaryTree();
};

