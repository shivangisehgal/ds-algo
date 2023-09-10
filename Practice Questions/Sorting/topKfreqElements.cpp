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
