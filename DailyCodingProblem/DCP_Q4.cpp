#include<iostream>

using namespace std;

namespace genericUtils{
    template<typename T>
    void swap(T &first, T &second){
        T temp;
        temp = first;
        first = second;
        second = temp;
        return;
    }
};

// This function seregates -v numbers, 0 to one side and +ve numbers to another.
int segregateArray(int arr[], int size){
    int negativeIndex = 0;
    for(int i=0;i<size;++i){
        if(arr[i] <= 0){
            genericUtils::swap(arr[i],arr[negativeIndex]);
            ++negativeIndex;
        }
    }
    return negativeIndex;
}

// Following function computes the smallest missing number.
int findSmallestMissing(int arr[], int size){
    int retVal = 0;
    cout<<arr[0]<<endl;
    return retVal;
}

int main(int argc, char *argv[]){
    int arr[] = { 2, 3, -7, 6, 8, 1, -10, 15 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int posIndexStart = segregateArray(arr,size);
    #ifdef DEBUG
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    #endif
    findSmallestMissing(arr+posIndexStart,size-posIndexStart);
    return 0;
}
