/*

AUTHOR - SAGAR SHARMA

DATE - 25/02/2020

Question - 

Given a binary tree, find height of it. 

*/
#include<iostream>
#include<queue>
#include<bits/stdc++.h>
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

// Used BFS for calculating height
void calcHeightTree(struct Node *root, int &height){
    if(root == NULL){
        height = INT_MIN;
        return;
    }
    height = 0;
    queue<struct Node*> q;
    q.push(root);
    q.push(NULL);
    struct Node *temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp == NULL){
            ++height;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
    return;
}

int main(int argc, char *argv[]){
    struct Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    //root->right->left = new Node(6);
    //root->right->right = new Node(7);
    //root->right->right->left = new Node(8);
    //root->right->right->right = new Node(9);
    int height = 0;
    calcHeightTree(NULL,height);
    cout<<height;
    return 0;
}
