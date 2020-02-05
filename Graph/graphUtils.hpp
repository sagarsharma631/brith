#ifndef GRAPH_UTILS
#define GRAPH_UTILS

#include<iostream>
#include<vector>
#include<stack> // This file is included because of depthFirstSearch 
#include<queue> // This file is included because of breadthFirstSearch
#include"matrix.hpp"

using namespace std;

enum MST_ALGO{
    MST_ALGO_NONE = 0,
    MST_ALGO_KRUSKAL,   // Makes use of quick sort and union find algoritm.
    MST_ALGO_PRIM,  // Makes use of min heap.
};

// The below structure is actually an edge.
struct graphNode{
    pair<char,char> edge;   // This is an edge having two characters on each side.
    int weight;     // This is the weight of an edge.
    graphNode(const pair<char,char> &ref, const int &wght = 0){
        edge = ref;
        weight = wght;
    }
    graphNode& operator=(const graphNode &other){
        this->edge.first = other.edge.first;
        this->edge.second = other.edge.second;
        this->weight = other.weight;
        return *this;
    }
};

template<typename T>
class matrix;

class graphUtils{
    private:
    static graphUtils *m_ptr;
    graphUtils();
    void quickSort(vector<struct graphNode> &vec,int __beg,int __end, bool(*compPtr)(int,int));
    public:
    static graphUtils* getInstance();
    int convertCharToIndex(char ch);
    char convertIndexToChar(int index);
    // The following method is for sorting the edges of a graph in ascending order of their weight. The following method makes used of quick sort.
    void sortEdges(vector<graphNode> &vec, bool(*)(int,int));

    template<typename T>
    void swap(T &, T &);

    template<typename T>
    void dispMatrix(matrix<T> &mat){
        int rows = mat.getRows();
        int cols = mat.getCols();
        for(int i = 0;i<cols;++i){
            for(int j = 0;j<rows;++j){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    /* The following method takes a adjecency matrix and searches for an elment within it. Please mind that it only searches for an 
    element within the graph, It does not guarantee you a shortest path to find it, However it may result in same but does not guarantee
    it.*/
    void depthFirstSearch(matrix<int> &mat, const char &currentNode, const char &searchRef);

    void breadthFirstSearch(const matrix<int> &mat, const char &searchRef);
};

#endif
