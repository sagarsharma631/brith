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

char indexToAlph(int s){
    int retVal = 0;
    
    switch(s){
        case 0:
            retVal = 'a';
            break;
        case 1:
            retVal = 'b';
            break;
        case 2:
            retVal = 'c';
            break;
        case 3:
            retVal = 'd';
            break;
        case 4:
            retVal = 'e';
            break;
        case 5:
            retVal = 'f';
            break;
        case 6:
            retVal = 'g';
            break;
        case 7:
            retVal = 'h';
            break;
        case 8:
            retVal = 'i';
            break;
        case 9:
            retVal = 'j';
            break;
        case 10:
            retVal = 'k';
            break;
        case 11:
            retVal = 'l';
            break;
        case 12:
            retVal = 'm';
            break;
        case 13:
            retVal = 'n';
            break;
        case 14:
            retVal = 'o';
            break;
        case 15:
            retVal = 'p';
            break;
        case 16:
            retVal = 'q';
            break;
        case 17:
            retVal = 'r';
            break;
        case 18:
            retVal = 's';
            break;
        case 19:
            retVal = 't';
            break;
        case 20:
            retVal = 'u';
            break;
        case 21:
            retVal = 'v';
            break;
        case 22:
            retVal = 'w';
            break;
        case 23:
            retVal = 'x';
            break;
        case 24:
            retVal = 'y';
            break;
        case 25:
            retVal = 'z';
            break;    
    };
    
    return retVal;
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
