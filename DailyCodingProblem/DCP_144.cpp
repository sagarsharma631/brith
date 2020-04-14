/*

AUTHOR - SAGAR SHARMA

DATE CREATED - 15/04/2020

Question - Given an array of numbers and an index i,

return the index of the nearest larger number of the number at index i,

where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

*/

#include<iostream>
#include<stack>

using namespace std;

int main(int argc, char *argv[]){
    int arr[]{4,1,3,5,6};
    int size = static_cast<int>(sizeof(arr)/sizeof(arr[0]));
    //int *ptr = new int[size]{-1};
    int ptr[5];
    stack<int> st; 
    int index = 0;
    bool shouldPush = true;
    while(index < size){
        // Reset this variable
        shouldPush = true;
        if(st.empty()){
            st.push(index);
        }
        else{
            while(arr[index] > arr[st.top()]){
                ptr[st.top()] = index;
                st.pop();
                if(st.empty()){
                    shouldPush = false;
                    st.push(index);
                    break;
                }
            }
            if(shouldPush){
                st.push(index);
            }
        }
        ++index;
    }
    
    return 0;
}
