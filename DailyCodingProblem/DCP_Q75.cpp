/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 06/02/2020

Question - 
Given an array of numbers, find the length of the longest increasing subsequence in the array. 

The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15], 

the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.

*/

#include<iostream>

using namespace std;

int longestIncreasingSubsequence(int arr[], int size){
    int maxLIS = 0;
    int countArr[size];
    for(int i=0;i<size;++i){
        countArr[i] = 0;
    }
    countArr[0] = 1;
    for(int i=1;i<size;++i){
        for(int j=0;j<i;++j){
            if(arr[j] <= arr[i]){
                if(countArr[i] < countArr[j]+1){
                    countArr[i] = countArr[j]+1;
                }
            }
        }
        maxLIS = (countArr[i] > maxLIS)?countArr[i]:maxLIS;
    }
    return maxLIS;
}

int main(int argc, char *argv[]){
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<longestIncreasingSubsequence(arr,size);
    return 0;
}
