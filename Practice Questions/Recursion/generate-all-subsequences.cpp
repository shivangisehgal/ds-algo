class Solution {
public:
    
    void rec(vector<int>& v, int i, int n, vector<vector<int>>& ans, vector<int>& nums)
    {
        if(i == n)
        {
            ans.push_back(v);
            return;
        }
        
            //pick
            v.push_back(nums[i]);
            rec(v, i + 1, n, ans, nums);
            v.pop_back();
            
            //not pick
            rec(v, i + 1, n, ans, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        rec(v, 0, n, ans, nums);
        return ans;
    }
};
