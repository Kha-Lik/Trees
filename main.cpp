#include <iostream>
#include "Tree.h"
#include "ctime"

using namespace std;

int main() {

	Tree bst(new BinnaryTree);
	Tree avl(new AVLTree);
	Tree bTree(new BTree(3));

	for (int i = 0; i < 15; i++){
		bst.insert(rand() % 201 - 100);
		avl.insert(rand() % 201 - 100);
		bTree.insert(rand() % 201 - 100);
	}

	bst.display();
	cout << endl;
	avl.display();
	cout << endl;
	bTree.display();

	return 0;
}