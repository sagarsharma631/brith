/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 05/01/2020

DATE LAST MODIFIED - 05/01/2020

Question - 
Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. 

If such a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.

*/
#include<iostream>
//#define DEBUG
using namespace std;

bool populateDP(int arr[], int size, int sum){
    bool retVal = false;
    bool dp[size+1][sum+1];
    for(int i=0;i<=size;++i){
        for(int j=0;j<=sum;++j){
            if(i==0 && j > 0){
                dp[i][j] = false;    
            }
            else if(j == 0){
                dp[i][j] = true;
            }
        }
    }
    for(int i=1;i<=size;++i){
        for(int j=1;j<=sum;++j){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else if(arr[i-1] == j){
                dp[i][j] = true;
            }
            else{
                dp[i][j] = (dp[i-1][j] || dp[i-1][j - arr[i-1]])?true:false;
            }
        }
        // Check whether the sumth index has become true or not, if it has just break the loop and return true
        if(dp[i][sum]){
            retVal = true;
            break;
        }
    }
#ifdef DEBUG
    for(int i=0;i<=size;++i){
        for(int j=0;j<=sum;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
#endif    
    return retVal;
}

int main(int argc, char *argv[]){
    //int arr[] = {3,34,4,12,5,2};
    int arr[] = {12, 1, 61, 5, 9, 2};
    int sum = 24;
    int size = sizeof(arr)/sizeof(arr[0]);
    populateDP(arr,size,sum);
    return 0;
}
