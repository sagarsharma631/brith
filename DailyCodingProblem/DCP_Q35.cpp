/*

AUTHOR - SAGAR SHARMA

DATE CREATED(dd/mm/yyyy) - 28/12/2019

LAST MODIFIED(dd/mm/yyyy) - 28/12/2019

Ques - Given an array of strictly the characters 'R', 'G', and 'B', 

segregate the values of the array so that all the Rs come first,

the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

NOTE : This problem is also known as Dutch National Flag Problem.

*/

#include<iostream>

template <typename T>
void swap(T &first, T &second){
    T temp;
    temp = first;
    first = second;
    second = temp;
    return;
}

template <typename T>
void sortArray(T arr[], int size){
    int j = 0;
    int i = 0;
    bool shouldSwap = false;
    for(i=0;i<size;++i){
        if(arr[i] == 'R'){
            swap<char>(arr[i],arr[j]);
            ++j;
        }
    }

    i = size-1;
    j = size-1;
    while(arr[i] != 'R'){
        if(arr[i] == 'B'){
            swap(arr[i],arr[j]);
            --j;
        }
        --i;
    }

    return;
}

int main(int argc, char *argv[]){
    char arr[] = {'G','B','R','R','B','R','G'};
    int size = sizeof(arr)/sizeof(arr[0]);
    sortArray<char>(arr,size);

    for(int i=0;i<size;++i){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<std::endl;

    return 0;
}
