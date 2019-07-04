#include<iostream>

using namespace std;

void swap(int *ptr1,int *ptr2){
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    return;
}

void seggregate(int *initptr, int *lastptr){

    int *ptr1 = initptr;
    int *ptr2 = lastptr;

    while(ptr1 != ptr2){
        
        if(*ptr1 != 0){
            if(*ptr2 == 0){
                swap(ptr1,ptr2);
                ++ptr1;
                --ptr2;
            }
        }
        else{
            ++ptr1;
        }
        
        if(*ptr2 != 1){
            if(*ptr1 == 1){
                swap(ptr1,ptr2);
                ++ptr1;
                --ptr2;
            }
        }
        else{
            --ptr2;
        }
    }
    
    return;
}

int main(int argc, char *argv[]){
    
    int arr[] = {0,1,0,1,0,0,1,1,1,0,1,1};
    
    int size = sizeof(arr)/sizeof(int);
    
    seggregate(arr,&arr[size - 1]);
    
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}
