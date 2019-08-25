#include"utility.hpp"

using namespace utility;

utilJOB_DATA* utilJOB_DATA::m_ptr = nullptr;

utilJOB_DATA* utilJOB_DATA::getInstance(){
	if(m_ptr == NULL){
		m_ptr = new utilJOB_DATA;	
	}
	return m_ptr;
}

std::vector<struct utilJOB*>& utilJOB_DATA::createVec(int __size){
	std::vector<struct utilJOB*> *tempPtr = new std::vector<struct utilJOB*>(__size);
	return *tempPtr;
}

struct utilJOB* utilJOB_DATA::createJOB(std::string __jobID,int __arrivalTime, int __burstTime){
	struct utilJOB *ptr = new struct utilJOB(__jobID, __arrivalTime, __burstTime);
	return ptr;
}

void utilJOB_DATA::addJOB(std::vector<struct utilJOB*> &vec, struct utilJOB *__jobptr){
	vec.push_back(__jobptr);
	return;
}

/*bool utilJOB_DATA::canjobSwap(const struct utilJOB &job1, const struct utilJOB &job2){
    bool retVal = false;
    if(job1 < job2){
        retVal = true;
    }
    return retVal;
}*/

template<typename T>
void swap(T &f,T &sec){
    T temp = f;
    f = sec;
    sec = temp;
    return;
}

template<typename T>
void sortJOBS(std::vector<T*> arr,int __beg,int __end, bool(*compPtr)(const T&,const T&)){
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


int main(int argc, char *argv[]){
	return 0;
}
