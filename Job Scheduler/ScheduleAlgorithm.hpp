//
//  ScheduleAlgorithm.hpp
//  ShortTermScheduler
//
//  Created by Sagar Sharma on 12/03/23.
//

#ifndef ScheduleAlgorithm_hpp
#define ScheduleAlgorithm_hpp

#include <iostream>
#include <vector>
#include <unordered_set>
#include "IReadyQueue.hpp"

class ShortTermSchedulingBase{
private:
    
protected:
    std::vector<struct job> m_jobs;
    // This is the ready queue which will hold the jobs to schedule.
    IReadyQ *m_rq;
    // This function does preprocessing and initializes ready queue
    virtual void process();
public:
    ShortTermSchedulingBase(std::vector<struct job>& _jobs, IReadyQ* _rq) : m_jobs(_jobs), m_rq(_rq){
        
    }
    
    // Cannot create a copy of this.
    ShortTermSchedulingBase(ShortTermSchedulingBase &obj) = delete;
    ShortTermSchedulingBase& operator=(ShortTermSchedulingBase &obj) = delete;
    
    ~ShortTermSchedulingBase(){
        
    }
    // This function executes the scheduling
    virtual void execute() = 0;
};

class ShortTermSchedulingFCFS : public ShortTermSchedulingBase{
private:
protected:
public:
    ShortTermSchedulingFCFS(std::vector<struct job>& jobs);
    ~ShortTermSchedulingFCFS();
    // This function executes the scheduling
    void execute() override;
};

class ShortTermSchedulingSJF : public ShortTermSchedulingBase{
private:
    // This holds the process names which have been sheduled. This algorithm runs until each process is scheduled at least once.
    std::unordered_set<std::string> m_scheduled;
protected:
public:
    ShortTermSchedulingSJF(std::vector<struct job>& jobs);
    ~ShortTermSchedulingSJF();
    // This function executes the scheduling
    void execute() override;
};

#endif /* ScheduleAlgorithm_hpp */
