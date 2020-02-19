/*

AUTHOR - SAGAR SHARMA

DATE - 19/02/2020

Question - 
Implement division of two positive integers without using the division, multiplication, or modulus operators. 

Return the quotient as an integer, ignoring the remainder.

*/
#include<iostream>

using namespace std;

int calcQuotient(const int &dividend, const int &divis){
    int divisor = divis;
    int count = 0;
    while(1){
        if(dividend > divisor){
            divisor <<= 1;
            ++count;
        }
        else if(dividend == divisor){
            ++count;
            break;
        }
        else{
            // Here dividend becomes greater than divisor, Hence break the loop.
            break;
        }
    }
    
    return count;
}

int main(int argc, char *argv[]){
    int dividend = 43;
    int divisor = 16;
    cout<<calcQuotient(dividend,divisor)<<endl;
    return 0;
}
