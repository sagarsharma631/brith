#
#   AUTHOR - SAGAR SHARMA
#
#   DATE CREATED - 16/04/2020
#
#   Question - Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
#
#

def findMaxLength(nums):
        if(len(nums) == 2):
            if(nums[0] == nums[1]):
                return 0
            else:
                return 2
            
        prefSumList = []
        currSum = 0
        for item in nums:
            if(item == 1):
                currSum += 1
                prefSumList.append(currSum) 
            else:
                currSum -= 1
                prefSumList.append(currSum)
        
        indexDict = dict()
        indexDict[0] = -1
        currlargest = 0
        index = 0
        while(index < len(prefSumList)):
            if(indexDict.get(prefSumList[index]) != None):
                # this means that this prefix sum is already available earlier
                currlargest = max(currlargest,index - indexDict.get(prefSumList[index]))
            else:
                indexDict[prefSumList[index]] = index
            
            index += 1
                
        return currlargest
