#include<iostream>
#include<string>

#define DEBUG

using namespace std;

// Following method implements addtion/deletion recursively. because recurrence relation for both the problems is same.
int minCharsToDeletePalindrome(const string& str, int lo, int hi) {
    if (lo == hi) {
        // Single character is always a palindrome
        return 0;
    }

    if (hi == lo + 1) {
        if (str[lo] == str[hi]) {
            return 0;
        }
        // This means there are only characters left now, 2 chars always need only 1 character to delete such they
        // become a palindrome.
        return 1;
    }

    if (str[lo] == str[hi]) {
        return minCharsToDeletePalindrome(str, lo + 1, hi - 1);
    }
    else {
        // Added one because we have already deleted one character in both the cases.
        return min(minCharsToDeletePalindrome(str, lo, hi - 1)
            , minCharsToDeletePalindrome(str, lo + 1, hi)) + 1;
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
    return longestCommonSubsequenceUtil(str1, str2);
}

// DP solution to min number of deletions to make string palindrome.
int minCharsToDeletePalindrome(string& str) {
    string actualString(str);
    reverse(str.begin(), str.end());
    int charsPalindrome = longestCommonSubsequence(actualString, str);
    str = actualString;
    return str.length() - charsPalindrome;
}

// DP solution to min number of additions to make a string palindrome
int minCharsToAddPalindrome(string& str) {
    return minCharsToDeletePalindrome(str);
}

int main(int argc, char* argv[]) {
    string str = "aebcbda";
    cout<<minCharsToAddPalindrome(str);
    return 0;
}
