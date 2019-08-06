#include<iostream>

using namespace std;

int alphToIndex(char s){
    int retVal = 0;
    retVal = (s - 'a');
    return retVal;
}

char indexToAlph(int s){
    return char(s + 'a');
}


void commonChars(string strArr[], int n){
    
    int hashArr[26];

    // Initializing the Hash Array
    for(int i=0;i<26;i++){
        hashArr[i] = -1;
    }

    int index = 0;

    for(int i=0;i<n;i++){ 
        
        while(strArr[i][index] != '\0'){
            int hashArrIndex = alphToIndex(strArr[i][index]);
            if(hashArr[hashArrIndex] != i){
                ++hashArr[hashArrIndex];
            }
            ++index;
        }
        // Reset the index
        index = 0;
    }

    for(int i = 0;i<26;i++){
        if(hashArr[i] == (n-1)){
            cout<<indexToAlph(i)<<" ";
        }
    }

    return;
}

int main(int argc, char *argv[]){
    string strArr[] = {
        "geeksforgeeks",
        "gemkstones",
        "acknowledges",
    };
    commonChars(strArr, sizeof(strArr)/sizeof(strArr[0]));
    cout<<endl;
    return 0;
}
