#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void push (Node** head_ref, int new_data)  
{  
    /* allocate node */
    Node* new_node = new Node(); 
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  

bool isTripletPresent(struct Node *l1, struct Node *l2, struct Node *l3, int sum){
    bool retVal = false;
    queue<int> q;
    unordered_map<int,int> m;
    struct Node *l1head = l1;
    struct Node *l2head = l2;
    struct Node *l3head = l3;
    
    while(l1head != NULL){
        q.push(sum - l1head->data);
        l1head = l1head->next;
    }
    
    while(!q.empty()){
        int temp = q.front();
        while(l2head != NULL){
            m[temp-l2head->data] = l2head->data; 
            l2head = l2head->next;
        }
        l2head = l2;
        q.pop();
    }
    
    while(l3head != NULL){
        if(m.find(l3head->data) != m.end()){
            retVal = true;
            break;
        }
        l3head = l3head->next;
    }
    return retVal;
}


int main(int argc, char *argv[]){
    
	Node* headA = NULL;  
    Node* headB = NULL;  
    Node* headC = NULL;  
  
    /*create a linked list 'a' 10->15->5->20 */
    push (&headA, 20);  
    push (&headA, 4);  
    push (&headA, 15);  
    push (&headA, 10);  
  
    /*create a sorted linked list 'b' 2->4->9->10 */
    push (&headB, 10);  
    push (&headB, 9);  
    push (&headB, 4);  
    push (&headB, 2);  
  
    /*create another sorted  
    linked list 'c' 8->4->2->1 */
    push (&headC, 1);  
    push (&headC, 2);  
    push (&headC, 4);  
    push (&headC, 8);
	
	(isTripletPresent(headA, headB, headC, 25))?cout<<"triplet is present"<<endl:cout<<"triplet is not present"<<endl;
    
	return 0;
}
