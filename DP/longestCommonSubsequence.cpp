/*
 *
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED - 27/04/2020
 *
 *
 */
#include<iostream>
#include<string>

#define DEBUG

using namespace std;

// Recursive solution for longest Common Subsequence 
int longestCommonSubsequenceUtil(const string str1, const string str2, int str1Index, int str2Index) {
    // Base cases
    if (str1Index < 0 || str2Index < 0) {
        // Cannot compare other string if either of the strings is empty.
        return 0;
    }
    if (str1[str1Index] == str2[str2Index]) {
        // added 1 because the strings had atleast this character as same.
        return longestCommonSubsequenceUtil(str1, str2, str1Index - 1, str2Index - 1) + 1;
    }
    else {
        return max(longestCommonSubsequenceUtil(str1, str2, str1Index, str2Index - 1)
            , longestCommonSubsequenceUtil(str1, str2, str1Index - 1, str2Index));
    }
}

// DP solution for longest common subsequence
int longestCommonSubsequenceUtil(const string str1, const string str2) {
    int rows = str1.length() + 1;
    int cols = str2.length() + 1;

    // creating our DP matrix
    int** dpMatrix = new int* [rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new int[cols] {0};
    }

    // filling our base cases.
    for (int i = 1; i < rows; ++i) {
        dpMatrix[i][0] = 0;
    }
    for (int i = 0; i < cols; ++i) {
        dpMatrix[0][i] = 0;
    }


    // filling our DP table
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dpMatrix[i][j] = dpMatrix[i - 1][j - 1] + 1;
            }
            else {
                dpMatrix[i][j] = max(dpMatrix[i - 1][j], dpMatrix[i][j - 1]);
            }
        }
    }

    int result = dpMatrix[rows - 1][cols - 1];
    // delete the heap allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] dpMatrix[i];
    }
    delete[] dpMatrix;
    return result;
}

int longestCommonSubsequence(const string str1, const string str2) {
    // Calling the DP version of longest common subsequence - takes lot of time for given strings if I call recursive version.
    return longestCommonSubsequenceUtil(str1, str2);
}

int main(int argc, char* argv[]) {
    std::cout << longestCommonSubsequence("ylqpejqbalahwr", "yrkzavgdmdgtqpg");
    return 0;
}
