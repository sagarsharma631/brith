#include<iostream>

using namespace std;

void findMaxContiguous(){
    int arr[] = {34,-50,42,14,-5,86};
    //int arr[] = {34,-33,18,90};
    int currSum = 0;
    int maxSum = 0;
    int minIndex = 0;
    int maxIndex = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;++i){
        currSum += arr[i];
        if(currSum < arr[i]){
            minIndex = i;
            currSum = arr[i];   
        }
        else if(currSum > arr[i]){
            // do nothing
        }
        if(currSum > maxSum){
            maxIndex = i;
            maxSum = currSum;
        }
    }
    cout<<"Max Sum starts at Index : "<<minIndex<<endl;
    cout<<"Max Sum ends at Index : "<<maxIndex<<endl;
    cout<<"Max Sum is : "<<maxSum<<endl;
    return;
}

int main(int argc, char *Argv[]){
    findMaxContiguous();
    return 0;
}
