#include"Heap.hpp"

inline int heap::getParent(int index) const{
    return (index-1) >> 1;
}

// Returns the index of leftchild of element.
inline int heap::getLeftChild(int index) const{
    return (index << 1) + 1;
}   

// Returns the index of rightchild of element.
inline int heap::getRightChild(int index) const{
    return (index << 1) + 2;
}

void heap::percolateDown(){
    switch(m_heapType){
        case HEAP_MIN:
            percolateDownMin();
            break;
        case HEAP_MAX:
            percolateDownMax();
            break;   
    }        
}

void heap::percolateDownMin(int index){
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

void heap::percolateDownMax(int index){
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

void heap::heapify(int index){
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

void heap::percolateUpMin(int index){
    if(index == 0 || m_pArray[getParent(index)] < m_pArray[index]){
        return;
    }
    utilityMethods::getInstance()->utilSwap(m_pArray[index], m_pArray[getParent(index)]);
    percolateUpMin(getParent(index));
}

void heap::percolateUpMax(int index){
    if(index == 0 || m_pArray[getParent(index)] > m_pArray[index]){
        return;
    }
    utilityMethods::getInstance()->utilSwap(m_pArray[index], m_pArray[getParent(index)]);
    percolateUpMax(getParent(index));
}

// Following method creates heap from the array present above.
void heap::createHeap(){    
    for(int i=0;i<m_size;i++){
        if(i != 0){
            heapify(i);           
        }
    }
}

int heap::getMax() const{
    if(m_heapType == HEAP_MAX){
        return *m_pArray;
    }
    else{
        throw "Not Max heap";
    }
}

int heap::getMin() const{
    if(m_heapType == HEAP_MIN){
        return *m_pArray;
    }
    else{
        throw "Not Min heap";
    }
}

// Pops the minimum element from heap. Throws an exception if Min is extracted from MAX_HEAP
int heap::popMin(){
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
int heap::popMax(){
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

heap::~heap(){
        // delete all the storage
}

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
