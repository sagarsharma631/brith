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
        // We can change the alpha from 0.5 to another weights as the scheduler progresses. Need to implement
        current.m_burst = 0.5 * current.m_pastBurst + 0.5 * current.m_burst;
        current.m_pastBurst = pastBurst;
        m_rq->push(current);
        m_scheduled.insert(current.m_name);
        ++i;
    }
    return;
}


