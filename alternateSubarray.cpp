// Length of the longest alternating subarray

#include<iostream>

using namespace std;

bool isAlternateIndex(int arr[], int index){
    bool result = false;
    if(arr[index] * arr[index+1] < 0){
        result = true;
    }
    return result;
}

int findLongestAlternate(){
	int arr2[] = {1, -5, 1, -5};
    int arr[] = {-5,-1,-1,2,-2,-3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int longest = 0;
    int windowLength = 0;
    
    for(int i=0;i<size;i++){
        if(isAlternateIndex(arr,i)){
            ++windowLength;
            if(windowLength > longest){
                longest = windowLength;
            }
        }
        else{
            windowLength = 0;
        }
    }
    return longest+1;
}

int main(int argc, char *argv[]){
    cout<<findLongestAlternate();
    return 0;
}
