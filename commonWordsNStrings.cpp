/* 

    Input : "The Kalmyks exile lasted 13 years",
        "The accusation levelled against Kalmyks"
        "The 90,000 Kalmyks to Siberia"
        "The feeling of Kalmyks collective guilt"
Output : The Kalmyks

Input : "Dog is Man's Best Friend"
        "Dog is Loyal"
        "Dog is faithful animal"
        "Dog is known since ages" 
Output : Dog is

*/

/*
    The idea to print common words from n given sentences is as follows -
1. Create a map<string, int>(string is word, int represents whether present in nth string).
2. Start traversing the strings alphabet by alphabet, insert the alphabets a temp string.
3. As a " "(space) is encountered in a string, insert the temp string in a map and increment by one.
4. Traverse the map and print all the strings where correponding int value is n-1(n represents total number of strings).
NOTE :  The below program is case-sensitive("This" is not equal to "this") 


*/

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int countCommonWords(string stringArr[], int size){
    int index = 0;
    
    int count = 0;
    
    string temp;
    unordered_map<string, int> m;

    for(int i = 0;i<size;i++){
        while(stringArr[i][index] != '\0'){
            if(stringArr[i][index] == ' '){
                if(m[temp] != i){
                    m[temp] += 1;
                }
                temp.clear();
            }
            else{
                temp.push_back(stringArr[i][index]);
            }
            ++index;
        }
        m[temp] += 1;
        temp.clear();
        index = 0;
    }

    for (auto it = m.begin(); it != m.end(); it++){
        if(it->second == (size-1)){
            cout<<it->first<<" ";
        }
    }  
}

int main(int argc, char *argv[]){
    string stringArr[] = {
        "The The Kalmyks exile lasted 13 years",
        "The accusation levelled against Kalmyks",
        "The 90,000 Kalmyks to Siberia",
        "The feeling of Kalmyks collective guilt",
    };

    int n = sizeof(stringArr)/sizeof(stringArr[0]);

    countCommonWords(stringArr, n);

    cout<<endl;
    return 0;
}
