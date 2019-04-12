//
// Created by MykolaV on 02.04.2019.
//

#include "Tree.h"

Tree::Tree(ITree *i_tree) {
	tree = i_tree;
}

void Tree::insert(int x) {
	tree->insert(x);
}

void Tree::remove(int x) {
	tree->remove(x);
}

void Tree::display() {
	tree->display();
}

void Tree::search(int x) {
	tree->search(x);
}