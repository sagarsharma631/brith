/*

AUTHOR - SAGAR SHARMA

DATE - 17-02-2020

Question - 
Invert a binary tree.

Binary tree code creation taken from 
https://www.geeksforgeeks.org/

Method written by me - void invertTree(struct node *head) && void printInorder(struct node* head)

*/
#include<iostream>

using namespace std;

struct node  
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
/* newNode() allocates a new node with the given data and NULL left and  
   right pointers. */
struct node* newNode(int data) 
{ 
  // Allocate memory for new node  
  struct node* node = (struct node*)malloc(sizeof(struct node)); 
  
  // Assign data to this node 
  node->data = data; 
  
  // Initialize left and right children as NULL 
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 

void swapNode(struct node *head){
    struct node *temp;
    temp = head->left;
    head->left = head->right;
    head->right = temp;
    return;
}

// Invert a binary tree
void invertTree(struct node *head){
    // Base condition
    if(head == NULL || (head->left == NULL && head->right == NULL)){
        return;
    }
    // Go down and invert the left sub tree.
    invertTree(head->left);
    // Go down and invert the right sub tree.
    invertTree(head->right);
    // Now swap the node current node itself.
    swapNode(head);
    return;
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* head){ 
    if (head == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(head->left); 
  
    /* then print the data of node */
    cout << head->data << " "; 
  
    /* now recur on right child */
    printInorder(head->right); 
} 

int main(int argc, char *argv[]){
    // creating the tree.
    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3);
    root->left->left  = newNode(4); 
    // print In order.
    printInorder(root);
    invertTree(root);
    // inorder after inversion.
    cout<<endl;
    printInorder(root);
    return 0;
}
