#ifndef UTIL_JOB_HPP
#define UTIL_JOB_HPP

#include<iostream>
#include<vector>

namespace utility{

    /*
    The copy constructor and assignment operator does shallow copy, 
    please provide a deep copy constructor and assignment operator in case any pointer member variable is added.
    */
    struct utilJOB{
        std::string m_procID;
        uint8_t m_arrivalTime;
        uint32_t m_burstTime;
        explicit utilJOB(std::string __id, int __arrival, int __burst):
            m_procID(__id),
            m_arrivalTime(__arrival),
            m_burstTime(__burst){
        
            }
        bool operator>(const utilJOB &other) const{
            return (this->m_arrivalTime > other.m_arrivalTime)?true:false;
        }

        bool operator<(const utilJOB &other) const{
            return (this->m_arrivalTime < other.m_arrivalTime)?true:false;
        }
    };

    class utilJOB_DATA{
        private:
            static utilJOB_DATA *m_ptr;         
            utilJOB_DATA(){
				
			}
        protected:

        public:
            static utilJOB_DATA* getInstance(); 
            std::vector<struct utilJOB*>& createVec(int __size = 0);
            struct utilJOB* createJOB(std::string __jobID,int __arrivalTime, int __burstTime);
            void addJOB(std::vector<struct utilJOB*> &vec, struct utilJOB *__jobptr);
            //bool canjobSwap(const struct utilJOB &job1, const struct utilJOB &job2);
            ~utilJOB_DATA(){
                delete m_ptr;
            }  
    };

    template<typename T>
    void swap(T &f,T &sec);

    // The following method makes use of quickSort to sort the jobs based on their arrival time.
    template<typename T>
    void sortJOBS(std::vector<T*> arr,int __beg,int __end, bool(*compPtr)(const T&,const T&));



}

#endif
