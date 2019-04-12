#pragma once
class Element {
 public:

	//int key;
	int value;
	Element *right;
	Element *left;
	Element *parent;

	Element(/*int key,*/ int value, Element *right, Element *left, Element *parent);
	~Element();
};

