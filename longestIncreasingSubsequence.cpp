#include<iostream>

using namespace std;

int showLCS(){
    int arr[] = {10,22,9,33,21,50,41,60,80};
    int arrSize = sizeof(arr)/sizeof(int);
    int dp[9] = {0};
    dp[0] = 1;
    int j = 0;
    int max = 0;
    for(int i=1;i<arrSize;i++){
        
        while(i != j){
            if(arr[j] < arr[i]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            ++j;
        }
        if(dp[i] > max){
            max=dp[i];
        }
        j = 0;
    }
    
    return max;
}

int main(int argc, char *argv[]){
    cout<<showLCS()<<endl;
    return 0;
}
