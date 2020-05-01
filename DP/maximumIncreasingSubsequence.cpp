/*
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED(DD/MM/YYYY) - 01/05/2020
 *
 *	Question - Given an array of positive unique numbres, find the maximum sum of longest increasing subsequences
 *
 *
 */
#include<iostream>

using namespace std;

// DP solution for max increasing subsequence
int maxIncreasingSubsequence(int arr[], int size) {
    // Initialize and allocate our DP array
    int* dpArray = new int[size] {0};

    // Set our base cases
    for (int i = 0; i < size; ++i) {
        // This means that max sum till this element is atleast itself
        dpArray[i] = arr[i];
    }

    // Our return value.
    int maxSum = 0;

    // Filling our DP table
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dpArray[i] = max(dpArray[i], dpArray[j] + arr[i]);
            }
        }
        maxSum = max(maxSum, dpArray[i]);
    }

    return maxSum;
}

int main(int argc, char* argv[]) {
    /*int arr[] = { 1, 101, 2, 3, 100, 4, 5 };  106*/
    /*int arr[] = { 10,22,9,33,21,50,41,60,80 };    255*/  
    int arr[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11}; // 34
    int size = static_cast<int>(sizeof(arr) / sizeof(arr[0]));
    int returnVal = maxIncreasingSubsequence(arr, size);
    return 0;
}
