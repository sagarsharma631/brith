/*

AUTHOR - SAGAR SHARMA

Question - Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

#include<iostream>
#include<unordered_set>
#include<algorithm>
#define DEBUG

int longestConsecutiveElements(const int arr[], int size) {
	std::unordered_set<int> hashMap;
	for (int item : arr) {
		hashMap.insert(item);
	}
	int length = INT_MIN;
	int temp = 0;
	for (int i = 0; i < size; ++i) {
		// This means that this element is the starting of the increasing array.
		if (hashMap.find(arr[i] - 1) == hashMap.end()) {
			temp = arr[i];
			while (hashMap.find(temp) != hashMap.end()) {
				temp += 1;
			}
			length = std::max<int>(length, temp - arr[i]);
		}
	}
	return length;
}

int main(int argc, char *argv[]){
	int arr[]{100,4,200,1,3,2};
	int size = sizeof(arr) / sizeof(arr[0]);
  int length = longestConsecutiveElements(arr,size);
#ifdef DEBUG
  std::cout<<length<<std::endl;
#endif

  return 0;
}
