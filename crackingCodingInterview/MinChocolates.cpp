#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(int &f,int &sec){
    int temp = f;
    f = sec;
    sec = temp;
    return;
}

void quickSort(int arr[],int __beg,int __end, bool(*compPtr)(int,int)){
    if((__beg > __end) || (__beg == __end)){
        return;
    }
    int index1 = 0;
    int index2 = 0;
    int pivot = arr[__end];
    for(int i=0;i<__end;i++){
        if(compPtr(arr[i],pivot)){
            swap(arr[index1],arr[index2]);
            ++index1;
            ++index2;
        }
        else if(!compPtr(arr[i],pivot)){
            ++index2;
        }
    }
    swap(arr[index1],arr[__end]);
    quickSort(arr,__beg,index1-1,compPtr);
    quickSort(arr,index1+1,__end,compPtr);
    return;
}

bool shouldSwapIncreasing(int arrElem, int pivot){
    bool retVal = false;
    if(arrElem < pivot){
        retVal = true;
    }
    return retVal;
}

// int children  - window size 
void calcMinDifferenceChocolate(int arr[], int size, int children, int &start, int &end){
    // there is only one possibility
    if(children >= size){
        return;
    }
    int minTillNow; // Set this to INT_MAX
    --children; // calculating exact window size.
    for(int i=0;i<size;++i){
        if(minTillNow > (arr[i+children] - arr[i])){
            minTillNow = arr[i+children] - arr[i];
            start = i;
            end = i+children;
        }
    }
    return;
}

int main(int argc, char *argv[]){
    int arr[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1,shouldSwapIncreasing);
    int start=0,end=0;
    calcMinDifferenceChocolate(arr,size,5,start,end);
    cout<<"Distribution chocoloates start Index : "<<start<<"end Index : "<<end<<endl;
    return 0;
}
