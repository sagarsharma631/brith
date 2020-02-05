#include"graphUtils.hpp"

graphUtils* graphUtils::m_ptr = NULL;

graphUtils::graphUtils(){

}

graphUtils* graphUtils::getInstance(){
    if(!m_ptr){
        m_ptr = new graphUtils();
    }
    return m_ptr;
}

int graphUtils::convertCharToIndex(char ch){
    return ch - 'A';
}

char graphUtils::convertIndexToChar(int index){
    return static_cast<char>('A' + index);
}

template<typename T>
void graphUtils::swap(T &f,T &sec){
    T temp = f;
    f = sec;
    sec = temp;
    return;
}

void graphUtils::quickSort(vector<struct graphNode> &vec,int __beg,int __end, bool(*compPtr)(int,int)){
    if((__beg > __end) || (__beg == __end)){
        return;
    }
    int index1 = 0;
    int index2 = 0;
    int pivot = vec[__end].weight;
    for(int i=0;i<__end;i++){
        if(compPtr(vec[i].weight,pivot)){
            swap(vec[index1],vec[index2]);
            ++index1;
            ++index2;
        }
        else if(!compPtr(vec[i].weight,pivot)){
            ++index2;
        }
    }
    swap(vec[index1],vec[__end]);
    quickSort(vec,__beg,index1-1,compPtr);
    quickSort(vec,index1+1,__end,compPtr);
    return;
}

void graphUtils::sortEdges(vector<graphNode> &vec, bool(*compPtr)(int,int)){
    quickSort(vec,0,vec.size()-1,compPtr);
    return;
}

void graphUtils::depthFirstSearch(matrix<int> &mat, const char &currentNode, const char &searchRef){
    if(currentNode == searchRef){
        return;
    }
    for(int i=convertCharToIndex(currentNode);i<mat.getRows();++i){
        for(int j=0;j<mat.getCols();++j){
            if(mat[i][j] != 0){
                depthFirstSearch(mat, convertIndexToChar(j), searchRef);
            }
        }
    }
    return;
}

void graphUtils::breadthFirstSearch(const matrix<int> &mat, const char &searchRef){
    return;
}

// template<typename T>
// void graphUtils::dispMatrix(matrix<T> &mat){

// }

// int main(int argc, char *Argv[]){
//     return 0;
// }
