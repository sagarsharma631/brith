/*

AUTHOR - SAGAR SHARMA

DATE CREATED - 20/04/2020

Question - Build a tree from given preorder

*/

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

TreeNode* func(const vector<int>& preorder,int& index, int rangeMin, int rangeMax) {
    //static int index = 0;
    if (index >= preorder.size()) {
        return NULL;
    }
    if (preorder[index] > rangeMin && preorder[index] < rangeMax) {
        TreeNode* head = new TreeNode(preorder[index]);
        ++index;
        head->left = func(preorder,index, rangeMin, head->val);
        if (head->left)
            head->right = func(preorder,index, head->val, rangeMax);
        else
            head->right = func(preorder,index, head->val, rangeMax);
        return head;
    }
    else {
        return NULL;
    }
}

TreeNode* buildFromPreorder(const vector<int>& preorder) {
    int startIndex = 0;
    return func(preorder,startIndex,INT_MIN,INT_MAX);
}

void doInorder(TreeNode* head) {
    if (head == NULL) {
        return;
    }
    doInorder(head->left);
    cout << head->val << endl;
    doInorder(head->right);
    return;
}

int main(int argc, char* argv[]) {
    vector<int> preorder({8,5,1,7,10,11,12});
    TreeNode* head = buildFromPreorder(preorder);
    doInorder(head);
    return 0;
}
