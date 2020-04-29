/*
 *	NAME - SAGAR SHARMA
 *
 *	DATE MODIFIED - 29/04/2020
 *
 *	Question - number of ways to reach top of a staircase
 *
 */
#include<iostream>

using namespace std;

// Recursive stair case problem - Time limit exceeded at stairs = 44
int numWays(int stairs, int currStair) {
    if (currStair > stairs) {
        return 0;
    }
    if (currStair == stairs) {
        return 1;
    }
    return numWays(stairs, currStair + 1) + numWays(stairs, currStair + 2);
}

// DP solution
int numWays(int stairs) {
    // initializing the DP array also means setting up the base cases.    
    int* dpArray = new int[stairs + 1]{ 0 };
    // Setting another base case
    dpArray[0] = 1;
    for (int i = 0; i < stairs; ++i) {
        if (i + 1 <= stairs) {
            dpArray[i + 1] += dpArray[i];
        }
        if (i + 2 <= stairs) {
            dpArray[i + 2] += dpArray[i];
        }
    }
    return dpArray[stairs];
}

int main(int argc, char* argv[]) {
    numWays(44);
    return 0;
}
