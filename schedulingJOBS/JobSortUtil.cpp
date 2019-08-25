#include<iostream>
#include<vector>
#include<string>

// The copy constructor and assignment operator does shallow copy, please provide a deep copy constructor and assignment operator in case any pointer member variable is added.
struct utilJOB{
    std::string m_procID;
    uint8_t m_arrivalTime;
    uint32_t m_burstTime;
    explicit utilJOB(std::string __id, int __arrival, int __burst):
    m_procID(__id),
    m_arrivalTime(__arrival),
    m_burstTime(__burst){
        
    }
    bool operator>(const utilJOB &other) const{
        return (this->m_arrivalTime > other.m_arrivalTime)?true:false;
    }

    bool operator<(const utilJOB &other) const{
        return (this->m_arrivalTime < other.m_arrivalTime)?true:false;
    }
};

template<typename T>
void swap(T &f,T &sec){
    T temp = f;
    f = sec;
    sec = temp;
    return;
}

template<typename T>
void quickSort(std::vector<T*> arr,int __beg,int __end, bool(*compPtr)(const T&,const T&)){
    if((__beg > __end) || (__beg == __end)){
        return;
    }
    int index1 = 0;
    int index2 = 0;
    struct utilJOB pivot = *arr[__end];
    for(int i=0;i<__end;i++){
        if(compPtr(*arr[i],pivot)){
            swap(*arr[index1],*arr[index2]);
            ++index1;
            ++index2;
        }
        else if(!compPtr(*arr[i],pivot)){
            ++index2;
        }
    }
    swap(*arr[index1],*arr[__end]);
    quickSort(arr,__beg,index1-1,compPtr);
    quickSort(arr,index1+1,__end,compPtr);
    return;
}

bool jobSwap(const struct utilJOB &job1, const struct utilJOB &job2){
    bool retVal = false;
    if(job1 < job2){
        retVal = true;
    }
    return retVal;
}

bool shouldSwapIncreasing(const int &arrElem,const int &pivot){
    bool retVal = false;
    if(arrElem < pivot){
        retVal = true;
    }
    return retVal;
}

bool shouldSwapDecreasing(const int &arrElem, const int &pivot){
    bool retVal = false;
    if(arrElem > pivot){
        retVal = true;
    }
    return retVal;
}

int main(int argc, char *argv[]){
    //int arr[] = {5, 20,	7,	12,	20,	1,	15,	8,	3, 4};
    //int arr2[] = {4,10,8,7,6,5,3,12,14,2};
    //int size = sizeof(arr2)/sizeof(arr2[0]);
    std::vector<struct utilJOB*> vec;
    vec.push_back(new struct utilJOB("P1",4,8));
    vec.push_back(new struct utilJOB("P2",3,4));
    vec.push_back(new struct utilJOB("P3",1,9));
    vec.push_back(new struct utilJOB("P4",2,5));
    int size = vec.size();
    quickSort<struct utilJOB>(vec,0,size-1,jobSwap);
    for(int i=0;i<size;i++){
        std::cout<<vec[i]->m_procID<<" ";
    }

    return 0;
}