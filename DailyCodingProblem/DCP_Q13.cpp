/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 06/01/2020

DATE LAST MODIFIED - 06/01/2020

Question - 

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

*/
#include<iostream>

using namespace std;

int convertCharToIndex(char temp){
    return temp - 'a';
}

char convertIndexToChar(int index){
    return static_cast<char>(index);
}

// calLongSubStrKChars(string to be traversed, utmost how many distinct characters)
int calLongSubStrKChars(const string &str, int k){
    int retVal = 0;
    if(k > str.length() || str.length() == 0){
        retVal = -1;
    }
    else{
        int hashArray[26];
        int currLength;
        int currMaxLength;
        int i = 0;
        int start = 0;
        int last = 0;
        while(str[i] != '\0'){
            if(currLength >= k){
                while()
                
            }
            // This condition tells that the character being parsed is actually not an unique character.
            if(hashArray[convertCharToIndex(str[i])] == 0 || hashArray[convertCharToIndex(str[i])] > 0){
                ++last;
                currLength += 1;
            }
            ++i;
        }
    }
    return retVal;
}

int main(int argc, char *argv[]){
    cout<<calLongSubStrKChars("aabbcc",2);
    return 0;
}
