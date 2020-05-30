/*
    AUTHOR - SAGAR SHARMA
    
    Question - Remove "k" from a string such that the remaining number is smallest

*/

#include<iostream>

// Recursive implementation of removing K digits to form smallest number.
string removeKChars(const string& str, string temp, const int& toMake, int currIndex) {
	if (static_cast<int>(temp.length() == toMake)) {
		return temp;
	}

	if (currIndex >= str.size()) {
		return str;
	}

	// Implement through recursion. Check for either include the element or not to include it.
	string include = removeKChars(str, temp + str[currIndex], toMake, currIndex + 1);

	string exclude = removeKChars(str, temp, toMake, currIndex + 1);

	int includeNum = (include.empty()) ? INT_MAX : stoi(include);
	int excludeNum = (exclude.empty()) ? INT_MAX : stoi(exclude);

	return (includeNum < excludeNum) ? include : exclude;
}

string removeKChars(const string& str, int k) {
	int charsToMake = static_cast<int>(str.length()) - k;
	string retVal = removeKChars(str, "", charsToMake, 0);;
	if (retVal[0] == '0') {
		retVal.erase(0, 1);
	}
	return retVal;
}

int main(int argc. char *argv[]){
  removeKChars("1432219",3);
}
