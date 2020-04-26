#include<iostream>
#include<algorithm>
#define DEBUG

using namespace std;

// Recursive Solution for subSet problem
bool subSetSumProblem(int arr[], int size, int rem, int index, int& iterations) {
    if (rem == 0) {
        return true;
    }
    if (index >= size || rem < 0) {
        return false;
    }
    ++iterations;
    return subSetSumProblem(arr, size, rem, index + 1, iterations) ||
        subSetSumProblem(arr, size, rem - arr[index], index + 1, iterations);
}

// Top Down DP solution for subset sum problem
bool subSetSumProblem(int arr[], int size, int k) {
    int rows = size + 1;
    int cols = k + 1;

    // creating our 2D DP Matrix
    bool** dpMatrix = new bool* [rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new bool[cols] {false};
    }

    // filling base cases for our DP Matrix
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i][0] = true;
    }
    for (int i = 0; i < cols; ++i) {
        dpMatrix[1][i] = false;
    }

    // filling our DP Table
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (j < arr[i - 1]) {
                dpMatrix[i][j] = dpMatrix[i - 1][j];
            }
            else if(j > arr[i - 1]){
                dpMatrix[i][j] = dpMatrix[i - 1][j] || dpMatrix[i-1][j - arr[i - 1]];
            }
            else {
                dpMatrix[i][j] = true;
            }
        }
    }
    

#ifdef DEBUG
    for(int i=0;i<rows;++i){
    	for(int j=0;j<cols;++j){
	    std::cout<<dpMatrix[i][j]<<" ";
	}
	std::cout<<std::endl;
    }
#endif
    // return the result 
    return dpMatrix[rows - 1][cols - 1];
}

// DP can equal partition - This is a variation of above problem.
bool canPartitionEqual(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return (sum % 2) ? false : subSetSumProblem(arr, size, sum / 2);
}
