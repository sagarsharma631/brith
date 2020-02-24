/*

AUTHOR - SAGAR SHARMA

DATE - 22/02/2020

Question - 

Write a function to print spiral order traversal of a tree

*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

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

enum TRAV_TYPE{
    TRAV_TYPE_INVALID = 0,
    TRAV_TYPE_LEFT_RIGHT,
    TRAV_TYPE_RIGHT_LEFT,
    TRAV_TYPE_MAX,
};

void populateSpiral(vector<struct Node *> &spiralVec);
void printSpiral(const vector<struct Node*> &spiralVec);

void populateSpiral(struct Node *root, vector<struct Node *> &spiralVec){
    TRAV_TYPE toggle = TRAV_TYPE_RIGHT_LEFT;
    stack<struct Node *> st_left_right;
    stack<struct Node *> st_right_left;
    st_left_right.push(root);
    struct Node *temp; 
    while(1){
        if(st_left_right.empty() && st_right_left.empty()){
            break;
        }
        switch(toggle){
            case TRAV_TYPE::TRAV_TYPE_LEFT_RIGHT:
            while(!st_right_left.empty()){
                temp = st_right_left.top();
                st_right_left.pop();
                if(temp->left != NULL){
                    st_left_right.push(temp->left);
                }
                if(temp->right != NULL){
                    st_left_right.push(temp->right);
                }
                spiralVec.push_back(temp);
            }
            toggle = TRAV_TYPE_RIGHT_LEFT;
            break;
            case TRAV_TYPE::TRAV_TYPE_RIGHT_LEFT:
            while(!st_left_right.empty()){
                temp = st_left_right.top();
                st_left_right.pop();
                if(temp->right != NULL){
                    st_right_left.push(temp->right);
                }
                if(temp->left != NULL){
                    st_right_left.push(temp->left);
                }                
                spiralVec.push_back(temp);
            }
            toggle = TRAV_TYPE_LEFT_RIGHT;
            break;
        }
    }
    return;
}

void printSpiral(const vector<struct Node*> &spiralVec){
    vector<struct Node*>::const_iterator iter = spiralVec.begin();
    while(iter != spiralVec.end()){
        cout<<(*iter)->data<<" ";
        ++iter;
    }
    cout<<endl;
    return;
} 

int main(int argc, char *argv[]){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    vector<struct Node*> vecSpiral;
    populateSpiral(root,vecSpiral);
    printSpiral(vecSpiral);
    return 0;
}
