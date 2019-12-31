/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 31/12/2019

Question - 
Given a string, find the palindrome that can be made by inserting the fewest number of characters as possible anywhere in the word. 

If there is more than one palindrome of minimum length that can be made, 

return the lexicographically earliest one (the first one alphabetically).

For example, given the string "race", you should return "ecarace", 

since we can add three letters to it (which is the smallest amount to make a palindrome). 

There are seven other palindromes that can be made from "race" by adding three letters, but "ecarace" comes first alphabetically.

As another example, given the string "google", you should return "elgoogle".

NOTE : This is recursive solution, needed to check all the overlapping sub problems, before going to DP.
*/

#include<iostream>
#include<conio.h>
using namespace std;

namespace util {
	int Min(int first, int second) {
		return (first > second) ? second : first;
	}
};

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
		return util::Min(minInsertionsForPalindrome(str, lo + 1, hi), minInsertionsForPalindrome(str, lo, hi - 1)) + 1;
	}
}

int main(int argc, char *argv[]) {
	cout << minInsertionsForPalindrome("abcda", 0, 4);
	_getch();
	return 0;
}
