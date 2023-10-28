//max heap of {abs(nums[i] - x), nums[i]}
//TC: O(NlogK + NlogN) = O(NlogN)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        priority_queue<pair<int, int>> maxHeap;
        
        for(int i = 0; i < arr.size(); i++)
        {
            int dist = abs(arr[i] - x);
            maxHeap.push({dist, arr[i]});
            
            if(maxHeap.size() > k)
                maxHeap.pop();
        }
        
        while(!maxHeap.empty())
        {
            auto p = maxHeap.top();
            ans.push_back(p.second);
            maxHeap.pop();
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
