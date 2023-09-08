// approach of sorting and contnueing if nums[i] == nums[i + 1] - This approach won't work if there is more than one duplicate element. At each iteration, you're swapping the element at i with another element. 
//The resulting array that is sent to recursive backtrack function isn't sorted anymore so you can't simply check for the previous element.
     
class Solution {
public:
    
     void helper(int i, vector<vector<int>>& ans, vector<int> nums)
     {
        if(i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> hashSet;
         
        for(int ind = i; ind < nums.size(); ind++)
        {
            if(hashSet.find(nums[ind]) != hashSet.end())
                continue;
            
            hashSet.insert(nums[ind]);
            swap(nums[ind], nums[i]);
            helper(i + 1, ans, nums);
            swap(nums[ind], nums[i]);
        }
     }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        helper(0, ans, nums);
        return ans;
    }
};
