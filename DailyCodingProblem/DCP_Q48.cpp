/*

AUTHOR - SAGAR SHARMA

DATE CREATED(DD/MM/YYYY) - 12/01/2020

DATE LAST MODIFIED - 12/01/2020

Question - 

Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

*/

#include<iostream>

using namespace std;

namespace util{
    enum BUILD_TYPE{
    };
};

template<typename T>
struct node{
    T m_data;
    struct node<T> *m_left;
    struct node<T> *m_right;
    node(T data){
        m_data = data;
        m_left = NULL;
        m_right = NULL;
    }
};

template<typename T>
struct node<T>* createNode(T data){
    struct node<T> *ptr = new node<T>(data);
    return ptr;
}

// search(data to be searched, inorder array, start index, end index)
template<typename T>
int search(T data, T in[], int start, int end){
    int retVal = -100;
    for(int i=start;i<=end;++i){
        if(in[i] == data){
            retVal = i;
        }
    }
    return retVal;
}

// The following method creates tree from preorder and inorder
template<typename T>
struct node<T>* createTree(char pre[], char in[], int start, int end){
    
    static int preIndex = 0;
    
    struct node<T> * ptr = createNode<T>(pre[preIndex]); 
    
    // This means that this node has no children
    if(start == end){
        return ptr;
    }
    
    int index = search<T>(pre[preIndex++],in,start,end);
    
    ptr->m_left = createTree<T>(pre,in,start,index-1);
    
    ptr->m_right = createTree<T>(pre,in,index+1,end);
    
    return ptr;
}

int main(int argc, char *argv[]){
    char inorder[] = {'d','b','e','a','f','c','g'}; 
    char preorder[] = {'a','b','d','e','c','f','g'};
    int size = sizeof(inorder)/sizeof(inorder[0]);
    createTree<char>(preorder,inorder,0,size-1);
    return 0;
}
