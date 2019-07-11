#include<iostream>
#include<queue>

using namespace std;

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
    node *nextRight;  
      
    /* Constructor that allocates a new node with the  
    given data and NULL left and right pointers. */
    node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
        this->nextRight = NULL; 
    } 
};

void connectNodes(node *head){
    queue<node*> q;
    q.push(head->left);
    q.push(head->right);
    q.push(NULL);
    
    while(!q.empty()){
        while(q.front() != NULL){
            node *temp = q.front();
            q.pop();
            (temp)?temp->nextRight = q.front():temp->nextRight = NULL;
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);   
            }
        }
        q.pop();
        if(!q.empty()){
            q.push(NULL);   
        }
    }
}

int main(int argc, char *argv[]){
    node *root = new node(8);  
    root->left = new node(3);  
    root->right = new node(10);  
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->left->right->left = new node(4);
    root->left->right->right = new node(7);
    root->right->right = new node(14);
    root->right->right->left = new node(13);
    connectNodes(root);
    return 0;
}
