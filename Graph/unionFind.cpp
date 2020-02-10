#include"unionFind.hpp"

unionFindUtil* unionFindUtil::m_ptr;

unionFindUtil::unionFindUtil(){

}

void unionFindUtil::initHashArray(int *ptr, int size){
    for(int i = 0;i < size; i++){
        ptr[i] = i;
    }
    return;
}

unionFindUtil* unionFindUtil::getInstance(){
    if(!m_ptr){
        m_ptr = new unionFindUtil();
    }
    return m_ptr;
}

void unionFindUtil::setHashArray(int *ptr, int size){
    if(!ptr || size == 0){
        return;
    }
    initHashArray(ptr,size);
    m_hashArray = ptr;
}
int unionFindUtil::findParent(char ref){
    int index = graphUtils::getInstance()->convertCharToIndex(ref);
    if(m_hashArray[index] == index){
        return index;
    }
    else{
        while(m_hashArray[index] != index){
            index = m_hashArray[index];
        }
    }
    return index;
}

// This makes
bool unionFindUtil::doUnion(const graphNode &graphEdge){
    int parentFNode = findParent(graphEdge.edge.first);
    int parentSNode = findParent(graphEdge.edge.second);
    if(parentFNode == parentSNode){
        // The edge if added creates a cycle.
        return false;
    }
    else{
        // Doing union of both the groups.
        m_hashArray[parentFNode] = parentSNode;
        return true;
    }
}
unionFindUtil::~unionFindUtil(){

}

// int main(int argc, char *Argv[]){
//     return 0;
// }
