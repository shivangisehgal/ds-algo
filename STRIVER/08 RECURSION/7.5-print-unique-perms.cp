//Wrong approach - sort and check for nums[ind] == nums[i]
// This approach won't work if there is more than one duplicate element. At each iteration, you're swapping the element at i with another element. 
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
        
        for(int ind = i; ind < nums.size(); ind++)
        {
            if(ind > i && nums[ind] == nums[i])
                continue;
            
            swap(nums[ind], nums[i]);
            helper(i + 1, ans, nums);
            swap(nums[ind], nums[i]);
        }
     }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        helper(0, ans, nums);
        return ans;
    }
};

// We're swapping the element at start with all possible elements
// If we've already swapped with an element, we shouldn't do it again.
// Keep track of what we're swapping and don't swap with an element
// we've already done so.
//don't sort, use a map, to check if you have visited this number
// This approach won't work if there is more than one duplicate element. At each iteration, you're swapping the element at i with another element. 
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
            if(hashSet.count(nums[ind]) == 1)
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
