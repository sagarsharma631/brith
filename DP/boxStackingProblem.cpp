#include<iostream>
#include<vector>
#define DEBUG	// Comment out if you don't wanna see the debuggin contents

using namespace std;

// This function merges the array based on the callback function present
template<typename T>
T* mergeArray(T arr[], int lo, int mid, int hi, bool (*func)(const T&, const T&)) {
    // Allocate the memory at heap for the merged array.
    T* merged = new T[(hi - lo) + 1];
    int lIndex = lo;
    int rIndex = mid + 1;
    int mergedIndex = 0;    // This index will keep track of the merged array.
    while (lIndex <= mid && rIndex <= hi) {
        /* The callback function decides which element to add in the merged array. It returns true if first is to be 
         inserted or false when second is to be inserted. */
        if (func(arr[lIndex], arr[rIndex])) {
            merged[mergedIndex] = arr[lIndex];
            ++lIndex;
        }
        else {
            merged[mergedIndex] = arr[rIndex];
            ++rIndex;
        }
        ++mergedIndex;
    }

    while (lIndex <= mid) {
        merged[mergedIndex] = arr[lIndex];
        ++mergedIndex;
        ++lIndex;
    }
    
    while (rIndex <= hi) {
        merged[mergedIndex] = arr[rIndex];
        ++mergedIndex;
        ++rIndex;
    }
    
    return merged;
}

// Merge Sort Implementation - Should make use of template and callback function.
template<typename T>
void mergerSort(T arr[], int lo, int hi, bool (*func)(const T&, const T&) = NULL) {
    if (!func) {
        // throw the exception asking to provide the callback function.
        throw("provide callback function");
    }
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        mergerSort<T>(arr, lo, mid, func);
        mergerSort<T>(arr, mid + 1, hi, func);
        T* merged = mergeArray(arr, lo, mid, hi, func);
        for (int i = lo; i <= hi; ++i) {
            arr[i] = merged[i - lo];
        }
        // Deallocate this memory or else memory leak.
        delete[] merged;
    }
    return;
}

// This structure is actually a 3D Box - length, breadth and height
struct box {
    int m_length;
    int m_breadth;
    int m_height;
    // Constructs the box.
    box(int length = 0, int breadth = 0, int height = 0): m_length(length),
        m_breadth(breadth),
        m_height(height){
    }
    // Copy Constructs the box object
    box(const struct box& other) {
        this->m_length = other.m_length;
        this->m_breadth = other.m_breadth;
        this->m_height = other.m_height;
    }
};

// Returns true if base area of first box has greater surface area than second.
bool isFirstGreater(const struct box& first, const struct box& second) {
    return ((first.m_length * first.m_breadth) >= (second.m_breadth * second.m_length)) ? true : false;
}

// 1st parameter is the original 3D box, 2nd parameter is the vector which will contain all the permutations of the box.
void permuteBox(const struct box& originalBox, vector<struct box>& permutationsBox) {
    /*
        Permutations will be done in following manner. L -> Length, B -> Breadth, H -> Height
        1.  L * B * H 
        2.  L * H * B
        3.  B * L * H
        4.  B * H * L
        5.  H * L * B
        6.  H * B * L
    */
    // 1 and 2
    permutationsBox.push_back(struct box(originalBox.m_length,originalBox.m_breadth,originalBox.m_height));     // 1
    permutationsBox.push_back(struct box(originalBox.m_length, originalBox.m_height, originalBox.m_breadth));   // 2
    // 3 and 4
    permutationsBox.push_back(struct box(originalBox.m_breadth, originalBox.m_length, originalBox.m_height));   // 3
    permutationsBox.push_back(struct box(originalBox.m_breadth, originalBox.m_height, originalBox.m_length));   // 4
    // 5 and 6
    permutationsBox.push_back(struct box(originalBox.m_height, originalBox.m_length, originalBox.m_breadth));   // 5
    permutationsBox.push_back(struct box(originalBox.m_height, originalBox.m_breadth, originalBox.m_length));   // 6
    return;
}

// DP solution for Box Stacking problem
int boxStackingProblem(struct box arr[], int size) {
    /* create the permutations of each box and push in the vector. Reserving the size of vector because we already know 
       that there would be 6 permutations per box.*/
    std::vector<struct box> permutationsBox;
    permutationsBox.reserve(size * 6);

    // traverse the arr[] containing the boxes in their initial form and insert their permutations in the above vector.
    for (int i = 0; i < size; ++i) {
        permuteBox(arr[i], permutationsBox);
    }

    /* Now we are done with all the permutations, sort them in descending order of their base areas i.e. first two
     dimensions */
    struct box* arrPermutations = new struct box[size * 6];
    int i = 0;
    for (const auto& iter : permutationsBox) {
        arrPermutations[i] = iter;
        ++i;
    }

    mergerSort<struct box>(arrPermutations,0,size-1,isFirstGreater);
#ifdef DEBUG
    for (int i = 0; i < size * 6; ++i) {
        cout << arrPermutations[i].m_length << "," << arrPermutations[i].m_breadth << endl;
    }
#endif // DEBUG

    // Now make use of LIS algorithm to find the Maximum increasing subsequence
    int maxVal = 0;
    int* dpArray = new int[size * 6];

    // populate the base cases.
    for (int i = 0; i < size * 6; ++i) {
        dpArray[i] = 1;
    }

    // populate the DP table
    for (int i = 0; i < (size * 6); ++i) {
        for (int j = 0; j < i; ++j) {

        }
    }
    return 0;

}

int main(int argc, char* argv[]) {
    struct box boxArr[]{
        struct box(4,2,5),
        struct box(3,1,6),
        struct box(3,2,1),
        struct box(6,3,8)
    };
    int size = static_cast<int>(sizeof(boxArr) / sizeof(boxArr[0]));
    boxStackingProblem(boxArr,size);
    return 0;
}
