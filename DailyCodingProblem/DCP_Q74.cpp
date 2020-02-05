/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 05/01/2020 

Question - 
Suppose you have a multiplication table that is N by N. 

That is, a 2D array where the value at the i-th row and j-th column is (i + 1) * (j + 1) (if 0-indexed) or i * j (if 1-indexed).

Given integers N and X, write a function that returns the number of times X appears as a value in an N by N multiplication table.

For example, given N = 6 and X = 12, you should return 4, since the 

*/

#include<iostream>
#include<map>

using namespace std;

int countOccurences(int n, int x){
    int count = 0;
    for(int i=1;i<=n;++i){
        if((x%i == 0) && (x/i)<=n){
            ++count;
        }
    }
    return count;
}

int main(int argc, char *argv[]){
    cout<<countOccurences(6,12)<<endl;
    return 0;
}
