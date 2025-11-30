//BRUTE - bucket sort
//TC: O(N + N + kN) = O(kN)
//SC: O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for(int num : nums)
            map[num]++;
        
        int n = nums.size();
        //a number can occur max of n times => size of bucket = n + 1, do that we can use i = n
        
        vector<vector<int>> bucket(n + 1);
        
        for(auto it : map)
        {
            int freq = it.second;
            int num = it.first;
            
            bucket[freq].push_back(num);
        }
            
        vector<int> ans;
        
        //reverse order coz highest freq first
        
        for(int i = n; i >= 0 && k > 0; i--)
        {
            for(int j = 0; j < bucket[i].size() && k > 0; j++)
            {
                ans.push_back(bucket[i][j]);
                k--;
            }
        }
        
        return ans;
    }
};


//OPTIMAL - heap
//TC: O(N+NlogK+KlogK) = O(NlogK)
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