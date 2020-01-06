/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 05/01/2020

DATE LAST MODIFIED - 05/01/2020

Implement a stack that has the following methods:

push(val), which pushes an element onto the stack

pop(), which pops off and returns the topmost element of the stack. 

max(), which returns the maximum value in the stack currently.

If there are no elements in the stack, then it should throw an error or return null.

Each method should run in constant time.

*/

#include<iostream>
#include<stack>
//#define DEBUG 

using namespace std;

// This class is a wrapper on normal STL - stack, This also enhances the capability of normal stack to return you max in O(1).
class maxStack{
    private:
    stack<int> *st;
    stack<int> *maxSt;
    public:
    maxStack(){
        st = new stack<int>();
        maxSt = new stack<int>();
    }
    ~maxStack(){
        delete st;
        delete maxSt;
    }
    void push(int value){
        if(maxSt->empty() || value >= maxSt->top()){
            // If value is greater than or equal to just push in max stack as well.  
            maxSt->push(value);
        }
        st->push(value);
        return;
    }

    int pop(){
        if(st->empty()){
            return -100;
        }
        int retVal = st->top();
        if(st->top() == maxSt->top()){
            maxSt->pop();
        }
        #ifdef DEBUG
        cout<<st->top();
        #endif
        st->pop();
        return retVal;
    }

    int max() const{
        if(maxSt->empty()){
            return -100;
        }
        return maxSt->top();
    }

};

int main(int argc, char *argv[]){
    // The following function creates the stack which returns the max in O(1).
    maxStack stackObj;
    stackObj.push(4);
    stackObj.push(19);
    stackObj.push(19);
    #ifdef DEBUG
    cout<<stackObj.max();
    stackObj.pop();
    cout<<stackObj.max();
    #endif
    stackObj.push(7);
    stackObj.push(14);
    stackObj.push(20);;
    return 0;
}
