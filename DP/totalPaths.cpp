/*
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED(DD/MM/YYYY) - 27/04/2020
 *
 */

#include<iostream>
#include<queue>

using namespace std;

// To check whether the node being inserted in Queue while BFS is within the matrix bounds or not
bool isInBounds(const int& xIndex, const int& yIndex, const int& rows, const int& cols) {
    return ((xIndex < rows) && (yIndex < cols));
}

// BFS solution contains overlapping of subProblems
int totalPathsInMatrix(int rows, int cols) {
    // no path can be achieved if any of the arguments is 0.
    if (rows == 0 || cols == 0) {
        return 0; 
    }
    int xIndex = 0;
    int yIndex = 0;

    // creating matrix
    int** matrix = new int* [rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols] {0};
    }

    // The following queue will be used for BFS traversal.
    std::queue<std::pair<int, int>> travQ;
    travQ.push(make_pair(xIndex, yIndex));
    pair<int, int> temp;

    // Now start filling our matrix
    while (!travQ.empty()) {
        temp = travQ.front();
        travQ.pop();
        // travers the left node
        if (isInBounds(temp.first, temp.second + 1, rows, cols)) {
            travQ.push(make_pair(temp.first, temp.second + 1));
            matrix[temp.first][temp.second + 1] += 1;
        }
        if (isInBounds(temp.first + 1, temp.second, rows, cols)) {
            travQ.push(make_pair(temp.first + 1, temp.second));
            matrix[temp.first + 1][temp.second] += 1;
        }
    }
   
    int result = matrix[rows - 1][cols - 1];
    // Delete all the allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return result;
}

// DP solution for total paths in a matrix
int countPaths(int rows, int cols) {
    if (rows == 0 || cols == 0) {
        return 0;
    }

    // creating our DP matrix
    int** dpMatrix = new int* [rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new int[cols] {0};
    }

    // filling our base cases
    for (int i = 1; i < rows; ++i) {
        // We can reach the borders of the matrix only in 1 way.
        dpMatrix[i][0] = 1;
    }
    for (int i = 1; i < cols; ++i) {
        // We can reach the borders of the matrix only in 1 way.
        dpMatrix[0][i] = 1;
    }

    // filling our DP Matrix.
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            // each and every node can only be reached either from above or from left
            dpMatrix[i][j] = dpMatrix[i - 1][j] + dpMatrix[i][j - 1];
        }
    }

    int result = dpMatrix[rows - 1][cols - 1];
    // Free all the allocated memory on Heap
    for (int i = 0; i < rows; ++i) {
        delete[] dpMatrix[i];
    }
    delete[] dpMatrix;

    return result;
}

int main(int argc, char* argv[]) {
    std::cout << countPaths(3,7);
    return 0;
}
