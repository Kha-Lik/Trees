//
// Created by MykolaV on 07.04.2019.
//

#include <iostream>
#include <iomanip>

#include "AVLTree.h"

AVLTree::AVLTree() {
	root = nullptr;
}

AVLTree::AVLTree(int val) {
	root = new Node(val);
}

void AVLTree::balanceAtNode(Node *n) {
	int bal = n->getBalance();
	if (bal > 1) {
		if (n->getLeftChild()->getBalance() < 0)
			rotateLeft(n->getLeftChild());
		rotateRight(n);
	} else if (bal < -1) {
		if (n->getRightChild()->getBalance() > 0)
			rotateRight(n->getRightChild());
		rotateLeft(n);
	}
}

Node *AVLTree::findNode(int val) {
	Node *temp = root;
	while (temp != nullptr) {
		if (val == temp->getData())
			break;
		else if (val < temp->getData())
			temp = temp->getLeftChild();
		else
			temp = temp->getRightChild();
	}
	return temp;
}

int AVLTree::getHeight() {
	return root->getHeight();
}

void AVLTree::insert(int val) {
	if (root == nullptr)
		root = new Node(val);
	else {
		Node *added_node = nullptr;
		Node *temp = root;
		while (temp != nullptr && added_node == nullptr) {
			if (val < temp->getData()) {
				if (temp->getLeftChild() == nullptr) {
					added_node = temp->setLeftChild(
						new Node(val));
				} else
					temp = temp->getLeftChild();
			} else if (val > temp->getData()) {
				if (temp->getRightChild() == nullptr) {
					added_node = temp->setRightChild(
						new Node(val));
				} else
					temp = temp->getRightChild();
			} else
				return;
		}
		temp = added_node;
		while (temp != nullptr) {
			temp->updateHeight();
			balanceAtNode(temp);
			temp = temp->getParent();
		}
	}
}

void AVLTree::display() {
	if (root == nullptr)
		std::cout << "Tree is empty!" <<
				  std::endl;
	else if (root->getHeight() > 4)
		std::cout << "Not currently supported!" <<
				  std::endl;
	else {
		int max = root->getHeight();
		for (int depth = 0; depth <= max; depth++) {
			printSubtree(root, depth, max - depth + 1, true);
			std::cout << std::endl;
		}
	}
}

void AVLTree::printSubtree(Node *subtree, int depth, int level, bool first) {
	if (depth > 0) {
		if (subtree == nullptr) {
			printSubtree(subtree, depth - 1, level, first);
			printSubtree(subtree, depth - 1, level, false);
		} else {
			printSubtree(subtree->getLeftChild(), depth - 1,
						 level, first);
			printSubtree(subtree->getRightChild(), depth - 1,
						 level, false);
		}
	} else if (subtree == nullptr)
		std::cout << std::setw((first) ?
							   spacing(level) / 2 : spacing(level)) << "-";
	else
		std::cout << std::setw((first) ?
							   spacing(level) / 2 : spacing(level)) <<
				  subtree->getData();
}

