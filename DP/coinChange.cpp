/*

AUTHOR - SAGAR SHARMA

DATE LAST MODIFIED(DD/MM/YYYY) - 26/04/2020

*/

#include<iostream>

#define DEBUG   // Please comment this out if you don't want see dpMatrix contents

// DP coin change problem
int coinChangeProblem(int arr[], int size, int amount) {
    int rows = size + 1;
    int cols = amount + 1;

    // creating our DP matrix
    int** dpMatrix = new int*[rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new int[cols] {0};
    }

    // filling our base cases.
    for (int i = 0; i < rows; ++i) {
        // when we have a coin left but the amount has already become 0.
        dpMatrix[i][0] = 1;
    }
    for (int i = 1; i < cols; ++i) {
        // when we have no coins left but we do have some amount still left with us.
        dpMatrix[0][i] = 0;
    }

    // filling our dpMatrix
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (j < arr[i - 1]) {
                dpMatrix[i][j] = dpMatrix[i - 1][j];
            }
            else {
                dpMatrix[i][j] = dpMatrix[i - 1][j] + dpMatrix[i][j - arr[i - 1]];
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
    int retVal = dpMatrix[rows - 1][cols - 1];
  
    // Deallocate memory or else memory leak
    for(int i=0;i<rows;++i){
        delete[] dpMatrix[i];
    }
    delete[] dpMatrix;
    return retVal;
}

int main(int argc, char* argv[]) {
    int arr[]{ 1,3,5,7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << coinChangeProblem(arr, size, 10);
    return 0;
}
