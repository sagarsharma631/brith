/*

AUTHOR - SAGAR SHARMA

DATE - 22/02/2020

Question - 

Write a function to connect all the adjacent nodes at the same level in a binary tree. 

Structure of the given Binary Tree node is like following.

struct node{ 
  int data; 
  struct node* left; 
  struct node* right; 
  struct node* nextRight;   
} 

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

*/
#include<iostream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *nextRight;
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
        this->nextRight = NULL;
    }
};

// The following method uses Level Order Traversal for connecting right nodes.
void connectNodesAtSameLevel(struct Node *root){
    if(root == NULL){
        return;
    }
    queue<struct Node *> travQ;
    travQ.push(root);
    travQ.push(NULL);
    struct Node *temp;
    while(!travQ.empty()){
        temp = travQ.front();
        travQ.pop();
        if(temp == NULL){
            if(!travQ.empty()){
                travQ.push(NULL);
            }
        }
        else{
            temp->nextRight = travQ.front();
            if(temp->left != NULL){
                travQ.push(temp->left);
            }
            if(temp->right != NULL){
                travQ.push(temp->right);
            }
        }
    }
    return;
}

int getSiblingNode(const struct Node *head){
    int retVal;
    if(head == NULL){
        retVal = INT_MIN;
    }
    else{
        if(head->nextRight == NULL){
            retVal = INT_MIN;
        }
        else{
            retVal = head->nextRight->data;
        }
    }
    return retVal;
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
    connectNodesAtSameLevel(root);
    cout<<getSiblingNode(root->right->left)<<endl;
    return 0;
}
