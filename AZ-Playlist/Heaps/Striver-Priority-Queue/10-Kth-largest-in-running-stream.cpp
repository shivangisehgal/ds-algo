// BRUTE:
// Keep all elements in an array.
// On every add(), sort the array and return arr[n-k].
// TC: O(N log N) per add(), SC: O(N).

// BETTER:
// Use a max-heap of all elements and pop k-1 times on each query.
// TC: O(N + k log N) per query — still too slow.

// OPTIMAL:
// Maintain a min-heap of size K.
// Heap always stores the K largest elements seen so far.
// Whenever size becomes K+1, pop the smallest.
// The top of this heap = Kth largest element.
//
// TC: constructor O(N log K), add() O(log K)
// SC: O(K)


class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
public:
    KthLargest(int k, vector<int>& nums) { //TC: O(N * log K)
        K = k;
        for(auto el : nums){
            add(el);
        }
    }
    
    int add(int val) { //TC: O(log K)
        minHeap.push(val);
        if(minHeap.size() > K)
            minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */