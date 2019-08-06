#include<iostream>

using namespace std;

enum HeapType{
    HEAP_MIN = 0,
    HEAP_MAX,
    HEAP_INVALID,
};

class utilityMethods{
    private:
    static utilityMethods *m_putilityMethods;
    utilityMethods(){

    }

    public:
    static utilityMethods* getInstance(){
        if(!m_putilityMethods){
            m_putilityMethods = new utilityMethods();
        }
        return m_putilityMethods;
    }

    void utilSwap(int &first, int &second){
        int temp; 
        temp = first;
        first = second;
        second = temp;
        return;
    }

    // Compares two quantities
    int utilMin(int &first, int &second){
        return (first < second)?first:second;
    }

    // Compares two quantities
    int utilMax(int &first, int &second){
        return (first > second)?first:second; 
    }

    // Returns index of the smaller element present at index1 and index2 of array pointed by __arr.
    int utilMinIndex(int *__arr, int __index1, int __index2){
        return (__arr[__index1] < __arr[__index2])?__index1:__index2;
    }

    // Returns index of the greater element present at index1 and index2 of array pointed by __arr.
    int utilMaxIndex(int *__arr, int __index1, int __index2){
        return (__arr[__index1] > __arr[__index2])?__index1:__index2;
    }
};

utilityMethods* utilityMethods::m_putilityMethods = NULL;

class heap{
    private:

    // Member Variables
    HeapType m_heapType;
    int *m_pArray;
    int m_size;

    // Member Functions
    inline int getParent(int index) const{
        return (index-1) >> 1;
    }

    // Returns the index of leftchild of element.
    inline int getLeftChild(int index) const{
        return (index << 1) + 1;
    }

    // Returns the index of rightchild of element.
    inline int getRightChild(int index) const{
        return (index << 1) + 2;
    }

    void percolateDown(){
        switch(m_heapType){
            case HEAP_MIN:
                percolateDownMin();
                break;
            case HEAP_MAX:
                percolateDownMax();
                break;   
        }        
    }

    void percolateDownMin(int index = 0){
        if(getRightChild(index) > m_size){
            return;
        }
        int minIndex = utilityMethods::getInstance()->utilMinIndex(m_pArray, getRightChild(index), getLeftChild(index));
        if(m_pArray[index] < m_pArray[minIndex]){
            return;
        }    
        utilityMethods::getInstance()->utilSwap(m_pArray[index],m_pArray[minIndex]);
        percolateDownMin(minIndex);
    }

    void percolateDownMax(int index = 0){
        if(getRightChild(index) > m_size){
            return;
        }
        int maxIndex = utilityMethods::getInstance()->utilMaxIndex(m_pArray, getRightChild(index), getLeftChild(index));
        if(m_pArray[index] > m_pArray[maxIndex]){
            return;
        }
        utilityMethods::getInstance()->utilSwap(m_pArray[index],m_pArray[maxIndex]);
        percolateDownMax(maxIndex);                
    }

    void heapify(int index){
        switch(m_heapType){
            case HEAP_MIN:
                if(m_pArray[index] < m_pArray[getParent(index)]){
                    percolateUpMin(index);
                }
                break;
            case HEAP_MAX:
                if(m_pArray[index] > m_pArray[getParent(index)]){
                    percolateUpMax(index);
                }
                break;
        }
    }

    // void percolateUp(int index){
    //     switch(m_heapType){
    //         case HEAP_MIN:
    //             percolateUpMin(index);
    //             break;
    //         case HEAP_MAX:
    //             percolateUpMax(index);
    //             break;   
    //     }
    // }

    void percolateUpMin(int index){
        if(index == 0 || m_pArray[getParent(index)] < m_pArray[index]){
            return;
        }
        utilityMethods::getInstance()->utilSwap(m_pArray[index], m_pArray[getParent(index)]);
        percolateUpMin(getParent(index));
    }

    void percolateUpMax(int index){
        if(index == 0 || m_pArray[getParent(index)] > m_pArray[index]){
            return;
        }
        utilityMethods::getInstance()->utilSwap(m_pArray[index], m_pArray[getParent(index)]);
        percolateUpMax(getParent(index));
    }

    public:
    heap(HeapType __heapType = HEAP_MIN, int *__array = 0, int __size = 0): m_heapType(__heapType), m_pArray(__array), m_size(__size){

    }

    // Following method creates heap from the array present above.
    void createHeap(){
    
        for(int i=0;i<m_size;i++){
            if(i != 0){
                heapify(i);           
            }
        }
    }

    int getMax() const{
        if(m_heapType == HEAP_MAX){
            return *m_pArray;
        }
        else{
            throw "Not Max heap";
        }
    }

    int getMin() const{
        if(m_heapType == HEAP_MIN){
            return *m_pArray;
        }
        else{
            throw "Not Min heap";
        }
    }

    // Pops the minimum element from heap. Throws an exception if Min is extracted from MAX_HEAP
    int popMin(){
        if(m_heapType == HEAP_MIN){
            int retVal = m_pArray[0];
            m_pArray[0] = m_pArray[m_size - 1];
            percolateDownMin();
            return retVal;
        }
        else{
            throw "Not Min heap";
        }        
    }

    // Pops the max element from the heap. Throws an exception if Max is extracted from MIN_HEAP
    int popMax(){
        if(m_heapType == HEAP_MAX){
            int retVal = m_pArray[0];
            m_pArray[0] = m_pArray[m_size - 1];
            percolateDownMax();
            return retVal;
        }
        else{
            throw "Not Max heap";
        }
    }

    ~heap(){
        // delete all the storage
    }
};

int main(int argc, char *argv[]){
    int arr[] = {3,12,2,18,5,15,6,7,10,13};
    int size = sizeof(arr)/sizeof(int);
    heap h(HEAP_MAX,arr,size);
    h.createHeap();
    try{
       h.popMax();
    }
    catch(const char *exception){
        cerr << "Error : Could Not show popped element due to - "<< exception<<endl;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}   
