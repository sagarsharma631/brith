/*
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED(DD/MM/YYYY) - 26/04/2020
 *
 */

#include<iostream>
#include<algorithm>

// Recursive longest increasing subsequence
int longestIncreasinSubsequence(int arr[], int size, int currIndex, int prevElement, bool& shouldInclude) {
    if (currIndex >= size) {
        return 0;
    }
    int skippingElement = longestIncreasinSubsequence(arr, size, currIndex + 1, prevElement, shouldInclude);
    if (arr[currIndex] < prevElement) {
        /* 
        This means that this element cannot be part of this increasing subsequence. It means we need to start a new    
        subsequence from this element or skip this element and keep adding subsequent elements to the subsequence.
        */
        int startingNewSequence = longestIncreasinSubsequence(arr, size, currIndex + 1, arr[currIndex], shouldInclude) + 1;
    }
    else if (arr[currIndex] > prevElement) {
        int includingElement = longestIncreasinSubsequence(arr, size, currIndex + 1, arr[currIndex],shouldInclude);
        if (shouldInclude) {
            return  max(skippingElement, includingElement+1);
        }
        return max(skippingElement,includingElement);
    }
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
    bool shouldInclude;
    cout << longestIncreasingSubsequence(arr, size);
    return 0;
}
