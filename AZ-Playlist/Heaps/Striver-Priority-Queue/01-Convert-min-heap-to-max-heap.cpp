// BRUTE:
// Extract all elements from min-heap, store, and build a new max-heap.
// TC: O(N) to read + O(N) to build = O(N)
// But destroys the original heap structure.

// BETTER:
// Swap elements to convert array form, then call heapify for each non-leaf.
// Same as building heap from scratch.

// OPTIMAL:
// Array already represents a complete binary tree.
// Only need to enforce max-heap property.
// Start from last non-leaf index = N/2 - 1 down to 0.
// Call maxHeapify() at each node.
// This converts the tree into a valid max-heap.
// TC: O(N), SC: O(1)

// User function Template for C++

class Solution {
private:
    void maxHeapify(int i, vector<int> &arr, int N){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        int maxVal = arr[i];
        int maxInd = i;
        
        if(left < N && arr[left] > maxVal){
            maxVal = arr[left];
            maxInd = left;
        }
        
        if(right < N && arr[right] > maxVal){
            maxVal = arr[right];
            maxInd = right;
        }
        
        if(maxInd != i){
            swap(arr[maxInd], arr[i]);
            maxHeapify(maxInd, arr, N);
        }
    }
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        
        for(int i = N / 2 - 1; i >= 0; i--){
            maxHeapify(i, arr, N);
        }
    }
};