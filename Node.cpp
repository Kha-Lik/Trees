//
// Created by MykolaV on 07.04.2019.
//

#include "Node.h"

::Node::Node(int val) {
	data = val;
	height = 0;
	parent = nullptr;
	left_child = nullptr;
	right_child = nullptr;
}

int ::Node::getBalance() {
	int result;
	if (left_child == nullptr)
		if (right_child == nullptr)
			result = 0;
		else
			result = -right_child->height - 1;
	else if (right_child == nullptr)
		result = left_child->height + 1;
	else
		result = left_child->height - right_child->height;
	return result;
}

int ::Node::getData() {
	return data;
}

int ::Node::getHeight() {
	return height;
}

::Node *::Node::getLeftChild() {
	return left_child;
}

::Node *::Node::getParent() {
	return parent;
}

::Node *::Node::getRightChild() {
	return right_child;
}

void ::Node::removeParent() {
	parent = nullptr;
}

::Node *::Node::setLeftChild(Node *newLeft) {
	if (newLeft != nullptr)
		newLeft->parent = this;
	left_child = newLeft;
	updateHeight();
	return left_child;
}

::Node *::Node::setRightChild(Node *newRight) {
	if (newRight != nullptr)
		newRight->parent = this;
	right_child = newRight;
	updateHeight();
	return right_child;
}

int ::Node::updateHeight() {
	if (left_child == nullptr)
		if (right_child == nullptr)
			height = 0;
		else
			height = right_child->height + 1;
	else if (right_child == nullptr)
		height = left_child->height + 1;
	else if (left_child->height > right_child->height)
		height = left_child->height + 1;
	else
		height = right_child->height + 1;
	return height;
}