#include<stdafx.h>
#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> calcMaxStockBuySell(int arr[], int size, int &maxVal) {
	vector<pair<int, int>> retVal;
	int minIndex = 0;
	int maxIndex = 0;
	for (int i = 1;i <= size;++i) {
		if (arr[i] > arr[maxIndex]) {
			maxIndex = i;
		}
		else if (arr[i] <= arr[maxIndex]) {
			// condition is being checked because it tells that the value of stock fell next day.
			if (maxIndex != minIndex) {
				retVal.push_back(make_pair(minIndex + 1, maxIndex + 1));
				maxVal += arr[maxIndex] - arr[minIndex];
			}
			// Reset both minIndex and maxIndex
			minIndex = i;
			maxIndex = i;
		}
	}
	return retVal;
}

int main(int argc, char *argv[]) {
	int arr[] = { 9,11,8,5,7,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int maxVal = 0;
	vector<pair<int,int>> result = calcMaxStockBuySell(arr, size, maxVal).begin();
	vector<pair<int, int>>::iterator iter = result.begin();
	while (iter != result.end()) {
		cout << "Buy sotck at " << iter->first << " day and sell at " << iter->second << endl;
	}
	cout << "MaxValue you can get : " << maxVal;
	return 0;
}
