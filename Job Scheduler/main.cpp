//
//  main.cpp
//  ShortTermScheduler
//
//  Created by Sagar Sharma on 12/03/23.
//

#include"ScheduleAlgorithm.hpp"

int main(int argc, const char * argv[]) {
    std::vector<struct job> jobs({
        job("P1",0,6),
        job("P2",3,5),
        job("P3",2,2),
        job("P4",1,3)
    });
    ShortTermSchedulingSJF obj(jobs);
    obj.execute();
    return 0;
}
