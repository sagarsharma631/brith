/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 29/01/2020 

Question - 
Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, and contain the following methods:

set(key, value): sets key to value. If there are already n items in the cache and we are adding a new item, then it should also

remove the least recently used item.

get(key): gets the value at key. If no such key exists, return null.

Each operation should run in O(1) time.

*/

#include<iostream>

using namespace std;

template<typename T>
struct node{
    T m_data;
    struct node<T> *prevNode;
    struct node<T> *nextNode;
    node(T data){
        // if data is a clas then it should have equal to operator overloaded
        m_data = data;
        prevNode = NULL;
        nextNode = NULL;
    }
};

template<typename T>
class doubleLinkedList{
    private:
    struct node<T> *m_head;
    struct node<T> *lastNode;   // caching last node which points to null.
    protected:
    public:
    doubleLinkedList{
        m_head = NULL;
        lastNode = NULL;
    }
    bool createHead(T data){
        bool retVal = false;
        if(!m_head){
            m_head = new struct Node<T>(data);
            if(m_head){
                retVal = true;
            }
        }
        else{
            return false;
        }
        return retVal;
    }
    bool addNode(T data, struct node<T> **ptr){
        bool retVal = false;
        if(m_head){
            *ptr = new
        }
        return retVal;
    }
    ~doubleLinkedList{
        delete m_head;
    }
};

int main(int argc, char *argv[]){
    return 0;
}

