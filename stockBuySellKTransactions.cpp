#include<iostream>

using namespace std;

void trackKTransactions(int arr[], int totTrans, int num){
    int j = totTrans - 1;
    if(arr[0] == 0){
        arr[0] = num;
    }
    else{
        while(j >= 0){
            if(arr[j] > num){
                --j;
            }
            else if(arr[j] < num){
                arr[j] = num;
                break;
            }
            else{
                break;
            }
        }    
    }
    return;
}

void calcProfitMax(int KArray[], int totTrans){
    int arr[] = {90, 80, 70, 60, 50};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i = 1;
    int sum = 0;
    while(i<size){
        if(arr[i] > arr[i - 1]){
            sum += (arr[i] - arr[i-1]);
        }
        else{
            trackKTransactions(KArray, totTrans, sum);
            sum = 0;
        }
        ++i;
    }
    trackKTransactions(KArray, totTrans, sum);
    return;
}

int main(int argc, char *argv[]){
    int k,sum = 0;
    cout<<"Enter the max number of transactions"<<endl;
    cin>>k;
    int arr[k] = {0};
    calcProfitMax(arr, k);
    for(int i=0;i<k;i++){
        sum +=arr[i];
    }
    cout<<sum<<endl;
    return 0;
}
