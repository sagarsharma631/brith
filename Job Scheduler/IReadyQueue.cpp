//
//  IReadyQueue.cpp
//  ShortTermScheduler
//
//  Created by Sagar Sharma on 12/03/23.
//

#include "IReadyQueue.hpp"

void FCFSQueue::initExecute(int lo, int hi){
    // Variant of quicksort - sorts the jobs on the basis of burst time.
    if(hi <= lo){
        return;
    }
    int i=0;
    int j=0;
    while(j < hi){
        if(m_jobs[j].m_arrival < m_jobs[hi].m_arrival){
            std::swap(m_jobs[i],m_jobs[j]);
            ++i;
        }
        ++j;
    }
    std::swap(m_jobs[i], m_jobs[hi]);
    initExecute(lo,i-1);
    initExecute(i+1,hi);
    return;
}

void FCFSQueue::initialize(){
    initExecute(0, static_cast<int>(m_jobs.size())-1);
    for(auto iter : m_jobs){
        push(iter);
    }
    return;
}

void FCFSQueue::push(struct job obj){
    readyQ.push(obj);
    return;
}

struct job FCFSQueue::pop(){
    if(!readyQ.empty()){
        struct job current = readyQ.front();
        readyQ.pop();
        return current;
    }
    else{
        assert(0);
    }
}

void SJFQueue::initialize(){
    for(auto iter : m_jobs){
        readyQ.push(iter);
    }
    return;
}

void SJFQueue::push(struct job obj){
    readyQ.push(obj);
    return;
}

struct job SJFQueue::pop(){
    struct job current = readyQ.top();
    readyQ.pop();
    return current;
}
