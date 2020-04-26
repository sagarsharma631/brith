/*
 *
 *	AUTHOR -  SAGAR SHARMA
 *
 *	DATE MODIFIED(DD/MM/YYYY) - 26/04/2020
 *
 */
#include<iostream>
#define DEBUG

using namespace std;

// Min path sum in a matrix
int minPathSum(int** matrix, int rows, int cols) {
    if (rows == 0 || cols == 0) {
        return 0;
    }

    // creating our DP matrix
    int** dpMatrix = new int* [rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new int[cols] {0};
    }

    // filling our base cases
    dpMatrix[0][0] = matrix[0][0];
    for (int i = 1; i < rows; ++i) {
        // We can reach the borders of the matrix only in 1 way.
        dpMatrix[i][0] = dpMatrix[i - 1][0] + matrix[i][0];
    }
    for (int i = 1; i < cols; ++i) {
        // We can reach the borders of the matrix only in 1 way.
        dpMatrix[0][i] = dpMatrix[0][i - 1] + matrix[0][i];
    }

    // filling our DP matrix
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            dpMatrix[i][j] = min(dpMatrix[i - 1][j], dpMatrix[i][j - 1]) + matrix[i][j];
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

    int result = dpMatrix[rows - 1][cols - 1];
    // Free all the allocated memory on Heap
    for (int i = 0; i < rows; ++i) {
        delete[] dpMatrix[i];
    }
    delete[] dpMatrix;

    return result;
}

int main(int argc, char* argv[]) {
    int** matrix = new int* [3] {NULL};
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new int[3] {0};
    }
    matrix[0][0] = 1;
    matrix[0][1] = 3;
    matrix[0][2] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 5;
    matrix[1][2] = 1;
    matrix[2][0] = 4;
    matrix[2][1] = 2;
    matrix[2][2] = 1;
    cout << minPathSum(matrix,3,3);
    return 0;
}
