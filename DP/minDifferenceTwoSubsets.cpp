/*
 *	NAME - SAGAR SHARMA
 *
 *	DATE MODIFIED(DD/MM/YYYY) - 01/05/2020
 *
 *	Question - Given an array, find the minimum difference between two subsets
 *
 */
#include<iostream>

using namespace std

// Recursive solution for min partition difference - But starting from first element.
int minDifference(int arr[], int size, int currIndex, int set1, int set2) {
    // Our base case
    if (currIndex >= size) {
        return abs(set1 - set2);
    }

    // include the element in set 1
    int diff1 = minDifference(arr, size, currIndex + 1, set1 + arr[currIndex], set2);
    // include the element in set 2
    int diff2 = minDifference(arr, size, currIndex + 1, set1, set2 + arr[currIndex]);

    return min(diff1, diff2);
}

// Recursive solution for min partition difference - But starting from last element
int minDfferenceLast(int arr[], int size, int currIndex, int set1, int set2) {

    if (currIndex < 0) {
        return abs(set1 - set2);
    }

    // include the element in set 1
    int diff1 = minDfferenceLast(arr, size, currIndex - 1, set1 + arr[currIndex], set2);
    // include the element in set 2
    int diff2 = minDfferenceLast(arr, size, currIndex - 1, set1, set2 + arr[currIndex]);

    return min(diff1, diff2);
}

int main(int argc, char *argv[]){
    int arr[]{1,5,6,11};
    int size = static_cast<int>(sizeof(arr)/sizeof(arr[0]));
    minDifference(arr,size,0,0,0);
    return 0;
}
