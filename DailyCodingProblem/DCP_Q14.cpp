/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 12/02/2020

Question - 
Given an array arr[] of positive integers,

the task is to find whether it is possible to make this array strictly decreasing by modifying at most one element.

BUG - Does not work if the list already in strictly Decreasing order. Need to address it.

*/
#include<iostream>

using namespace std;

bool canBeStrictlyDecreasing(int arr[], int size){
    bool retVal = false;
    for(int i=0;i<size-1;++i){
        if(arr[i+1] > arr[i]){
            if(retVal == false){
                if((arr[i] - arr[i+2]) > 1){
                    retVal = true;
                }
                else if(arr[i-1] - arr[i+1] > 1){
                    retVal = true;
                }
            }
            else{
                retVal = false;
                break;
            }
        }
    }
    return retVal;
}

int main(int argc, char *argv[]){
    int arr[] = {12,9,10,8,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<canBeStrictlyDecreasing(arr,size);
    return 0;
}
