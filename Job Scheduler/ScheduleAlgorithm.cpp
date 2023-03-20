//
//  ScheduleAlgorithm.cpp
//  ShortTermScheduler
//
//  Created by Sagar Sharma on 12/03/23.
//

#include "ScheduleAlgorithm.hpp"

void ShortTermSchedulingBase::execute(){
    std::cout<<"This is base execute"<<std::endl;
}

void ShortTermSchedulingBase::process(){
    m_rq->initialize();
    return;
}

ShortTermSchedulingFCFS::ShortTermSchedulingFCFS(std::vector<struct job>& jobs)
    :ShortTermSchedulingBase(jobs, new FCFSQueue(jobs)){
}

void ShortTermSchedulingFCFS::execute(){
    // Below function initializes the ready queue.
    process();
    
    // Below code generates report for user on how the jobs got executed.
    int i = m_rq->getSize();
    while(i > 0){
        struct job current = m_rq->pop();
        std::cout<<"PROCESS NAME : "<<current.m_name<<" ";
        std::cout<<"ARRIVAL TIME : "<<current.m_arrival<<" ";
        std::cout<<"BURST TIME : "<<current.m_burst<<std::endl;
        --i;
    }
    return;
}

ShortTermSchedulingFCFS::~ShortTermSchedulingFCFS(){
    
}

ShortTermSchedulingSJF::ShortTermSchedulingSJF(std::vector<struct job>& jobs)
    :ShortTermSchedulingBase(jobs, new SJFQueue(jobs)){
}

ShortTermSchedulingSJF::~ShortTermSchedulingSJF(){
    
}

void ShortTermSchedulingSJF::execute(){
    // Below function initializes the ready queue.
    process();
    
    // Below code generates report for user on how the jobs got executed.
    struct job current;
    /*while(m_scheduled.size() != m_jobs.size()){*/
    int i = 0;
    while(i < 10){
        current = m_rq->pop();
        std::cout<<"PROCESS NAME : "<<current.m_name<<" ";
        std::cout<<"ARRIVAL TIME : "<<current.m_arrival<<" ";
        std::cout<<"BURST TIME : "<<current.m_burst<<std::endl;
        // The current burst time will become
        int pastBurst = current.m_burst;
        // We can change the alpha from 0.5 to another weight as the scheduler progresses. Need to implement
        current.m_burst = 0.5 * current.m_pastBurst + 0.5 * current.m_burst;
        current.m_pastBurst = pastBurst;
        m_rq->push(current);
        m_scheduled.insert(current.m_name);
        ++i;
    }
    return;
}

ShortTermSchedulingSRTF::ShortTermSchedulingSRTF(std::vector<struct job>& jobs)
    :ShortTermSchedulingBase(jobs, new SRTFQueue(jobs)){
}

ShortTermSchedulingSRTF::~ShortTermSchedulingSRTF(){
    
}

void ShortTermSchedulingSRTF::executeInit(int lo, int hi){
    // Variant of quicksort - sorts the jobs on the basis of arrival time.
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
    executeInit(lo,i-1);
    executeInit(i+1,hi);
    return;
}

void ShortTermSchedulingSRTF::execute(){
    /*
        The scheduling works in the following way -
        1. Sorts the jobs on the basis of their arrival time.
        2. Picks job one by one and insert it in the Queue
    */
    executeInit(0, static_cast<int>(m_jobs.size()) - 1);
    int timeStamp = 0;
    int i = 0;
    m_jobs[i].m_burst -= 1;
    m_rq->push(m_jobs[i]);
    std::cout<<"0 ns START"<<std::endl;
    std::cout<<"PROCESS NAME : "<<m_jobs[i].m_name<<" SCHEDULED"<<std::endl;
    std::cout<<"0 ns FINISH"<<std::endl;
    i += 1;
    timeStamp += 1;
    while(!m_rq->empty()){
        std::cout<<timeStamp<<"ns START"<<std::endl;
        struct job currentJob = m_rq->pop();
        if(timeStamp == m_jobs[i].m_arrival){
            if(currentJob.m_burst > m_jobs[i].m_burst){
                // Preempt the currently running job at CPU.
                std::cout<<"PROCESS NAME : "<<currentJob.m_name<<" ";
                std::cout<<"PREEMPTED "<<std::endl;
                std::cout<<"PROCESS NAME : "<<m_jobs[i].m_name<<" ";
                std::cout<<"SCHEDULED "<<std::endl;
                m_jobs[i].m_burst -= 1;
            }
            else{
                std::cout<<"PROCESS NAME : "<<currentJob.m_name<<" ";
                std::cout<<"SCHEDULED "<<std::endl;
                currentJob.m_burst -= 1;
            }
            if(currentJob.m_burst > 0){
                m_rq->push(currentJob);
            }
            if(m_jobs[i].m_burst > 0){
                m_rq->push(m_jobs[i]);
            }
            i += 1;
        }
        else{
            std::cout<<"PROCESS NAME : "<<currentJob.m_name<<" ";
            std::cout<<"SCHEDULED "<<std::endl;
            currentJob.m_burst -= 1;
            if(currentJob.m_burst > 0){
                m_rq->push(currentJob);
            }
        }
        std::cout<<timeStamp<<"ns FINISH"<<std::endl;
        timeStamp += 1;
    }
    return;
}


