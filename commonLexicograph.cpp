#include<iostream>

using namespace std;

int min(int a,int b){
    if(a!=b){
        return (a>b)?b:a;
    }
    else{
        return a;
    }
}

int alphToIndex(char s){
    int retVal = 0;

    retVal = (s - 'a');
    
    return retVal;
}

char indexToAlph(int s){
    return char(s + 'a');
}

void printCommonLexograph(){
    
    char str1[] = "geeks";
    char str2[] = "forgeeks";
    
	int hashArr1[26];
	int hashArr2[26];
	
	for(int i = 0;i < 26;i++){
        hashArr1[i] = 0;
		hashArr2[i] = 0;
    }
	
	int count = 0;
    int index = 0;
	
    while(str1[count] != '\0'){
        index = alphToIndex(str1[count]);
        ++hashArr1[index];
        ++count;
    }
	
	count = 0;
	
	while(str2[count] != '\0'){
        index = alphToIndex(str2[count]);
		++hashArr2[index];
        ++count;
    }
	
	for(int i=0;i<26;i++){
		if(hashArr1[i] == 0 || hashArr2[i] == 0){
			continue;
		}
		else{
			int printTimes = min(hashArr1[i],hashArr2[i]);
			for(int j=0;j<printTimes;j++){
				cout<<indexToAlph(i)<<" ";
			}
		}
	}
	
	return;
}

int main(int argc, char *argv[]){
	printCommonLexograph();
	cout<<endl; 
    return 0;
}
