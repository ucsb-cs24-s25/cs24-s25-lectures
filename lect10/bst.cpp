// BST.cpp
// Modified version of lab02 starter code for demo purposes

#include <iostream>
#include <queue>
#include "bst.h"
using std::cout;

// constructor sets up empty tree

BST::BST() : root(nullptr) { }

// destructor deletes all nodes

BST::~BST() {
    clear(root);
}


// recursive helper for destructor
void BST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate

bool BST::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)

bool BST::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

// print tree data pre-order
void BST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void BST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}


void BST::printBreadthFirst(vector<int>& v) const{
	queue<Node* > q;
	q.push(root); // root
	while (!q.empty())
	{
		Node* fr = q.front();
		v.push_back(fr->info);
		if(fr->left) q.push(fr->left);
		if(fr->right) q.push(fr->right);
		q.pop();
	}

}


