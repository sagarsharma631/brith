/*

AUTHOR - SAGAR SHARMA

DATE CREATED - 17/04/2020

Question - 
Minimum insertions needed to make a string palindrome

*/

#include<iostream>
#include<algorithm>

using namespace std;

// Recursive solution - 2^n solution
int minInsertionsForPalindrome(string str, int lo, int hi) {
	if (lo == hi - 1) {
		if (str[lo] == str[hi]) {
			return 0;
		}
		else {
			return 1;
		}
	}

	if (str[lo] == str[hi]) {
		return minInsertionsForPalindrome(str, lo + 1, hi - 1);
	}
	else {
		return min(minInsertionsForPalindrome(str, lo + 1, hi), minInsertionsForPalindrome(str, lo, hi - 1)) + 1;
	}
}

// Dynamic Programming based approach by reversing the string
int minInsertionPalindrome(string& str) {
	int rows = 0;
	int cols = 0;
	rows = cols = static_cast<int>(str.length()) + 1;

	// creating DP matrix
	int** matrix = new int* [rows]{ NULL };
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[cols]{ 0 };
	}

	// reverse the string
	string revStr(str);
	reverse(str.begin(), str.end());

	// populate base cases for our DP table
	for (int i = 0; i < rows; ++i) {
		matrix[0][i] = 0;
	}

	for (int i = 1; i < cols; ++i) {
		matrix[i][0] = 0;
	}

	// populdating our DP Matrix
	for (int i = 1; i < rows; ++i) {
		for (int j = 1; j < cols; ++j) {
			if (str[j - 1] == revStr[i - 1]) {
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}
			else {
				matrix[i][j] = max({ matrix[i - 1][j], matrix[i][j - 1] });
			}
		}
	}

	return str.length() - matrix[rows - 1][cols - 1];

}

int main(int argc, char* argv[]) {
	string str = "abca";
	cout<<minInsertionPalindrome(str);
	return 0;
}
