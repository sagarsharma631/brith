/*

AUTHOR - SAGAR SHARMA

DATE CREATED - 21/04/2020

Question - Binary tree pruning

*/

#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* pruneTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* retVal = root;
    TreeNode* leftSub = pruneTree(root->left);
    TreeNode* rightSub = pruneTree(root->right);

    if (leftSub == NULL && rightSub == NULL) {
        root->left = NULL;
        root->right = NULL;
        if (root->val == 0) {
            retVal = NULL;
        }
    }
    else if (leftSub == NULL) {
        root->left = NULL;
    }
    else if (rightSub == NULL) {
        root->right = NULL;
    }

    return retVal;
}

int main(int argc, char* argv[]) {
	return 0;
}
