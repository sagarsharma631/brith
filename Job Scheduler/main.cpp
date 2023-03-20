//
//  main.cpp
//  ShortTermScheduler
//
//  Created by Sagar Sharma on 12/03/23.
//

#include"ScheduleAlgorithm.hpp"

void schedule(ShortTermSchedulingBase& obj){
    obj.execute();
    return;
}

int main(int argc, const char * argv[]) {
    std::vector<struct job> jobs({
        job("P1",0,8),
        job("P5",4,5),
        job("P3",2,2),
        job("P2",1,4),
        job("P4",3,9)
    });
    ShortTermSchedulingSRTF obj(jobs);
    schedule(obj);
    return 0;
}
