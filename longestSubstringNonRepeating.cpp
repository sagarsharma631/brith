#include<iostream>
#include<queue>

using namespace std;

int alphToIndex(char s){
    int retVal = 0;
    
    switch(s){
        case 'a':
            retVal = 0;
            break;
        case 'b':
            retVal = 1;
            break;
        case 'c':
            retVal = 2;
            break;
        case 'd':
            retVal = 3;
            break;
        case 'e':
            retVal = 4;
            break;
        case 'f':
            retVal = 5;
            break;
        case 'g':
            retVal = 6;
            break;
        case 'h':
            retVal = 7;
            break;
        case 'i':
            retVal = 8;
            break;
        case 'j':
            retVal = 9;
            break;
        case 'k':
            retVal = 10;
            break;
        case 'l':
            retVal = 11;
            break;
        case 'm':
            retVal = 12;
            break;
        case 'n':
            retVal = 13;
            break;
        case 'o':
            retVal = 14;
            break;
        case 'p':
            retVal = 15;
            break;
        case 'q':
            retVal = 16;
            break;
        case 'r':
            retVal = 17;
            break;
        case 's':
            retVal = 18;
            break;
        case 't':
            retVal = 19;
            break;
        case 'u':
            retVal = 20;
            break;
        case 'v':
            retVal = 21;
            break;
        case 'w':
            retVal = 22;
            break;
        case 'x':
            retVal = 23;
            break;
        case 'y':
            retVal = 24;
            break;
        case 'z':
            retVal = 25;
            break;    
    };
    
    return retVal;
}

void longestSubString(char str[]){
    
    int count = 0;
    int hashArr[26];
    queue<int> q;
    
    for(int i=0;i<26;i++){
        hashArr[i] = 0;
    }
    while(str[count] != '\0'){
        int index = alphToIndex(str[count]);
        if(hashArr[index] != 0){
            while(!q.empty()){
                int tempIndex = q.front();
                q.pop();
				hashArr[alphToIndex(str[tempIndex])] = 0;
                cout<<str[tempIndex]<<" ";
            }
        }
        else if(hashArr[index] == 0){
            q.push(count);
            hashArr[index] = 1;
        }
        ++count;
    }
}

int main(int argc, char *argv[]){
    char str[] = "geeksforgeeks";
    longestSubString(str);
	cout<<endl;
    return 0;
}
