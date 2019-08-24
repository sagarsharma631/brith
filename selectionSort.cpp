#include<iostream>

using namespace std;

void swap(int &num1, int &num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}
//void selectionSort(int arr[], int size)
void selectionSort(int arr[], int size){
    int min;
    int index;
    for(int i=0;i<(size-1);i++){
        min = arr[i];
        for(int j=i+1;j<size;j++){
            if(arr[j] < min){
                index = j;
                min = arr[j];
            }
        }
        swap(arr[i],arr[index]);
    }
    return;
}

int main(int argc, char *argv[]){
    int arr[] = {70,65,8,97,6,71,53,64,17,22,17,6,97};
    int size = sizeof(arr)/sizeof(arr[0]);;
    selectionSort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
