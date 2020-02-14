/*

AUTHOR - SAGAR SHARMA

DATE - 14/2/2020

Question - 
Calcualte maximum sum in an array(containing all numbers >= 0), the sum should not includ adjacent numbers.
e.g.  {1,2,9,4,5,0,4,11,6};
o/p - 26
*/
#include<iostream>

using namespace std;

namespace genericUtils{
    template<typename T>
    T max(T first, T second){
        return (first >= second)?first:second;
    }
}

int findMax(int arr[], int currIndex, int maxIndex){
    if(currIndex >= maxIndex){
        return 0;
    }
    int first = findMax(arr,currIndex+2,maxIndex);
    int second = findMax(arr,currIndex+3,maxIndex);
    
    return genericUtils::max<int>(first+arr[currIndex],second+arr[currIndex]);
}

int main(int argc, char *argv[]){
    //int arr[] = {1,2,9,4,5,0,4,11,6};
    //int arr[] = {5,1,1,5};
    int arr[] = {2,4,6,2,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    // Here index starts with 0
    cout<<genericUtils::max<int>(findMax(arr,0,size),findMax(arr,1,size));
    return 0;
}
