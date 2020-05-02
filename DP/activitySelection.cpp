/*
 *
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED(DD/MM/YYYY) - 02/05/2020
 *
 *	Question - Activity selection problem
 *
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std

bool sortActivity(const pair<int,int>& activity1, const pair<int,int>& activity2) {
    return (activity1.first <= activity2.first) ? true : false;
}

// This function merges the array based on the callback function present
template<typename T>
T* mergeArray(T arr[], int lo, int mid, int hi, bool (*func)(const T&, const T&)) {
    // Allocate the memory at heap for the merged array.
    T* merged = new T[(hi - lo) + 1];
    int lIndex = lo;
    int rIndex = mid + 1;
    int mergedIndex = 0;    // This index will keep track of the merged array.
    while (lIndex <= mid && rIndex <= hi) {
        /* The callback function decides which element to add in the merged array. It returns true if first is to be 
         inserted or false when second is to be inserted. */
        if (func(arr[lIndex], arr[rIndex])) {
            merged[mergedIndex] = arr[lIndex];
            ++lIndex;
        }
        else {
            merged[mergedIndex] = arr[rIndex];
            ++rIndex;
        }
        ++mergedIndex;
    }

    while (lIndex <= mid) {
        merged[mergedIndex] = arr[lIndex];
        ++mergedIndex;
        ++lIndex;
    }
    
    while (rIndex <= hi) {
        merged[mergedIndex] = arr[rIndex];
        ++mergedIndex;
        ++rIndex;
    }
    
    return merged;
}

// Merge Sort Implementation - Should make use of template and callback function.
template<typename T>
void mergerSort(T arr[], int lo, int hi, bool (*func)(const T&, const T&) = NULL) {
    if (!func) {
        // throw the exception asking to provide the callback function.
        throw("provide callback function");
    }
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        mergerSort<T>(arr, lo, mid, func);
        mergerSort<T>(arr, mid + 1, hi, func);
        T* merged = mergeArray(arr, lo, mid, hi, func);
        for (int i = lo; i <= hi; ++i) {
            arr[i] = merged[i - lo];
        }
        // Deallocate this memory or else memory leak.
        delete[] merged;
    }
    return;
}

bool doOverlap(const pair<int,int>& activity1, const pair<int,int>& activity2) {
    // The activities will only overlap when finish time of first activity is more than the start times of second activity.
    return (activity2.first < activity1.second) ? true : false;
}

// DP solution for Activity selection
int activitySelection(pair<int, int> activity[], int size) {

    // sort the array of activities before applying LIS. This sorts the array in ascending order of their start time.
    mergerSort<pair<int, int>>(activity, 0, size - 1, sortActivity);

    // create the DP array
    int* dpArray = new int[size];

    // set the base cases - you can also initialize to zero.
    for (int i = 0; i < size; ++i) {
        dpArray[i] = 1;
    }

    int maxVal = INT_MIN;

    // fill the DP table
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (!doOverlap(activity[j], activity[i])) {
                dpArray[i] = max(dpArray[i], dpArray[j] + 1);
            }
        }
        maxVal = max(maxVal, dpArray[i]);
    }

    // deallocate the memory
    delete[] dpArray;

    return maxVal;
}

int main(int argc, char* argv[]) {
    pair<int, int> activity[]{
        make_pair(1,4),
        make_pair(3,5),
        make_pair(0,6),
        make_pair(5,7),
        make_pair(3,8),
        make_pair(5,9),
        make_pair(6,10),
        make_pair(8,11),
        make_pair(8,12),
        make_pair(2,13),
        make_pair(12,14),
    };
    int size = static_cast<int>(sizeof(activity) / sizeof(activity[0]));
    int result = activitySelection(activity, size);
    return 0;
}
