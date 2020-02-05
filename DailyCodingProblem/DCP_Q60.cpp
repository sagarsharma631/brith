/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 25/01/2020

Question - 

Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, 

since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55


*/

#include<iostream>
//#define DEBUG

using namespace std;

// This variable holds the number of partitions which lead to sum.
int count = 0;

template<typename T>
bool canSplitIntoTwo(T arr[], int size, int &half){
    T sum = 0;
    for(int i=0;i<size;++i){
        sum += arr[i];
    }
    return (sum%2 == 0 && sum != 0)?true:false;
}

// The following function makes use of recursion just to check all subproblems.
template<typename T>
bool checkPartition(T arr, int size, int sum, int currIndex){
    if(sum == 0){
        ++count;
        return true;
    }

    if(sum < 0 || currIndex > size){
        return false;
    }

    return checkPartition(arr,size,sum - arr[currIndex], currIndex+1) || checkPartition(arr,size,sum,currIndex+1);
}

int main(int argc, char *Argv[]){
    //int arr[] = {15, 5, 20, 10, 35, 15, 10};
    int arr[] = {2,4,6,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    if(canSplitIntoTwo<int>(arr,size,sum)){
        cout<<checkPartition(arr,size,16,0)<<endl;
        #ifdef DEBUG
        cout<<count<<endl;
        #endif
    }
    return 0;
}
