#include<iostream>

#define DEBUG

using namespace std;

// Recursive implmentation for interleaving string
bool interLeavingString(const string& str1, const string& str2, const string& str3, int str1Index, int str2Index, int str3Index) {

    if (str1Index >= str1.length() && str2Index >= str2.length() && str3Index >= str3.length()) {
        return true;
    }

    if (str3Index >= str3.length() && (str1Index < str1.length() || str2Index < str2.length())) {
        return false;
    }

    if (str1Index >= str1.length()) {
        if (str2Index >= str2.length()) {
            return false;
        }
        if (str2[str2Index] == str3[str3Index]) {
            return interLeavingString(str1, str2, str3, str1Index, str2Index + 1, str3Index + 1);
        }
        else {
            return false;
        }
    }

    if (str2Index >= str2.length()) {
        if (str1Index >= str1.length()) {
            return false;
        }
        if (str1[str1Index] == str3[str3Index]) {
            return interLeavingString(str1, str2, str3, str1Index + 1, str2Index, str3Index + 1);
        }
        else {
            return false;
        }
    }

    if (str1[str1Index] == str2[str2Index]) {
        if (str1[str1Index] != str3[str3Index]) {
            return false;
        }
        else {
            return interLeavingString(str1, str2, str3, str1Index + 1, str2Index, str3Index + 1)
                || interLeavingString(str1, str2, str3, str1Index, str2Index + 1, str3Index + 1);
        }
    }
    else {
        if(str1[str1Index] == str3[str3Index]) {
            return interLeavingString(str1, str2, str3, str1Index + 1, str2Index, str3Index + 1);
        }
        else if(str2[str2Index] == str3[str3Index]){
            return interLeavingString(str1, str2, str3, str1Index, str2Index + 1, str3Index + 1);
        }
        else {
            return false;
        }
    }
}

// Dynamic Programming Solution for interleaving string
bool interLeavingString(const string& str1, const string& str2, const string& str3) {
    // str1 and str2 are strings which on interleaving result into str3
    int rows = str1.length() + 1;
    int cols = str2.length() + 1;

    // Creating our DP matrix
    bool** dpMatrix = new bool* [rows] {NULL};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new bool[cols] {false};
    }

    // Filling our base cases.
    
    // Filling our DP table
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {

        }
    }

#ifdef DEBUG
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << dpMatrix[i][j];
        }
        std::cout << std::endl;
    }
#endif // DEBUG

    int result = dpMatrix[rows - 1][cols - 1];
    // Avoid Memory leaks
    for (int i = 0; i < rows; ++i) {
        delete[] dpMatrix[i];
    }
    delete[] dpMatrix;
    return result;
}

int main(int argc, char *argv[]){
    std::cout<<interLeavingString("aabd","abdc","aabdbadc");	// false
    std::cout<<interLeavingString("aabcc","dbbca","aadbbcbcac");	// true
    return 0;
}
