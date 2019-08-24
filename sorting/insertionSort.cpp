#include<iostream>

using namespace std;

void swap(int &num1, int &num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}

void insertionSort(int a[], int size){
    int i = 1;
    int j,temp;
    while(i <= (size - 1)){
        j = i - 1;
        temp = i;
        while(j >= 0){
            if(a[temp] < a[j]){
                swap(a[temp],a[j]);
                --temp;
            }
            else if(a[temp] >= a[j]){
                break;
                // do nothing
            }
            --j;
        }
        ++i;
    }
    return;
}

int main(int argc, char *argv[]){
    int arr[] = {70,65,8,6,7,97,71,53,64,17};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