void AVLTree::remove(int val) {
	Node *toBeRemoved = findNode(val);
	if (toBeRemoved == nullptr)
		return;
	enum { left, right } side;
	Node *p = toBeRemoved->getParent();
	if (p != nullptr &&
		p->getLeftChild() == toBeRemoved)
		side = left;
	else
		side = right;
	if (toBeRemoved->getLeftChild() == nullptr)
		if (toBeRemoved->getRightChild() == nullptr) {
			if (p == nullptr) {
				setRoot(nullptr);
				delete toBeRemoved;
			} else {
				if (side == left)
					p->setLeftChild(nullptr);
				else
					p->setRightChild(nullptr);
				delete toBeRemoved;
				p->updateHeight();
				balanceAtNode(p);
			}
		} else {
			if (p == nullptr) {
				setRoot(toBeRemoved->getRightChild());
				delete toBeRemoved;
			} else {
				if (side == left)
					p->setLeftChild(toBeRemoved->
						getRightChild());
				else
					p->setRightChild(toBeRemoved->
						getRightChild());
				delete toBeRemoved;
				p->updateHeight();
				balanceAtNode(p);
			}
		}
	else if (toBeRemoved->getRightChild() == nullptr) {
		if (p == nullptr) {
			setRoot(toBeRemoved->getLeftChild());
			delete toBeRemoved;
		} else {
			if (side == left)
				p->setLeftChild(toBeRemoved->
					getLeftChild());
			else
				p->setRightChild(toBeRemoved->
					getLeftChild());
			delete toBeRemoved;
			p->updateHeight();
			balanceAtNode(p);
		}
	} else {
		Node *replacement;
		Node *replacement_parent;
		Node *temp_node;
		int bal = toBeRemoved->getBalance();
		if (bal > 0) {
			if (toBeRemoved->getLeftChild()->
				getRightChild() == nullptr) {
				replacement = toBeRemoved->getLeftChild();
				replacement->setRightChild(
					toBeRemoved->getRightChild());
				temp_node = replacement;
			} else {
				replacement = toBeRemoved->
					getLeftChild()->getRightChild();
				while (replacement->getRightChild() !=
					nullptr)
					replacement = replacement->getRightChild();
				replacement_parent = replacement->getParent();
				replacement_parent->setRightChild(
					replacement->getLeftChild());
				temp_node = replacement_parent;
				replacement->setLeftChild(
					toBeRemoved->getLeftChild());
				replacement->setRightChild(
					toBeRemoved->getRightChild());
			}
		} else if (toBeRemoved->getRightChild()->
			getLeftChild() == nullptr) {
			replacement = toBeRemoved->getRightChild();
			replacement->setLeftChild(
				toBeRemoved->getLeftChild());
			temp_node = replacement;
		} else {
			replacement = toBeRemoved->
				getRightChild()->getLeftChild();
			while (replacement->getLeftChild() !=
				nullptr)
				replacement = replacement->getLeftChild();
			replacement_parent = replacement->getParent();
			replacement_parent->setLeftChild(
				replacement->getRightChild());
			temp_node = replacement_parent;
			replacement->setLeftChild(
				toBeRemoved->getLeftChild());
			replacement->setRightChild(
				toBeRemoved->getRightChild());
		}
		if (p == nullptr)
			setRoot(replacement);
		else if (side == left)
			p->setLeftChild(replacement);
		else
			p->setRightChild(replacement);
		delete toBeRemoved;
		balanceAtNode(temp_node);
	}
}

void AVLTree::rotateLeft(Node *n) {
	enum { left, right } side;
	Node *p = n->getParent();
	if (p != nullptr && p->getLeftChild() == n)
		side = left;
	else
		side = right;
	Node *temp = n->getRightChild();
	n->setRightChild(temp->getLeftChild());
	temp->setLeftChild(n);
	if (p == nullptr)
		setRoot(temp);
	else if (side == left)
		p->setLeftChild(temp);
	else
		p->setRightChild(temp);
}

void AVLTree::rotateRight(Node *n) {
	enum { left, right } side;
	Node *p = n->getParent();
	if (p != nullptr && p->getLeftChild() == n)
		side = left;
	else
		side = right;
	Node *temp = n->getLeftChild();
	n->setLeftChild(temp->getRightChild());
	temp->setRightChild(n);
	if (p == nullptr)
		setRoot(temp);
	else if (side == left)
		p->setLeftChild(temp);
	else
		p->setRightChild(temp);
}

void AVLTree::setRoot(Node *n) {
	root = n;
	if (root != nullptr)
		root->removeParent();
}

bool AVLTree::search(int val) {
	return findNode(val)!= nullptr;
}

int AVLTree::spacing(int level) {
	int result = 2;
	for (int i = 0; i < level; i++)
		result += result;
	return result;
}