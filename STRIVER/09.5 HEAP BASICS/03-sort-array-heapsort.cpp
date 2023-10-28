//Build a max heap of the vector using heapfify 
//Sort the heap vector using heap sort

//This is 0-based indexing

//TC: O(NlogN)
//SC: O(1)

class Solution {
public:
    
    void maxHeapify(int ind, vector<int>& v, int size) //Placing node at ind at correct position by *comparing with children*
    {
        //0-based index
        int leftChildPos = 2 * ind + 1;
        int rightChildPos = 2 * ind + 2;

        int maxPos = ind;

        if(leftChildPos <= size && v[leftChildPos] > v[maxPos])
            maxPos = leftChildPos;
        if(rightChildPos <= size && v[rightChildPos] > v[maxPos])
            maxPos = rightChildPos;

        if(maxPos != ind)
        {
            swap(v[ind], v[maxPos]);
            maxHeapify(maxPos, v, size);
        }
    }
    
    
    void buildHeap(vector<int>& v) //Place all internal nodes at their correct position
    {
        int n = v.size();
        
         for(int i = n / 2 - 1; i >= 0; i--) //0 -> (n / 2 - 1)
            maxHeapify(i, v, n - 1);
    }
    
    void heapSort(vector<int>& heap) //extract max element (Swap with last element and decrease size by 1) one by one
    {
        int size = heap.size() - 1;
        
        for(int i = size; i >= 1; i--)
        {
            swap(heap[0], heap[i]);
            size = size - 1;
            maxHeapify(0, heap, size);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        //Transform vector into heap vector
        buildHeap(nums);
        
        //Sort heap vector
        heapSort(nums);
        
        return nums;
    }
};
