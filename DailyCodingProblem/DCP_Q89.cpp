/*

AUTHOR - SAGAR SHARMA

DATE - 20/02/2020

Question - Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, left and right,

and satisfies the constraint that the key in the left child must be less than or equal to the root

and the key in the right child must be greater than or equal to the root.

ValidateBst() method written by me.

CreateBST methods taken from geeksforgeeks.com

*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 

bool validateBST(struct node *head, int min, int max){
    
    if(head == NULL){
        return true;
    }
    
    if( (head->key > max) || (head->key < min) ){
        return false;
    }
    
    return validateBST(head->left, min, head->key) && validateBST(head->right, head->key, max);
    
}
int main(int argc, char *argv[]){
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    cout<<validateBST(root, INT_MIN, INT_MAX)<<endl;
    return 0;
}

