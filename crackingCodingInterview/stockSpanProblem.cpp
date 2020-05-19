#include<iostream>
#include<stack>

#define DEBUG

using namespace std;

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {

    }
};

int largestRectangle(int arr[], int size) {
    int* areaArr = new int[size] {0};
    stack<int> st;
    st.push(0);
    areaArr[0] = 0;
    auto printArr = [](int* arr, int size) -> void {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
    };

    for (int i = 1; i < size; ++i) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        areaArr[i] = (st.empty()) ? (i) : (i - st.top() - 1);
        st.push(i);
    }

    // Clear the stack
    while (!st.empty()) {
        st.pop();
    }

    int lastIndex = size - 1;
    st.push(lastIndex);
    
    for (int i = lastIndex - 1; i >= 0; --i) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        areaArr[i] += (st.empty()) ? (lastIndex - i) : (st.top() - i - 1);
        st.push(i);
    }

    int maxArea = INT_MIN;

    for (int i = 0; i < size; ++i) {
        maxArea = ((areaArr[i] * arr[i]) > maxArea) ? (areaArr[i] * arr[i]) : maxArea;
    }

    printArr(areaArr, size);
    return 0;
}

// Always delete the memory being returned from this method - or else memory leak.
int* stockSpan(int arr[], int size) {
    int* retArr = new int[size] {0};
    retArr[0] = 1;
    // This stack will be used for storing the indices
    stack<int> st;
    st.push(0);
   
    for (int i = 1; i < size; ++i) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        
        retArr[i] = (st.empty()) ? i + 1 : i - st.top();
        // Now push the element into the stack
        st.push(i);
    }
    return retArr;
}

int main(int argc, char* argv[]) {
    auto printArr = [](int *arr, int size) -> void {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
    };
    int arr[]{6,2,5,4,5,1,1};
    int size = static_cast<int>(sizeof(arr) / sizeof(arr[0]));
    int spanArr = largestRectangle(arr, size);
	return 0;
}
