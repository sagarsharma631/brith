/*
  AUTHOR - SAGAR SHARMA
  
  DATE MODIFIED (DD/MM/YYYY) - 30/12/2019

*/

#include<iostream>

using namespace std;

/* The tree creation code is not mine - 

    Copied it just from   https://www.geeksforgeeks.org/find-the-node-with-maximum-value-in-a-binary-search-tree/

*/
/* A binary tree node has data, pointer to left child   
   and a pointer to right child */
struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

// Function to create a new node 
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
        malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 

// Function to insert a new node in BST 
struct node* insert(struct node* node, int data) 
{ 
    /* 1. If the tree is empty, return a new,       
      single node */
    if (node == NULL) 
        return (newNode(data)); 
    else { 
        /* 2. Otherwise, recur down the tree */
        if (data <= node->data) 
            node->left = insert(node->left, data); 
        else
            node->right = insert(node->right, data); 
  
        /* return the (unchanged) node pointer */
        return node; 
    } 
} 

// This is my code, Finds secondlargest Integer in a BST.
bool isSecondLargestNode(struct node *head){
    if(head->right == NULL){
        if(head->left == NULL){
            return true;
        }
        else{
            cout<<head->left->data;
            return false;
        }
    }
    if(isSecondLargestNode(head->right)){
        cout<<head->data;
    }
    return false;
}

int main(int argc, char *argv[]){
    struct node* root = NULL; 
    root = insert(root, 4); 
    insert(root, 2); 
    insert(root, 1); 
    insert(root, 3); 
    insert(root, 6); 
    insert(root, 5); 
    isSecondLargestNode(root);
    return 0;
}
