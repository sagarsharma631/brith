/*

AUTHOR - SAGAR SHARMA

DATE CREATED - 14/01/2020

DATE MODIFIED - 14/01/2020

Suppose an arithmetic expression is given as a binary tree. 

Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

*/


#include"stdafx.h"
#include<iostream>
// Uncomment if you want ot print some important variables.
//#define DEBUG	
using namespace std;

namespace tempUtil {
	template<typename T>
	struct node {
		T data;
		struct node<T> *left;
		struct node<T> *right;
	};
};

struct node {
	int data;
	struct node *left;
	struct node *right;
	node(int val = 0) :data(val) {
		left = NULL;
		right = NULL;
	}
};

struct node* newNode(int data)
{
	// Allocate memory for new node  
	struct node* tempNode = new struct node(data);

	return(tempNode);
}

int computeTree(struct node *root) {
	// base Condtiion
	if ((root->left == NULL) && (root->right == NULL)) {
		return root->data;
	}
	else {
		// following cases are all ASCII values
		switch (root->data) {
			// ASCII +
		case 43:
			return computeTree(root->left) + computeTree(root->right);
			break;
			// ASCII *
		case 42:
			return computeTree(root->left) * computeTree(root->right);
			break;
			// ASCII -
		case 45:
			return computeTree(root->left) - computeTree(root->right);
			break;
			// ASCII /
		case 47:
			return computeTree(root->left) / computeTree(root->right);
			break;
		default:
			return 0;
		};
	}
}

int main(int argc, char *Argv[]) {
	struct node *root = newNode('*');
	root->left = newNode('+');
	root->right = newNode('+');
	root->left->left = newNode(3);
	root->left->right = newNode(2);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	int temp = computeTree(root);
#ifdef DEBUG
	cout << temp;
#endif
	getchar();
	return 0;
}
