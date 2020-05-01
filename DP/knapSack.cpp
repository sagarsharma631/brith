/*
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED(DD/MM/YYYY) - 01/05/2020
 *
 *	Question - 0/1 Knapsack problem.
 *
 */

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG	// Macro toggles DPMatrix contents

using namespace std;

// Recursive 0/1 knapsack problem - Added weight from beginnning, Teach other method by decreasing weight from end
int knapsackproblem(int value[], int weight[], int size, int knapSackWeight, int currWeight, int currValue, int currIndex) {
    /*  Need to take care of two things in this one.
        1. currWeight is always smaller then or equal to knapSackWeight
        2. currIndex is in bound.
        Above two mentioned are our base cases.
    */

    if (currWeight > knapSackWeight) {
        return INT_MIN;
    }

    if (currIndex >= size) {
        return currValue;
    }
    // Exclude this item, Hence do not add either the weight of this item to the current weight or its value.
    int excluding = knapsackproblem(value, weight, size, knapSackWeight, currWeight, currValue, currIndex + 1);
    // Include this item, Hence add the weight of this item to the current weight.
    int including = knapsackproblem(value, weight, size, knapSackWeight, currWeight + weight[currIndex]
        , currValue + value[currIndex], currIndex + 1);

    return max(excluding, including);

}

// DP solution to 0/1 knapsack problem
int knapsackproblem(int value[], int weight[], int size, int knapSackWeight) {
    int rows = size + 1;
    int cols = knapSackWeight + 1;

    // Create Our DP Matrix our base cases have already been set by setting initializing the matrix content to 0.
    int** dpMatrix = new int* [rows]{ NULL };
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new int[cols] {0};
    }

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (j >= weight[i - 1]) {
                // populate max of if I put this item into knapsack or I do not put this item into the knapsack.
                dpMatrix[i][j] = max(dpMatrix[i - 1][j - weight[i - 1]] + value[i - 1], dpMatrix[i - 1][j]);
            }
            else {
                dpMatrix[i][j] = dpMatrix[i - 1][j];
            }
        }
    }

    int returnVal = dpMatrix[rows - 1][cols - 1];

#ifdef DEBUG
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << dpMatrix[i][j];
        }
        std::cout << std::endl;
    }
#endif // DEBUG

    // deallocate memory allocated on heap.
    for (int i = 0; i < rows; ++i) {
        delete[] dpMatrix[i];
    }
    delete[] dpMatrix;

    return returnVal;
}

int main(int argc, char* argv[]) {
    int value[]{ 20,5,10,40,15,25 };
    int weight[]{ 1,2,3,8,7,4 };
    int size = static_cast<int>(sizeof(value) / sizeof(value[0]));
    int returnVal = knapsackproblem(value,weight,size,10);
    return 0;
}
