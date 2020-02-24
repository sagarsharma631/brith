/*

AUTHOR - SAGAR SHARMA

DATE - 22/02/2020

Question - 
You are given a binary tree for which you have to print its "vertical order traversal". 

your task is to complete the function verticalOrder which takes one argument the root 

of the binary tree and prints the node of the binary tree in vertical order as shown below.

If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal.

*/
#include<iostream>
#include<map>
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

void printVector(const vector<struct Node *> &verticalOrderVector);
void populateVerticalOrderMap(struct Node *root, map<int,vector<struct Node*>> &verticalOrderMap, int hd);
void printVerticalOrder(const map<int,vector<struct Node *>> &verticalOrderMap);

void populateVerticalOrderMap(struct Node *root, map<int,vector<struct Node*>> &verticalOrderMap, int hd){
    if(root == NULL){
        return;
    }
    verticalOrderMap[hd].push_back(root);
    populateVerticalOrderMap(root->left,verticalOrderMap,hd - 1);
    populateVerticalOrderMap(root->right,verticalOrderMap,hd+1);
    return;
}

void printVerticalOrder(const map<int,vector<struct Node *>> &verticalOrderMap){
    if(verticalOrderMap.empty()){
        return;
    }
    map<int,vector<struct Node*>>::const_iterator iter = verticalOrderMap.begin();
    while(iter != verticalOrderMap.end()){
        cout<<"Nodes at HD level "<<iter->first<<" : ";
        printVector(iter->second);
        cout<<endl;
        ++iter;
    }
    return;
}

void printVector(const vector<struct Node *> &verticalOrderVector){
    if(verticalOrderVector.empty()){
        return;
    }
    vector<struct Node *>::const_iterator iter = verticalOrderVector.begin();
    while(iter != verticalOrderVector.end()){
        cout<<(*iter)->data<<" ";
        ++iter;
    }
    return;
}


int main(int argc, char *argv[]){
    // struct Node *root = new Node(1); 
    // root->left = new Node(2); 
    // root->right = new Node(3); 
    // root->left->left = new Node(4); 
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(8);
    // root->right->right->right = new Node(9);
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    map<int,vector<struct Node *>> verticalOrderMap;
    populateVerticalOrderMap(root,verticalOrderMap,0);
    printVerticalOrder(verticalOrderMap);
    return 0;
}
