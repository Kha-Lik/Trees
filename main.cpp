#include <iostream>
#include "Tree.h"
#include "ctime"

using namespace std;

int main() {

	Tree bst(new BinnaryTree);
	Tree avl(new AVLTree);
	Tree bTree(new BTree(3));

	clock_t tStart, tEnd, time;
	int count = 20000;

	for (int i = 0; i < count; i++) {
		bTree.insert(rand() % 2000000 - 1000000);
	}

	tStart = clock();

	for (int i = 0; i < count; i++) {
		bTree.remove(rand() % 2000000 - 1000000);
	}
	tEnd = clock();
	time = tEnd - tStart;

	cout << time << " ms" << endl;

	return 0;
}