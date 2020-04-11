/*

AUTHOR - SAGAR SHARMA

Question  - Write a program to print all the LEADERS in the linked list.
An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.


*/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct node{
    T data;
    struct node<T> *next;
    node(T value):data{value},
        next(NULL){
        // constructor
    }
    ~node(){
        delete next;
    }
};

template<typename T>
void giveLeadersUtil(struct node<T>* head,vector<T> *vec,T& max){
    if(head->next == NULL){
        max = head->data;
        vec->push_back(head->data);
    }
    else{
        giveLeadersUtil(head->next,vec,max);   
        if(head->data > max){
            max = head->data;
            vec->push_back(head->data);
        }
    }
    return;
}

template<typename T>
vector<T>* giveLeaders(struct node<T>* head){
    T max = INT_MIN;
    vector<T> *vec = new vector<T>;
    if(head == NULL){
        return NULL;
    }
    giveLeadersUtil<T>(head,vec,max);
    return vec;
}

int main(int argc, char *argv[]){
    struct node<int> *head = new struct node<int>(16);
    head->next = new struct node<int>(17);
    head->next->next = new struct node<int>(4);
    head->next->next->next = new struct node<int>(3);
    head->next->next->next->next = new struct node<int>(5);
    head->next->next->next->next->next = new struct node<int>(2);
    for(auto item : *(giveLeaders<int>(head))){
        cout<<item<<" "<<endl;
    }
    return 0;
}
