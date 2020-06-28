/*

AUTHOR - SAGAR SHARMA

Question - Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

*/

#include<iostream>
#include<vector>
#include<algorithm>

#define DEBUG
using namespace std;

// Building our recurrence relation with the following recursive solution.
int minSquaresUtil(const vector<int>& squares, int num, int currIndex) {
    //-------------------- Base cases ----------------------------
    if (num == 0) {
        // If my num has already become 0, then there is no need to recurse
        return 0;
    }
    if (currIndex < 0 || num < 0) {
        return INT_MAX - 1;
    }
    //-------------------- Base cases end -------------------------

    // Include the square present at this index.
    int include = minSquaresUtil(squares, num - squares[currIndex], currIndex) + 1;

    // Exclude the square present at this index.
    int exclude = minSquaresUtil(squares, num, currIndex - 1);

    return min(include, exclude);
}

// DP optimization on the above recurrence relation. O(number * maxBound) maxBound refers to the largest perfect square less than the number.
int minSquaresUtil(const vector<int>& squares, int num) {
    // Memory allocation for DP matrix
    int rows = squares.size() + 1;
    int cols = num + 1;

    int** dpMatrix = new int*[rows] {nullptr};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new int[cols] {0};
    }

    // Filling our base cases with the help of recurrence relation.
    for (int i = 0; i < rows; ++i) {
        // This means we have no num left to make, but still left with some of the elements.
        dpMatrix[i][0] = 0;
    }
    for (int i = 0; i < cols; ++i) {
        // This means we have no elements left in the vector but still left with some num to make.
        dpMatrix[0][i] = INT_MAX - 1;
    }

    // Now fill our DP matrix with the help of Bottom - up approach.
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (i == rows - 1 && j == cols - 1) {
                cout << "Hello world" << endl;
            }
            if (j < squares[i - 1]) {
                dpMatrix[i][j] = dpMatrix[i - 1][j];
            }
            else if (j > squares[i - 1]) {
                // Take min of excluding and including the current item.
                dpMatrix[i][j] = min(dpMatrix[i][j - squares[i - 1]] + 1, dpMatrix[i - 1][j]);
            }
            else {
                // This means both are equal.
                dpMatrix[i][j] = 1;
            }
        }
    }

#ifdef DEBUG
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << dpMatrix[i][j] << " ";
        }
        cout << endl;
    }
#endif // DEBUG

    int retVal = dpMatrix[rows - 1][cols - 1];

    // Free the memory
    for (int i = 0; i < rows; ++i) {
        delete[] dpMatrix[i];
    }
    delete[] dpMatrix;

    return retVal;
}

int minSquares(int num) {
    vector<int> vec;
    auto findMaxBound = [&]() {
        int index = 1;
        while ((index * index) <= num) {
            vec.push_back(index * index);
            ++index;
        }
    };

    // Find the max bound for the squares.
    findMaxBound();

    // Never send the num as a reference, The util method will make operations to it.
    //return minSquaresUtil(vec, num, vec.size() - 1);
    return minSquaresUtil(vec, num);
}

int main(int argc, char* argv[]) {
    int temp = minSquares(12);
    cout << temp << endl;
    return 0;
}
