//TC: O(N+NlogK+KlogK) = O(NlogN)
//SC: O(K) + O(N)

class Cmp
{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return (a.first > b.first);
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        
        for(int num : nums)
            map[num]++;            
        
        int n = nums.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> minHeap;
        
        for(auto m : map)
        {
            int freq = m.second;
            int num = m.first;
            minHeap.push({freq, num}); 
            
            if(minHeap.size() > k)
                minHeap.pop();          
        }
        
        vector<int> ans;
        
        while(!minHeap.empty())
        {
            auto p = minHeap.top();
            ans.push_back(p.second);
            minHeap.pop();                      
        }
        
        return ans;
    }
};
