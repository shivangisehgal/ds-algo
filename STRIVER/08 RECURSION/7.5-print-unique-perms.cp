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

//OPTIMAL
//Just like in the BRUTE of printing perms, 
//sort the array, if first we'll visit the number, if we have duplicates, and we have visited the previous element, only then we should iterate, 
//because, lets say [1 1 2] => if we have not visited nums[0] = 1, and we are at nums[1] = 1, then now, v = [1], and same kahani continues, 
//so we only need to iterate a duplicate, if its previous duplicate has alreasy been chosen.
//TC: O(N! * N)
//SC: O(N! + N)
class Solution {
public:
    
    void helper(vector<bool>& visited, vector<int>& v, vector<vector<int>>& ans, vector<int>& nums)
    {
        if(v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        
        for(int ind = 0; ind < nums.size(); ind++)
        {
            if(visited[ind] == true|| (ind > 0 && nums[ind] == nums[ind - 1] && visited[ind - 1] == false))
                continue;
            
            visited[ind] = true;
            v.push_back(nums[ind]);
            helper(visited, v, ans, nums);
            v.pop_back();
            visited[ind] = false;
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<vector<int>> ans;
        vector<int> v;
        helper(visited, v, ans, nums);
        return ans;
    }
};
