#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>	// included for INT_MAX while compiling with g++ - Remove it or comment in Visual Studio

#define DEBUG

// Recursive solution to Min coin change
int minCoinChange(int arr[], int size, int currIndex, int amount) {
    if (size == 0 || amount == 0) {
        return 0;
    }
    // Our base cases
    if (currIndex < 0 && amount > 0) {
        return INT_MAX - 1;
    }
    
    if (amount < 0) {
        return INT_MAX - 1;
    }

    /* Our recurrence relation -  The first recursive call means we did not include the current Element and the 
        second recursive call means we did use the current element.
    */
    return min(minCoinChange(arr, size, currIndex - 1, amount), 
                minCoinChange(arr, size, currIndex, amount - arr[currIndex]) + 1);
}

// DP Min coin problem
int minCoinChange(int arr[], int size, int amount) {
    int rows = size + 1;
    int cols = amount + 1;

    // creating the DP matrix
    int** dpMatrix = new int* [rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new int[cols] {0};
    }

    // filling our base cases
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i][0] = 0;
    }
    for (int i = 1; i < cols; ++i) {
        dpMatrix[0][i] = INT_MAX - 1;
    }

    // filling our DP table
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (j < arr[i - 1]) {
                dpMatrix[i][j] = dpMatrix[i - 1][j];
            }
            else if (j == arr[i - 1]) {
                dpMatrix[i][j] = 1;
            }
            else {
                dpMatrix[i][j] = min(dpMatrix[i - 1][j], dpMatrix[i][j - arr[i - 1]] + 1);
            }
        }
    }
 // Displays our DPmatrix - Just for debugging purpose.
#ifdef DEBUG
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << dpMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
#endif
    return dpMatrix[rows - 1][cols - 1];
}

int main(int argc, char *argv[]){
    int arr[]{ 1,3,5,7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << minCoinChange(arr, size, 10);
    return 0;
}
