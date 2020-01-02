/*

AUTHOR - SAGAR SHARMA

DATE CREATED(DD/MM/YYYY) - 2/1/2020

DATE LAST MODIFIED(DD/MM/YYYY) - 2/1/2020

Question - 

You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width wall and the integer is the height. 

Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second,

and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.

*/

#include<iostream>

using namespace std;

int calcRainWater(int arr[], int size){
    int lo = 0;
    int hi = size-1;
    int loMax = 0;
    int highMax = 0;
    int rainWaterTrapped = 0;
    while(lo < hi){
        if(arr[lo] <= arr[hi]){
            if(arr[lo] > loMax){
                loMax = arr[lo];
            }
            else{
                rainWaterTrapped += (loMax - arr[lo]);
            }
            ++lo;
        }
        else if(arr[lo] > arr[hi]){
            if(arr[hi] > highMax){
                highMax = arr[hi];
            }
            else{
                rainWaterTrapped += (highMax - arr[hi]);
            }
            ++hi;
        }
    }
    return rainWaterTrapped;
}

int main(int argc, char *argv[]){
    int rainArray[] = {2,1,2};
    cout << calcRainWater(rainArray,sizeof(rainArray)/sizeof(rainArray[0]));
    return 0;
}
