#include<iostream>

using namespace std;

struct interval{
  struct interval *right;
  struct interval *left;
  int low;
  int high;
  int max;
};

bool searchIntersection(struct interval *currentInterval, struct interval *searchInterval){
    if(currentInterval == NULL){
        return false;
    }
    if((searchInterval->low > currentInterval->low) && (searchInterval->low < currentInterval->high)){
        return true;
    }

    if((currentInterval->left != NULL) && (currentInterval->left->max < searchInterval->low)){
        searchIntersection(currentInterval->right, searchInterval);
    }
    else{
        searchIntersection(currentInterval->left, searchInterval);
    }

    return false;
}

void addInterval(struct interval *currInterval, struct interval *insertInterval){
    
    if(insertInterval == NULL){
        return;
    }
    
    if(insertInterval->low < currInterval->low){
        if(currInterval->left != NULL){
            addInterval(currInterval->left, insertInterval);
        }
        else{
            currInterval->left = insertInterval;
        }
    }
    
    if(insertInterval->low > currInterval->low){
        if(currInterval->right != NULL){
            addInterval(currInterval->right, insertInterval);
        }
        else{
            currInterval->right = insertInterval;
        }
    }
    
    if(insertInterval->high > currInterval->max){
        currInterval->max = insertInterval->high;
    }
    
    return;
}



int main(int argc, char *argv[]){
    return 0;
}
