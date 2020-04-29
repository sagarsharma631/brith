/*
 *	AUTHOR - SAGAR SHARMA
 *
 *	DATE MODIFIED - 29/04/2020
 *
 *	Question - Max a robber can rob if he is allowed to rob only non adjacent homes.
 *
 */
#include<iostream>
#include<vector>

using namespace std;

int rob(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int maxStolenVal = INT_MIN;
        int maxBound = nums.size();
        // create DP array
        int *dpArr = new int[maxBound]{0};
        
        // set base cases.
        dpArr[0] = nums[0];
        if(maxBound > 1){
            dpArr[1] = nums[1];
        }
        
        // fill dp array
        for(int i=0;i<maxBound;++i){
            maxStolenVal = max({maxStolenVal,dpArr[i]});
            if(i+2 < maxBound){
                dpArr[i+2] = max({dpArr[i] + nums[i+2],dpArr[i+2]});  
            }
            if(i+3 < maxBound){
                dpArr[i+3] = max({dpArr[i] + nums[i+3],dpArr[i+3]});   
            }
        }
        return maxStolenVal;
}

int main(int main, char *argv[]){
	vector<int> nums({2,7,9,3,1});	
	cout<<rob(nums);
	return 0;
}
