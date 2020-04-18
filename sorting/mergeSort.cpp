/*

AUTHOR - SAGAR SHARMA

NOTE - MERGE SORT

*/

#include<iostream>
#define DEBUG
using namespace std;

// Merged two sorted arrays to the third one
int* mergeTwoSorted(int arr[], const int &lo, const int &hi, const int &mid) {
	int* arrMerged = new int[(hi - lo) + 1]{0};
	int indexL = 0;
	int indexR = mid+1;
	int indexMerge = 0;
	while ((indexL <= mid) && (indexR <= hi)) {
		if (arr[indexL] <= arr[indexR]) {
			arrMerged[indexMerge] = arr[indexL];
			++indexL;
		}
		else {
			arrMerged[indexMerge] = arr[indexR];
			++indexR;
		}
		++indexMerge;
	}
	if (indexL != mid) {
		while (indexL <= mid) {
			arrMerged[indexMerge] = arr[indexL];
			++indexMerge;
			++indexL;
		}
	}
	else {
		while (indexR <= hi) {
			arrMerged[indexMerge] = arr[indexR];
			++indexMerge;
			++indexR;
		}
	}

	return arrMerged;
}

void mergeSort(int arr[], const int& lo, const int& hi){
	if (lo < hi) {
		int mid = (lo + hi) / 2;
		mergeSort(arr, lo, mid);
		mergeSort(arr, mid + 1, hi);
		int *merged = mergeTwoSorted(arr, lo, hi, mid);
		for (int i = lo; i <= hi; ++i) {
			arr[i] = merged[i];
		}
		// free the merged array or else memory leak
		delete[] merged;
		return;
	}	
}

int main(int argc, char *argv[]){
  int arr[]{33	10	19	12	49	25	14	39	33	30};
  return 0;
}
