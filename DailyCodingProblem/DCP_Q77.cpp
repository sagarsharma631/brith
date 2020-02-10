/*

AUTHOR - SAGAR SHARMA

DATE(dd/mm/yyyy) - 09/02/2020

Question - Given a list of possibly overlapping intervals, 

return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].


*/
#include<iostream>
#include<vector>

using namespace std;

// The following function sorts the array using quickSort.

namespace genericUtility{
    // util to swap the elements.
    template<typename T>
    void swap(T &first, T &second){
        T temp;
        temp = first;
        first = second;
        second = temp;
        return;
    }

    template<typename T>
    T min(T &first, T &second){
        return (first >= second)?first:second;
    }
};

int count = 0;

void sortArray(pair<int,int> arr[], int start, int end){
    if(end <= start){
        return;
    }
    pair<int,int> pivot = arr[end];
    int j = start;
    for(int i=start;i<end;++i){
        if(arr[i].first <= pivot.first){
            genericUtility::swap<pair<int,int>>(arr[i],arr[j]);
            ++j;
        }        
    }
    genericUtility::swap<pair<int,int>>(arr[j],arr[end]);
    sortArray(arr,start,j-1);
    sortArray(arr,j+1,end);
    #ifdef DEBUG
    ++count;
    #endif
}

// Following method merges the overlapped intervals.
void mergeOverLappedIntervals(pair<int,int> arr[], int size, vector<pair<int,int>> &intervalVec){
    intervalVec.push_back(arr[0]);
    int index = 0;
    for(int i=1;i<size;++i){
        if(intervalVec[index].second > arr[i].first){
            // This means that the intervals are overlapping.
            if(intervalVec[index].second < arr[i].second){
                // This if condition tells which has greater ending time in the two intervals.
                intervalVec[index].second = arr[i].second;    
            }
        }
        else{
            // Intervals were not overlapping
            intervalVec.push_back(arr[i]);
            ++index;
        }
    }
    return;
}

int main(int argc, char *argv[]){
    pair<int,int> arr[] = {
        make_pair(1,25),
        make_pair(2,5),
        make_pair(4,10),
        make_pair(20,25)
    };
    int size = sizeof(arr)/sizeof(arr[0]);
    // Following method makes the array of intervals into an ascending order.
    sortArray(arr, 0, size-1);

    // The following method merges the overlapping intervals
    vector<pair<int,int>> intervalVec;
    mergeOverLappedIntervals(arr,size,intervalVec);

    for(auto i = intervalVec.begin();i<intervalVec.end();++i){
        cout<<i->first<<","<<i->second<<endl;
    }
    return 0;
}
