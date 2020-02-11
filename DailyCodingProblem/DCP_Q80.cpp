/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 11/02/2020

Question - 

Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.

*/

#include"stdafx.h"
#include<iostream>
#include<queue>

using namespace std;

template<typename T>
struct node {
	T data;
	struct node<T> *left;
	struct node<T> *right;
	node():left(NULL),right(NULL) {
		// default constructor
	}
};

// BFS on a binary tree for max Depth and also sets the maximum depth node.
template<typename T>
int BFSBinaryTree(struct node<T> *head, struct node<T> *mexDepthNode) {
	// Base condition if done through recursion.
	if (head == NULL) {
		return 0;
	}
	queue<struct node<T>*> q;
	int maxDepth = 0;	// Stores the maximum Depth of the binary tree we are traversing.
	// First push in the root node and NULL for it's the first level.
	q.push(head);
	q.push(NULL);
	struct node<T> *temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp != NULL) {
			if (temp->right != NULL) {
				q.push(temp->right);
			}

			if (temp->left != NULL) {
				q.push(temp->left);
			}
		}
		// One level is complete, identifies traversal of one level in the tree.
		else if (temp == NULL) {
			if (!q.empty()) {
				q.push(NULL);
			}
			++maxDepth;
		}
	}
	return maxDepth;
}

// BFS on a binary tree for max Depth and also sets the maximum depth node.
template<typename T>
int DFSBinaryTree(struct node<T> *head, struct node<T> *mexDepthNode) {
	// Need to implement it ASAP.
	return 0;
}

int main(int argc, char *Argv[]) {
	struct node<int> *head = NULL;
	struct node<int> *maxDepthNode = NULL;
	// returns the maxDepth and sets the maxDepthNode with deppest node.
	BFSBinaryTree<int>(head,maxDepthNode);
	return 0;
}
