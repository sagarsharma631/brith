/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 02/01/2020

DATE LAST MODIFIED - 02/01/2020

Given an array of integers where every integer occurs three times except for one integer,

which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.

*/

#include<iostream>

using namespace std;

void populateArrayOfSetBits(int bitArray[], int number){
    int mask = 0x01;
    for(int i=0;i<32;++i){
        mask <<= i;
        if((number & mask) == mask){
            // This means the bit is set.
            bitArray[i] += 1;
        }
        // Reset the bit mask
        mask = 0x01;
    }
    return;
}

int findNumberAppearingOnce(int arr[], int size){
    int missingNumber;
    int bitMask = 0x01;
    int bitArray[32] = {0};
    for(int i=0;i<size;++i){
        populateArrayOfSetBits(bitArray,arr[i]);    
    }
    for(int i=0;i<32;++i){
        if(bitArray[i]%3 != 0){
            missingNumber += (bitMask << i);
        }
        // Reset our bit mask
        bitMask = 0x01;
    }
    return missingNumber;
}

int main(int argc, char *argv[]){
    int arr[] = {6, 1, 3, 3, 3, 6, 6};
    cout << findNumberAppearingOnce(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}
