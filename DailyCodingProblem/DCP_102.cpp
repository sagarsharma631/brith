/*
AUTHOR - SAGAR SHARMA

DATE - 04/03/2020

Question - Given a list of integers and a number K, return which contiguous elements of the list sum to K.
*/
#include<iostream>

using namespace std;

pair<int,int> contiguousElementsSum(int arr[], int size, int k){
    pair<int,int> temp(0,0);
    int sum = 0;
    int index = 0;
    for(int i=0;i<size;++i){
        sum += arr[i];
        if(sum > k){
            while(sum > k){
                sum -= arr[index];
                ++index;
            }
        }
        if(sum == k){
            temp.first = index;
            temp.second = i;
            return temp;
        }
        
    }
    return temp;
}

int main(int argc, char *argv[]){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    pair<int,int> result = contiguousElementsSum(arr,size,15);
    cout<<"Intended Sum Index starts at : "<<result.first<<" ends at : "<<result.second;
    return 0;
}
