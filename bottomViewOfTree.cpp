/*

<!------------------------------------------------------------------------------------------------------------------------

Given a Binary Tree, we need to print the bottom view from left to right.
A node x is there in output if x is the bottommost node at its horizontal distance.
Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, 
and that of right child is horizontal distance of x plus 1

---------------------------------------------------------------------------------------------------------------------------!>

*/

#include<iostream>
#include<queue>
#include<map>
using namespace std;

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right; 
    int hd; // this is used for storing the horizontal distance
    node(){
        left = NULL;
        right = NULL;
        hd = 0;
    }
};  

node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
} 

void printBottomView(node *src){
    if(src == NULL){
        return;
    }
    queue<node*> q;
    map<int,int> m;
    q.push(src);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        m[temp->hd] = temp->data;
        if(temp->left != NULL){
            q.push(temp->left);
            temp->left->hd = (temp->hd) - 1;
        }
        if(temp->right != NULL){
            q.push(temp->right);
            temp->left->hd = (temp->hd) + 1;
        }
    }

    for (auto i = m.begin(); i != m.end(); ++i) {
        cout << i->first << " ";
    } 
}

int main(int argc, char *argv[]){
    node *root = newNode(11);  
  
    root->left = newNode(8);  
    root->left->left = newNode(5);  
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(6);
    root->right = newNode(10);  
    root->right->left = newNode(9);
    root->right->right = newNode(12);
    printBottomView(root);    
    return 0; 
}
