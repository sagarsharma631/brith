#include<iostream>

struct utilJOB{
    uint8_t arrivalTime;
    uint32_t burstTime;
    explicit utilJOB(int __arrival, int __burst):
    arrivalTime(__arrival),
    burstTime(__burst){
        
    }
};

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

bool shouldSwapDecreasing(int arrElem, int pivot){
    bool retVal = false;
    if(arrElem > pivot){
        retVal = true;
    }
    return retVal;
}

int main(int argc, char *argv[]){
    int arr[] = {5, 20,	7,	12,	20,	1,	15,	8,	3, 4};
    int arr2[] = {4,10,8,7,6,5,3,12,14,2};
    int size = sizeof(arr2)/sizeof(arr2[0]);
    quickSort(arr2,0,size-1,shouldSwapDecreasing);
    for(int i=0;i<size;i++){
        std::cout<<arr2[i]<<" ";
    }
    return 0;
}