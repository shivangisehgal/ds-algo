// Given: array is k-sorted → each element is at most k positions away from its correct index.
//
// INTUITION:
// The smallest element of the sorted array must come from indices [0 … k].
// So push first k+1 elements into a min-heap.
// Heap top gives the next correct element in sorted order.
// After popping, push the next unseen element.
// Continue until array ends, then empty the heap.
//
// TC: O(N log K)
// SC: O(K)


class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        vector<int> sortedArr;
        
        for(int i = 0; i < n && i < k; i++)
            minHeap.push(arr[i]);
        
        int i = k;
        
        while(i < n)
        {
            minHeap.push(arr[i]);
            sortedArr.push_back(minHeap.top());
            minHeap.pop();
            
            i++;
        }
        
        while(!minHeap.empty())
        {
            sortedArr.push_back(minHeap.top());
            minHeap.pop();
            i++;
        }
        
        return sortedArr;
    }
};