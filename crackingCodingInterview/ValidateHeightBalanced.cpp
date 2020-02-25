/*

AUTHOR - SAGAR SHARMA

DATE - 25/02/2020

Question - 

Validate whether binay tree is height balanced or not.

*/
#include<iostream>
#include<bits/stdc++.h>

namespace genericUtils {
	int Mod(int value) {
		return (value < 0) ? (-value) : value;
	}
	int max(int first, int second) {
		return (first <= second) ? second : first;
	}
};

struct Node
{
	int data;
	struct Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

bool isHeightBalancedUtil(struct Node *root, int &height) {
	if (root == NULL) {
		return true;
	}
	int leftHeight = 0;
	int rightheight = 0;
	bool leftTreeBalanced = isHeightBalancedUtil(root->left, leftHeight);
	bool rightTreeBalanced = isHeightBalancedUtil(root->right, rightheight);
	if (leftTreeBalanced && rightTreeBalanced && (genericUtils::Mod(leftHeight - rightheight) <= 1)) {
		height += genericUtils::max(leftHeight, rightheight) + 1;
		return true;
	}
	else {
		return false;
	}
}

bool isHeightBalanced(struct Node *root) {
	int height;
	return isHeightBalancedUtil(root, height);
}

int main()
{
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->right->left = new Node(8);
	root->right->right->right = new Node(9);
	bool temp = isHeightBalanced(root);
	getchar();
  return 0;
}
