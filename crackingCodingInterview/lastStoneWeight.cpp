/*

AUTHOR - SAGAR SHARMA

DATE CREATED - 16/04/2020

Question - 
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.

Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

*/
#include<iostream>
#include<queue>

using namespace std;

int lastStoneWeight(vector<int>& vec) {
        priority_queue<int> heap;
	    int index = 0;
	    for (auto item : vec) {
		    heap.push(item);
	    }
	    int itemFirst = 0;
	    int itemSecond = 0;
	    while (!heap.empty() && heap.size() > 1){
		    itemFirst = heap.top();
		    heap.pop();
		    itemSecond = heap.top();
		    heap.pop();
		    if (itemFirst > itemSecond) {
			    heap.push(itemFirst - itemSecond);
		    }
		    else if (itemFirst < itemSecond) {
			    heap.push(itemSecond - itemFirst);
		    }
		    else {
			    // Do nothing
		    }
	    }
	    // return 0 if the heap is now empty or return the element which is present in heap now.
	    return (heap.empty()) ? 0 : heap.top();
    }
    
    int main(int argc, char *argv[]){
      vector<int> vec({2,7,4,1,8,1});
      lastStoneWeight(vec);
      return 0;
    }
