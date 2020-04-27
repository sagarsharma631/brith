/*
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED - 27/04/2020
 *
 */

#include<iostream>
#include<string>

#define DEBUG

using namespace std;

int distinctSubsequencesUtil(const string& str, const string& pattern, int strIndex, int patternIndex) {
    // Our base cases
    if (strIndex < 0 && patternIndex > 0) {
        return 0;
    }
    else if (strIndex > 0 && patternIndex < 0) {
        return 1;
    }
    else if (strIndex == 0 && patternIndex == 0) {
        return (str[strIndex] == pattern[patternIndex]) ? 1 : 0;
    }

    if (str[strIndex] == pattern[patternIndex]) {
        return distinctSubsequencesUtil(str, pattern, strIndex - 1, patternIndex - 1) +
            distinctSubsequencesUtil(str, pattern, strIndex - 1, patternIndex);
    }
    else {
        return distinctSubsequencesUtil(str, pattern, strIndex - 1, patternIndex);
    }
}

// Recursive solution for number of distinct subsequences of S which equals T
int distinctSubsequences(const string& str, const string& pattern) {
    return distinctSubsequencesUtil(str, pattern, str.length() - 1, pattern.length() - 1);
}

// DP solution to distinct subsequences in a string
int distinctSubsequencesDP(const string& str, const string& pattern) {
    int rows = pattern.length() + 1;
    int cols = str.length() + 1;

    if (rows == 0 || cols == 0) {
        return 0;
    }

    // Building our DP table
    int** dpmatrix = new int* [rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        dpmatrix[i] = new int[cols] {0};
    }

    // Fill our base conditions
    for (int i = 1; i < rows; ++i) {
        dpmatrix[i][0] = 0;
    }
    for (int j = 0; j < cols; ++j) {
        dpmatrix[0][j] = 1;
    }

    // Filling the DP table
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (str[j - 1] == pattern[i - 1]) {
                dpmatrix[i][j] = dpmatrix[i - 1][j - 1] + dpmatrix[i][j - 1];
            }
            else {
                dpmatrix[i][j] = dpmatrix[i][j - 1];
            }
        }
    }
#ifdef DEBUG
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << dpmatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
#endif // DEBUG

    int returnVal = dpmatrix[rows - 1][cols - 1];
    for (int i = 0; i < rows; ++i) {
        delete[] dpmatrix[i];
    }
    delete[] dpmatrix;

    return returnVal;
}

int main(int argc, char* argv[]) {
    cout<< distinctSubsequencesDP("rabbbit","rabbit");
    return 0;
}
