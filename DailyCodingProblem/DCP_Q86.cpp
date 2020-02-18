/*

AUTHOR - SAGAR SHARMA

DATE - 17-02-2020

Question - 

Given a string of parentheses, write a function to compute the minimum number of 

parentheses to be removed to make the string valid (i.e. each open parenthesis is eventually closed).

*/
#include<iostream>
#include<string>
#include<stack>

#define DEBUG

using namespace std;

// canPop(stack top, current char in string)
bool canPop(const char &top, const char &ref){
    bool retVal = false;
    
    if(top == '(' && ref == ')'){
        retVal = true;
    }

    return retVal;
}

// Following method tells how many brackets need to be deleted
void calcMinDel(const string &str, int& count){
    stack<char> st;
    int index = 0;
    // while string is not empty.
    while(str[index] != '\0'){
        if(st.empty()){
            st.push(str[index]);
        }
        else{
            if(canPop(st.top(),str[index])){
                st.pop();
            }
            else{
                st.push(str[index]);
            }
        }
        ++index;
    }
    count = st.size();
    return;
}

int main(int argc, char *argv[]){
    string str{"()())((())"};
    int count = 0;
    calcMinDel(str,count);
    #ifdef DEBUG
    cout<<count<<endl;
    #endif
    return 0;
}
