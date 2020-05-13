/*
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED - 04/05/2020
 *
 *	Question - Rod cutting problem
 *
 */
#include<iostream>
#include<bits/stdc++.h>
#define DEBUG

using namespace std;

// Recursive solution to rod cutting problem
int rodCuttingProblem(int value[], int size, int rodLength, int currIndex, int valueTillNow) {
    /* ---------------Our base cases ------------------------- */
    //if (rodLength <= 0) {
    //    return valueTillNow;
    //}
    if (currIndex >= size) {
        // This means that the rod to be cut is still left whereas we are out of bounds
        return INT_MIN;
    }

    // check if enough rod length is left or not.
    if ((rodLength - (currIndex + 1)) < 0) {
        return valueTillNow;
    }
    /* ---------------Our base cases ------------------------- */

    // Including the element
    int including = rodCuttingProblem(value, size, rodLength - (currIndex + 1), currIndex, valueTillNow + value[currIndex]);

    // exclude this element
    int excluding = rodCuttingProblem(value, size, rodLength, currIndex + 1, valueTillNow);

    return max(including, excluding);
}

int rodCuttingProblem(int value[], int size, int rodLength, int currIndex) {
    if (rodLength == 0) {
        return 0;
    }

    // This base case means that i am still left with some of my rod, but I do not have any bars remaining
    if (currIndex >= size) {
        return INT_MIN;
    }

    int including = rodCuttingProblem(value, size, rodLength - (currIndex + 1), currIndex) + value[currIndex];

    int excluding = rodCuttingProblem(value, size, rodLength, currIndex + 1);

    return max(including, excluding);
}

// DP solution for rod cutting problem
int rodCuttingProblem(int value[], int size) {
    int rows = size + 1;
    int cols = size + 1;

    // create the DP matrix
    int** dpMatrix = new int* [rows] {nullptr};
    for (int i = 0; i < rows; ++i) {
        dpMatrix[i] = new int[cols] {0};
    }

    // fill in the base cases
    for (int i = 1; i < rows; ++i) {
        // This means if there is no rod left with use just return whatever the value you have achieved till now.
        dpMatrix[i][0] = 0;
    }
    for (int i = 0; i < cols; ++i) {
        dpMatrix[0][i] = 0;
    }

    // fill in our DP matrix.
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (j < i) {
                dpMatrix[i][j] = dpMatrix[i - 1][j];
            }
            else {
                // take max of considering this element and not considering this element.
                dpMatrix[i][j] = max(dpMatrix[i - 1][j], dpMatrix[i][j - i] + value[i - 1]);
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
    int value[]{ 1,5,8,9,10,17,17,20 };
    int size = static_cast<int>(sizeof(value) / sizeof(value[0]));
    int retVal = rodCuttingProblem(value, size);
    return 0;
}
