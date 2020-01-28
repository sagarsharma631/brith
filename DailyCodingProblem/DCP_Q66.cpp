/*

AUTHOR -  SAGAR SHARMA

DATE(DD/MM/YYYY) - 28/01/2020

Question-
Assume you have access to a function toss_biased() which returns 0 or 1 with a probability ,

that's not 50-50 (but also not 0-100 or 100-0). You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.

*/

#include<iostream>

using namespace std;

bool toss_biased(){
    
}

/* The following algorithm works because for each 100 times a coin is tossed, we will get a 0 followed by 1 or a 1 followed by 0, 
  Hence these events are equally likely.*/
bool tossFairCoin(){
    bool firstToss = toss_biased();
    bool secondToss = toss_biased();
    
    // firstToss = 0 and secondToss = 1, will give 0
    if((firstToss == 0) && (secondToss == 1)){
        return 0;
    }
    
    // firstToss = 1 and secondToss = 0, will give 1
    if((firstToss == 0) && (secondToss == 1)){
        return 1;
    }
    
    // if we didn't same values in both the tosses, the coin is biased, Hence recurse until we achieve it.
    return tossFairCoin();
}

int main(int argc, char *argv[]){
    // gives unbiased result after calling a biased method.
    tossFairCoin();
    return 0;
}
