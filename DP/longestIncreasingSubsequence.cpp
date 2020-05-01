/*
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED(DD/MM/YYYY) - 01/05/2020
 *
 */

#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;


// Recursive longest increasing subsequence
int longestIncreasingSubsequence(int arr[], int size, int currIndex, int prev) {

    // Our base case
    if (currIndex == size) {
        return 0;
    }

    // The element is not included - Hence sending prev as the element.
    int excluding = longestIncreasingSubsequence(arr, size, currIndex + 1, prev);

    // Include this element only if this element is bigger then the prev. Hence add 1 and send this element as prev
    // to next one.
    int including = 0;//INT_MIN
    if (arr[currIndex] > prev) {
        including = longestIncreasingSubsequence(arr, size, currIndex + 1, arr[currIndex]);
    }

    // either include 1 up or here one and the samething. 
    return max(excluding, including + 1);
}

// DP longest increasing subsequence
int longestIncreasingSubsequence(int arr[], int size) {
    // Building our DP table
    int* dpArray = new int[size] {0};
    
    // Initialize the DP array with base cases.
    for (int i = 0; i < size; ++i) {
        /* 
        Initializing with one means that longest increasing subsequence at this element is atleast 1 which means itself.
        Consider a strictly decreasing array LIS for this array would be 1 because each element in itself is Longest 
        Increasing subsequence. LIS for [5,4,3,2,1] is 1.
        */
        dpArray[i] = 1;
    }

    // Filling our DP array.
    int currMax = INT_MIN;
    int Max = INT_MIN;
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (arr[i] > arr[j]) {
                dpArray[i] = max(dpArray[i], dpArray[j] + 1);
                currMax = dpArray[i];
            }
        }
        Max = max(currMax, Max);
    }

    delete[] dpArray;
    return Max;
}

int main(int argc, char* argv[]) {
    //int arr[]{ -3,0,5,10,9,21,6 };
    int arr[]{ 5,4,3,2,1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << longestIncreasingSubsequence(arr, size);
    return 0;
}
