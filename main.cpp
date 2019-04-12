/* The following program performs deletion on a B-Tree. It contains functions
specific for deletion along with all the other functions provided in the
previous articles on B-Trees. See https://www.geeksforgeeks.org/b-tree-set-1-introduction-2/
for previous article.

The deletion function has been compartmentalized into 8 functions for ease
of understanding and clarity

The following functions are exclusive for deletion
In class BTreeNode:
	1) remove
	2) removeFromLeaf
	3) removeFromNonLeaf
	4) getPred
	5) getSucc
	6) borrowFromPrev
	7) borrowFromNext
	8) merge
	9) findKey

In class BTree:
	1) remove

The removal of a key from a B-Tree is a fairly complicated process. The program handles
all the 6 different cases that might arise while removing a key.

Testing: The code has been tested using the B-Tree provided in the CLRS book( included
in the main function ) along with other cases.

Reference: CLRS3 - Chapter 18 - (499-502)
It is advised to read the material in CLRS before taking a look at the code. */

#include <iostream>
#include "Tree.h"
#include "ctime"

using namespace std;

int main() {

	Tree bst(new BinnaryTree);
	Tree avl(new AVLTree);
	Tree bTree(new BTree(2));

	bTree.insert(10);
	bTree.insert(-10);
	bTree.insert(0);
	bTree.insert(134);
	bTree.insert(18);
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());
	bTree.insert(rand());

	bTree.display();



	return 0;
}