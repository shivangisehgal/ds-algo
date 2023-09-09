BASIC IMPLEMENTATIVE EXAMPLE OF CHOOSING EACH ELEMENT RECURSION (SUB ITERATIVE)
//This is usually used when duplicates are not allowed.
//with pick-notpick rec, we would have used set, therefore, TC, SC : O(2^N * logN) (set insertion bhi hai)

//TC, SC : O(2^N)
class Solution {
public:
    void helper(int i, vector<int>& v, vector<vector<int>>& ans, vector<int>& nums)
    {
        //base case condition
        ans.push_back(v);
        
        for(int ind = i; ind < nums.size(); ind++)
        {
            if(ind > i and nums[ind] == nums[ind - 1])
                continue;
            
            
            v.push_back(nums[ind]);
            helper(ind + 1, v, ans, nums);
            v.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(0, v, ans, nums);
        return ans;
    }
};
