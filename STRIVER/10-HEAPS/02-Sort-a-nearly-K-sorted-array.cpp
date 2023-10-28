//i-th element can lie from i - k th to i + k th index.
//so first element of the sorted array can be from 0th index to kth index
//So, push first k + 1 elements in a minHeap. so first element of the sorted array would be the minimum element of the heap.
//and so on

//TC: O(NlogK)
//SC: O(K)

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
