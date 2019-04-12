#include "Element.h"

Element::Element(int value, Element *right, Element *left, Element *parent) {
	this->value = value;
	this->right = right;
	this->left = left;
	this->parent = parent;
}

Element::~Element() {
}
