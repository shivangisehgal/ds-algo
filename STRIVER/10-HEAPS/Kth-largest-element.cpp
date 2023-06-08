//BRUTE
//Sort, find the kth element
//TC: O(NlogN)
//SC: O(1)


//BETTER
//use max heap of size N for kth largest element, use min heap of size N for kth smallest element

// TC: O(N + KlogN), heapify cost O(N), popping k times costs O(KlogN).
// SC: O(N)

class Solution {
public:
  
  int findKthLargest(vector<int>& nums, int k) 
  {
    priority_queue<int> pq(nums.begin(), nums.end());
    for(int i = 1; i < k; i++) 
        pq.pop();
    
    return pq.top();
  }
  
}

//OPTIMAL
//Use min heap OF SIZE K for kth largest element, max heap OF SIZE K for kth smallest element
//Intuition, a min heap of size k - after having traversed entire array would store the top k elements (coz popping happens of minimum elements)
//hence, the minimum element in this min heap would be the kth largest element.


//TC: O(NlogK) - insertion: N * O(log k), popping N * O(log k) => O(NlogK + NlogK)
//SC: O(K)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto num: nums)
        {
            minHeap.push(num);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        
        return minHeap.top();
    }
};
