#include<iostream>

using namespace std;

void Ksort(){
    int arr[] = {6,5,3,2,8,10,9};
    int size = sizeof(arr)/sizeof(arr[0]); 
    int k = 3;
    int sortArray[size] = {0};
    for(int i=0;i<k+1;i++){
        minHeap.add(a[i]);
    }
    
    for(int j=k+1;j<=size;j++){
        sortArray[j - (k+1)] = minHeap.pop();
        minHeap.add(arr[j]);
    }
    
    return;
}

int main(int argc, char *argv[]){
    Ksort();
    return 0;
}
