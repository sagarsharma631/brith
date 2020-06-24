#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> search(const string& str, const string& pattern) {
	// The following vector stores the indices, where the pattern has been found.
	vector<int> result;
	if (str.empty() || pattern.empty() || (str.size() < pattern.size())) {
		// if either of the string is empty return an empty vector
		return result;
	}

	int patternSize = pattern.size();
	size_t patternHash = hash<string>{}(pattern);

	auto areHashSame = [&](const string& str) -> bool {
		return (hash<string>{}(str) == patternHash) ? true : false;
	};

	auto areStringSame = [&](const int& start, const int& end) -> bool {
		int patternIndex = 0;
		for (int i = start; i <= end; ++i) {
			if (str[i] != pattern[patternIndex]) {
				return false;
			}
			++patternIndex;
		}
		return true;
	};

	int windowMin = 0;
	int windowMax = patternSize - 1;

	while (windowMax < static_cast<int>(str.size())) {
		if (areHashSame(str.substr(windowMin, (windowMax - windowMin) + 1))) {
			// This is to check if in case there is a hash collision.
			if (areStringSame(windowMin, windowMax))
				result.push_back(windowMin);
		}
		windowMin += 1;
		windowMax += 1;
	}

	return result;
}

// Generates the permutation for all the strings present in the vector.
void permute(vector<string>& strVec, int index, unordered_set<string>& permuteSet, int& windowLength){
    
    auto strSwap = [&](int swapIndex) -> void{
        string temp = strVec[swapIndex];
        strVec[swapIndex] = strVec[index];
        strVec[index] = temp;
    };
    
    auto generateString = [&]() -> string{
        string retVal;
        for(auto iter : strVec){
            retVal += iter;
        } 
        if(windowLength == 0){
            // Length of our first permutation.
            windowLength = retVal.length();
        }
        return retVal;
    };
    
    if(index == strVec.size()-1){
        permuteSet.insert(generateString());
        return;
    }
    
    for(int i=index;i<strVec.size();++i){
        strSwap(i);
        permute(strVec, index + 1,permuteSet,windowLength); 
        strSwap(i);
    }
    
    return;
}

int main(int argc, char *argv[]){
    
    vector<string> vec({"cat","dog","lion"});
    // The following set contains the hashes of all the permutations of the above vector.
    unordered_set<string> permuteSet;
    int windowLength = 0;
    string searchStr = "dogcatcatcodecatdog";
    permute(vec,0,permuteSet,windowLength);
    cout<<windowLength<<endl;
    
    return 0;
}
