/*

AUTHOR - SAGAR SHARMA

DATE CREATED(dd/mm/yyy) - 26/01/2020

Question - 

An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than linear time.

If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique

*/

#include<iostream>

using namespace std;

int findMidPoint(int startIndex, int endIndex){
    return (startIndex+endIndex)/2;
}

// This function searches the element in the rotated array.
template<typename T> 
int findElement(T arr[], int size, T searchVal, int startIndex, int endIndex){
    cout<<"entered"<<endl;
    // Our base case
    if(startIndex == endIndex){
        if(arr[startIndex] == searchVal){
            return startIndex;
        }
        else{
            // Element not found in the array
            return -1;
        }
    }
    int mid = findMidPoint(startIndex,endIndex);
    if(searchVal == arr[mid]){
        return mid;
    }
    else if(searchVal > arr[startIndex] && searchVal < arr[mid]){
        return findElement(arr,size,searchVal,startIndex,mid-1);
    } 
    else{
        return findElement(arr,size,searchVal,mid+1,endIndex);
    }
}

int main(int argc, char *argv[]){
    //int arr[] = {5,6,7,8,9,10,1,2,3};
    int arr[] = {13, 18, 25, 2, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<findElement<int>(arr,size,8,0,size-1)<<endl;
    return 0;
}
