#include<iostream>
#include<stack>

using namespace std;

class node  
{  
    public: 
    int data;  
    node *left, *right;  
};

node *newNode(int item)  
{  
    node *temp = new node(); 
    temp->data = item;  
    temp->left = temp->right = NULL;  
    return temp;  
}  

void printLeftViewRecur(node *head){
    
    if(head == NULL){
        return;
    }
    
    if(head->left != NULL){
        cout<<head->left->data<<" ";
    }
    
    printLeftViewRecur(head->left);
    printLeftViewRecur(head->right);
    
}

void printLeftViewIter(node *head){
    stack<node *> s;
    s.push(head);
    cout<<head->data<<" ";
    while(!s.empty()){
        node *temp = s.top();
        s.pop();
        if(temp->left != NULL){
            cout<<temp->left->data<<" ";
        }
        if(temp->right != NULL){
            s.push(temp->right);    
        }
        if(temp->left != NULL){
            s.push(temp->left);    
        }
    }
}

int main(int argc, char *argv[])  
{  
    node *root = newNode(20);  
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right->left = newNode(21);  
    root->right->right = newNode(26);  
  
    printLeftViewIter(root);  
  
    return 0;  
}  
