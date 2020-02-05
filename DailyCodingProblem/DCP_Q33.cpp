/*

AUTHOR - SAGAR SHARMA

DATE CREATED(dd/mm/yyyy) - 28/12/2019

LAST MODIFIED(dd/mm/yyyy) - 28/12/2019

Ques - Compute the running median of a sequence of numbers.

That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm

2
1.5
2
3.5
2
2
2 

*/

#include<iostream>

using namespace std;

namespace util{
    template <typename T>
    void swap(T &first, T &second){
        T temp;
        temp = first;
        first = second;
        second = temp;
        return;
    }
}


void calcMedianHeap(){
    
}

// The following method makes use of Insertion Sort Algorithm to calculate the running median of a stream of numbers.
void calcMedian(float arr[], int size){
    cout<<arr[0]<<endl;
    for(int i=1;i<size;++i){
        // Insert number at correct position.
        for(int j=i;j>0;--j){
            if(arr[j] < arr[j-1]){
                util::swap<float>(arr[j],arr[j-1]);
            }
            else if(arr[j] >= arr[j-1]){
                // we need to break the loop here, as this buddy is already largest.
                break;
            }
        }

        // Should see, If I have traversed odd/even number of elements till now.
        if((i+1)%2 == 0){
            cout<<(arr[i/2] + arr[i/2+1])/2<<endl;
        }
        else{
            cout<<arr[i/2]<<endl;
        }

    }
    return;
}

int main(int argc, char *argv[]){
    float arr[] = {2,1,5,7,2,0,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    calcMedian(arr,size);
    return 0;
}
