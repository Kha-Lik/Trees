#include "BinnaryTree.h"
#include "iostream"

BinnaryTree::BinnaryTree() {
	this->root = nullptr;
}

Element *BinnaryTree::add(/*int key,*/ int value, Element *root) {
	if (root == nullptr) {
		root = new Element(/*key,*/ value, nullptr, nullptr, nullptr);
	} else {
		if (value < root->value) {
			if (root->left == nullptr) {
				root->left = new Element(value, nullptr, nullptr, root);
			} else {
//				this->root = this->root->left;
				add(value, root->left);
			}
		} else if (value > this->root->value) {
			if (root->right == nullptr) {
				root->right = new Element(value, nullptr, nullptr, root);
			} else {
//				this->root = this->root->right;
				add(value, root->right);
			}
		} else if (value == root->value) {
			root->value = value;
		}
	}
	return root;
}

/*Element *BinnaryTree::remove(int value, Element *root) {
	if (root == nullptr) {
		return nullptr;
	} else {
		if (value > root->value) {
//			this->root = this->root->right;
			remove(value, root->right);
		} else if (value < root->value) {
//			this->root = this->root->left;
			remove(value, root->left);
		} else if (value == root->value) {
			if (root->left == nullptr && root->right == nullptr) {
				root = nullptr;
				if (root == root->parent->left) {
					root->parent->left = nullptr;
				} else {
					root->parent->right = nullptr;
				}
			} else if (root->left == nullptr) {
				root->right->parent = root->parent;
				root = root->right;
			} else if (root->right == nullptr) {
				root->left->parent = root->parent;
				root = root->left;
			} else {
				if (root->right->left == nullptr) {
					root->left->parent = root->right;
					root->right->left = root->left;
					root->right->parent = root->parent;
					root = root->right;
				} else {
					temp = root;
					while (temp->left != nullptr) {
						temp = temp->left;
					}
					temp->parent = root->parent;
					temp->right = root->right;
					temp->left = root->left;
//					this->root = temp;
					remove(temp->value, temp);
				}
			}
		}
	}
	return root;
}*/

Element *minValueNode(Element *node) {
	Element *current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != nullptr)
		current = current->left;

	return current;
}

Element *removeInn(Element *root, int key) {
	// base case
	if (root == nullptr) return root;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->value)
		root->left = removeInn(root->left, key);

		// If the key to be deleted is greater than the root's key,
		// then it lies in right subtree
	else if (key > root->value)
		root->right = removeInn(root->right, key);

		// if key is same as root's key, then This is the node
		// to be deleted
	else {
		// node with only one child or no child
		if (root->left == nullptr) {
			Element *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			Element *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Element *temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->value = temp->value;

		// Delete the inorder successor
		root->right = removeInn(root->right, temp->value);
	}
	return root;
}

Element *BinnaryTree::search(int value, Element *root) {
	//std::cout << this->root->value << std::endl;
	if (root == nullptr) {
		//std::cout << "1";
		//std::cout << "No such element in the tree\n";
		return nullptr;
	} else {
		if (value == root->value) {
			//std::cout << "Element is in the tree\n";
			return root;
		} else {
			if (value < root->value) {
				search(value, root->left);
			} else {
				search(value, root->right);
			}
		}
	}
}

void BinnaryTree::print(Element *root) {
	//node = _search(key);
	if (root == nullptr) {
		return;
	}
	print(root->left);
	std::cout << root->value << "->";
	print(root->right);
}

void BinnaryTree::display() {
	print(root);
	std::cout << std::endl;
}

void BinnaryTree::insert(int value) {
	root = add(value, root);
}

void BinnaryTree::remove(int value) {
	root = removeInn(root, value);
}

bool BinnaryTree::search(int key) {
	root = search(key, root);
	return root ? true : false;
}

BinnaryTree::~BinnaryTree() {
}
