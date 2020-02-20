#include "stdafx.h"
#include<iostream>
#include<queue>
#include"genericUtils.h"

struct nodeInt* newNode(int data)
{
	// Allocate memory for new node  
	struct nodeInt* node = (struct nodeInt*)malloc(sizeof(struct nodeInt));

	// Assign data to this node 
	node->data = data;

	// Initialize left and right children as NULL 
	node->left = NULL;
	node->right = NULL;
	return(node);
}

// Print left view of a binary tree.
void printLeftView(struct nodeInt *head, VIEWTYPE view = VIEWTYPE::VIEWTYPE_LEFT) {
	std::queue<struct nodeInt *> q;
	q.push(head);
	q.push(NULL);
	bool isLeftView = true;
	struct nodeInt *temp = NULL;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		// Completion of a level.
		if (temp == NULL) {
			if (!q.empty()) {
				isLeftView = true;
				q.push(NULL);
			}
		}
		else{
			if (isLeftView) {
				std::cout << temp->data << std::endl;
				isLeftView = false;
			}
			switch (view)
			{
			case VIEWTYPE_LEFT:
				if (temp->left != NULL)
					q.push(temp->left);
				if (temp->right != NULL)
					q.push(temp->right);
				break;
			case VIEWTYPE_RIGHT:
				if (temp->right != NULL)
					q.push(temp->right);
				if (temp->left != NULL)
					q.push(temp->left);
				break;
			case VIEWTYPE_BOTTOM:
				break;
			case VIEWTYPE_MAX:
				break;
			default:
				break;
			}
		}
	}
	return;
}

int main()
{
	// creating the tree.
	struct nodeInt *root = newNode(4);
	root->left = newNode(5);
	root->right = newNode(2);
	root->left->left = newNode(6);
	root->left->right = newNode(8);
	root->right->left = newNode(3);
	root->right->right = newNode(1);
	root->right->left->left = newNode(6);
	root->right->left->right = newNode(7);
	printLeftView(root,VIEWTYPE_RIGHT);
	getchar();
    return 0;
}
