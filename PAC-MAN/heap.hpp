#ifndef HEAP_CLASS_H
#define HEAP_CLASS_H

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
    inline int getParent(int index) const;

    // Returns the index of leftchild of element.
    inline int getLeftChild(int index) const;

    // Returns the index of rightchild of element.
    inline int getRightChild(int index) const;

    void percolateDown();

    void percolateDownMin(int index = 0);

    void percolateDownMax(int index = 0);

    void heapify(int index);

    void percolateUpMin(int index);

    void percolateUpMax(int index);

    public:
    heap(HeapType __heapType = HEAP_MIN, int *__array = 0, int __size = 0): m_heapType(__heapType), m_pArray(__array), m_size(__size){

    }

    // Following method creates heap from the array present above.
    void createHeap();

    int getMax() const;

    int getMin() const;

    // Pops the minimum element from heap. Throws an exception if Min is extracted from MAX_HEAP
    int popMin();

    // Pops the max element from the heap. Throws an exception if Max is extracted from MIN_HEAP
    int popMax();

    ~heap();
};

#endif
