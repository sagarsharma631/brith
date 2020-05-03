#include<iostream>
#include<string>
#define DEBUG // Comment it if you don't wanna see the contents of DP matrix

using namespace std;

// Recursive function to calculate minimum number of changes to be done to a string to convert it to another.
// Limit exceeded at source -> "dinitrophenylhydrazine" target -> "benzalphenylhydrazone"
int minEditDistance(const string& s, const string& t, int sourceIndex, int targetIndex) {
    // Our base cases.
    if (sourceIndex < 0) {
        // This is the base where my source string is now empty but I am still left with some characters in target string.
        return targetIndex + 1;
    }
    if (targetIndex < 0) {
        // This is the case where my target string has become empty, this means I have already converted my source string
        // to target string, hence whatever the characters are remaining in the source string just delete them.
        return sourceIndex + 1;
    }

    // If both the characters in the source string and target string are same. There is no need to perform any operation.
    // Just need to check the remaining chars of the string.
    if (s[sourceIndex] == t[targetIndex]) {
        return minEditDistance(s, t, sourceIndex - 1, targetIndex - 1);
    }

    // If the characters of both strings are not same.

    // Case 1: Insert a new character to the source string.
    int insertChar = minEditDistance(s, t, sourceIndex, targetIndex - 1) + 1;

    // Case 2: Delete the character from the source string.
    int deleteChar = minEditDistance(s, t, sourceIndex - 1, targetIndex) + 1;

    // Case 3: Replace the character in the source string
    int replaceChar = minEditDistance(s, t, sourceIndex - 1, targetIndex - 1) + 1;

    // Return the minimum of the above 3 operations.
    return min({ insertChar,deleteChar,replaceChar });
}

// DP solution to compute edit distance between two strings
int minEditDistance(const string& s, const string& t) {
    int rows = t.length() + 1;
    int cols = s.length() + 1;

    // create our DP matrix
    int** dpMatrix = new int* [rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new int[cols] {0};
    }

    // populate the base cases.
    for (int i = 0; i < rows; ++i) {
        // This is the case when my target string is empty and I need to add characters.
        dpMatrix[i][0] = i;
    }
    for (int i = 1; i < cols; ++i) {
        // This is the case when my source string is empty.
        dpMatrix[0][i] = i;
    }

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (s[j - 1] == t[i - 1]) {
                // if both the chars are same
                dpMatrix[i][j] = dpMatrix[i - 1][j - 1];
            }
            else {
                // Take minimum of either of the three operation as done in recurrence relation.
                dpMatrix[i][j] = min({ dpMatrix[i - 1][j] + 1,dpMatrix[i][j - 1] + 1,dpMatrix[i - 1][j - 1] + 1 });
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

    // Dealocate the memory or else memory leak.
    for (int i = 0; i < rows; ++i) {
        delete[] dpMatrix[i];
    }
    delete[] dpMatrix;

    return retVal;
}

int main(int argc, char* argv[]) {
    string source = "horse";    // intention
    string target = "ros";      // execution
    int retVal = minEditDistance(source, target);
    return 0;
}
