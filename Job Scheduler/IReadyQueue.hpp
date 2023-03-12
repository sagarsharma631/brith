//
//  IReadyQueue.hpp
//  ShortTermScheduler
//
//  Created by Sagar Sharma on 12/03/23.
//

#ifndef IReadyQueue_hpp
#define IReadyQueue_hpp

#include<queue>
#include<string>

struct job{
    std::string m_name;
    int m_arrival;
    int m_burst;
    // This value is heuristically calculated with alpha as 0.5 -> 0.5 current burst time + 0.5 past info.
    int m_pastBurst;    // Initial value assigned as 10 ms burst time.
    job():
        m_name("JUNK PROCESS"),
        m_arrival(INT_MIN),
        m_burst(INT_MIN),
        m_pastBurst(INT_MIN)
    {
    
    }
    job(std::string name_, int arrival_, int burst_):
        m_name(name_),
        m_arrival(arrival_),
        m_burst(burst_),
        m_pastBurst(10)
    {
        
    }
};

class IReadyQ{
private:
    int m_size;
protected:
    std::vector<struct job> m_jobs;
public:
    IReadyQ(std::vector<struct job>& jobs, int _size) :
        m_jobs(jobs),
        m_size(_size)
    {
        
    }
    ~IReadyQ(){
        
    }
    virtual void initialize() = 0;
    virtual void push(struct job obj) = 0;
    virtual struct job pop() = 0;
    inline int getSize() const{return m_size;}
};

// This creates the ready Queue for FCFS scheduling
class FCFSQueue : public IReadyQ{
private:
    std::queue<struct job> readyQ;
    void initExecute(int lo, int hi);
protected:
public:
    FCFSQueue(std::vector<struct job>& jobs) :
        IReadyQ(jobs, static_cast<int>(jobs.size()))
    {
        
    }
    ~FCFSQueue(){
        
    }
    void initialize() override;
    void push(struct job obj) override;
    struct job pop() override;
};

// This creates the ready Queue for SJF scheduling
class SJFQueue : public IReadyQ{
private:
    struct compareBurst{
        bool operator()(struct job& first, struct job& second){
            return first.m_burst > second.m_burst;
        }
    };
    std::priority_queue<struct job, std::vector<struct job>, struct compareBurst> readyQ;
protected:
public:
    SJFQueue(std::vector<struct job> _jobs):
        IReadyQ(_jobs,static_cast<int>(_jobs.size()))
    {
        
    }
    ~SJFQueue(){
        
    }
    void initialize() override;
    void push(struct job obj) override;
    struct job pop() override;
};

// This creates the ready Queue for SRTF scheduling

#endif /* IReadyQueue_hpp */
