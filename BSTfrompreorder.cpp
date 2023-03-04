#include<iostream>
#include<vector>

using namespace std;

class Solution {
    TreeNode* bstFromPreorder(vector<int>& preorder, int& currIndex, int min, int max){
        
        if(currIndex >= preorder.size()){
            return nullptr;
        }
        
        if(preorder[currIndex] < min || preorder[currIndex] > max){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[currIndex]);
        currIndex += 1;
        root->left = bstFromPreorder(preorder, currIndex, min, root->val);
        root->right = bstFromPreorder(preorder, currIndex, root->val, max);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int currIndex = 0;
        return bstFromPreorder(preorder, currIndex, INT_MIN, INT_MAX);
    }
};

int main(int argc, char *argv[]){
  vector<int> preorder({8,5,1,7,10,12});
  Solution obj;
  obj.bstFromPreorder(preorder);
  return
}
