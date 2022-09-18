/*
AUTHOR - SAGAR SHARMA

Question - A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

*/

#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
/* Memoization Top Down Solution */

unordered_map<int, int> memoize;
int numsDecodingsUtil(const string& s, int currIndex) {
  if (memoize.find(currIndex) != memoize.end()) {
		return memoize[currIndex];
	}
	
  auto charToInt = [&](char ch) -> int {
		return ch - '0';
	};

	if (s[currIndex] == '0') {
		return 0;
	}

	if (currIndex >= s.size() - 1) {
		//result += 1;
		return 1;
	}
	int result = 0;
	if (currIndex + 1 < s.size() &&
		charToInt(s[currIndex]) * 10 + charToInt(s[currIndex + 1]) <= 26) {
		result += numsDecodingsUtil(s, currIndex + 2);
	}

	result += numsDecodingsUtil(s, currIndex + 1);
	memoize[currIndex] = result;
	return result;
	
}

int numDecodings(string s)
{
	int result = numsDecodingsUtil(s, 0);
	return result;
}

int main(int argc,char *argv[])
{
  string s("2236");
  int result = numDecodings(s);  
  return 0;
}
