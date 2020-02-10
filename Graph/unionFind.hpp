#ifndef UNION_FIND_ALGO
#define UNION_FIND_ALGO

// The following utility does not make use path compression.

#include<iostream>
#include"graphUtils.hpp"

using namespace std;

// Following class is a singleton class. Hence no this pointer
class unionFindUtil{
    private:
    
    // private Member Variables
    static unionFindUtil *m_ptr;
    int *m_hashArray;
    /*This variable is very important. It actually gets reset every time when a new hashArray is set.
     This helps us to know if a user is trying to perform operations on new graph without closing the opearions on the previous graph.*/
    bool canProceed;
    // private Member functions
    unionFindUtil();
    unionFindUtil(const unionFindUtil &other) = delete;
    void initHashArray(int *ptr, int size);

    public:
    static unionFindUtil* getInstance();
    void setHashArray(int *ptr, int size);
    int findParent(char ref);
    bool doUnion(const graphNode &graphEdge);
    ~unionFindUtil();
    protected:
};

#endif
