#include<iostream>
#include<algorithm>

using namespace std;

int minDeletionsUtil(string str, int lo, int hi) {
    // Our base cases
    if (lo == hi) {
        return 0;
    }
    if (hi = lo + 1) {
        if (str[lo] == str[hi]) {
            return 0;
        }
        else {
            // We return 1 because we need to delete 1 character and then there is only one character left
            // which in itself is a palindrome.
            return 1;
        }
    }

    if (str[lo] == str[hi]) {
        return minDeletionsUtil(str, lo + 1, hi - 1);
    }
    else {
        return min(minDeletionsUtil(str, lo, hi - 1), minDeletionsUtil(str, lo + 1, hi)) + 1;
    }
}

int minDeletions(string str) {
    int retVal = INT_MAX;
    if (str.length() == 0 || str.length() == 1) {
        // 0 or 1 characters do not need anything to be deleted.
        return 1;
    }
    return minDeletionsUtil(str, 0, str.length() - 1);
}

int main(int argc, char* argv[]) {
    cout << minDeletions("ACBCDBAA");
    return 0;
}