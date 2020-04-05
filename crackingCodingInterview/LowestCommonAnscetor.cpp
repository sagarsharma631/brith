/*

NAME - SAGAR SHARMA

TOPIC - Lowest Common Anscestor of a binary tree(NOT A BST). Iterative Method my own method

*/

#include<iostream>
#define DEBUG

using namespace std;

// Node of a BST.
struct node {
	int data;
	int rank;
	int numRightChildren;	// total number of right children of the node
	int numLeftChildren;	// total number of left children of the node
	struct node* left;
	struct node* right;
	node(int temp) :data(temp),
		left(NULL),
		right(NULL) {
		// Just Initialized the important variables.
	}
};

// Finds lowest Common Anscestor among two nodes in a binary tree.
struct node* LCAUtil(struct node* root, int x, int y) {
	std::vector<struct node*> vec;
	vec.push_back(root);
	int xIndex = INT_MIN;
	int yIndex = INT_MIN;
	int index = 0;
	while (index < static_cast<int>(vec.size())) {
		if (vec[index]) {
			if (xIndex == INT_MIN && vec[index]->data == x)
				xIndex = index;
			if (yIndex == INT_MIN && vec[index]->data == y)
				yIndex = index;
			vec.push_back((vec[index]->left) ? vec[index]->left : NULL);
			vec.push_back((vec[index]->right) ? vec[index]->right : NULL);
		}
		++index;
	}
	if (xIndex == INT_MIN || yIndex == INT_MIN || xIndex == yIndex) {
		// Both the values were not present in the tree, Hence cannot find the LCA
		return NULL;
	}
	else {
		int maxIndex = genericUtils::max<int>(xIndex, yIndex);
		int minIndex = xIndex + yIndex - maxIndex;
		while (1) {
			if (maxIndex == minIndex) {
				return vec[minIndex];
			}
			else if (minIndex == 0 || maxIndex == 0) {
				return vec[0];
			}
			else if (minIndex < maxIndex) {
				maxIndex = (maxIndex - 1) / 2;
			}
			else if (minIndex > maxIndex) {
				minIndex = (minIndex - 1) / 2;
			}
		}
	}

	return NULL;
}

struct node* LCA(int x,int y) {
	struct node* root = new struct node(1);
	root->left = new struct node(2);
	root->right = new struct node(3);
	root->left->left = new struct node(4);
	root->left->right = new struct node(5);
	root->left->right->left = new struct node(8);
	root->left->right->right = new struct node(9);
	root->right->left = new struct node(6);
	root->right->right = new struct node(7);
	return LCAUtil(root, x, y);
}

int main(int argc, char *argv[]){
  const struct node* lca = LCA(4,9);
#ifdef DEBUG
  cout<<"Lowest Common Anscetor is "<<lca->data<<endl;
#endif
  return 0;
}
