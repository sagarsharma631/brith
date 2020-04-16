/*

AUTHOR - SAGAR SHARMA

Question - Given a string S and a string T, count the number of distinct subsequences of S which equals T.

*/

#include<iostream>
#include<string>

using namespace std;

// The following method populates the variable for showing the number of distinct subsequences of pattern in str
bool numDistinctUtil(string& str, string& pattern, int strIndex, int patternIndex, int& retVal) {
	// Our base cases
	if (patternIndex == 0) {
		return true;
	}
	else if (strIndex == 0) {
		// We did not find the string
		return false;
	}
	else {
		if (str[strIndex] == pattern[patternIndex]) {
			// We found a match for one character
			if (numDistinctUtil(str, pattern, strIndex - 1, patternIndex - 1, retVal)) {
				retVal += 1;
				return true;
			}
			
			if(numDistinctUtil(str, pattern, strIndex - 1, patternIndex, retVal)) {
				retVal += 1;
				return true;
			}
		}
		else {
			if (numDistinctUtil(str, pattern, strIndex - 1, patternIndex - 1, retVal)) {
				retVal += 1;
				return true;
			}
		}
	}
}

int numDistinctUtil(string& str, string& pattern) {
	// just created our DP Matrix
	int** matrix = new int*[pattern.length() + 1];
	for (int index = 0; index <= pattern.length(); ++index) {
		matrix[index] = new int[str.length() + 1]{0};
	}
	int rows = pattern.length() + 1;
	int cols = str.length() + 1;

	// populating our base cases in DP matrix
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (i == 0 && j >= 0) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}

	// populate the DP matrix
	for (int i = 1; i < rows; ++i) {
		for (int j = 1; j < cols; ++j) {
			if (pattern[i - 1] == str[j - 1]) {
				matrix[i][j] = matrix[i - 1][j - 1] + matrix[i][j - 1];
			}
			else {
				matrix[i][j] = matrix[i][j - 1];
			}
		}
	}
	return matrix[rows - 1][cols - 1];
}

int numDistinct(string& str, string& pattern) {
	int retVal = 0;
	int strIndex = 0;
	int patternIndex = 0;
	numDistinctUtil(str, pattern, strIndex, patternIndex, retVal);
	return retVal;
}

int main(int argc, char* argv[]) {
	string str("banana");
	string pattern("ban");
	cout<<numDistinctUtil(str, pattern);
	return 0;
}
