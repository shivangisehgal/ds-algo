//note: exaxctly k
// Consider a sum of the current subset as currSum, we are at index i, and we want the sum of each subset equal to reqSum = sum(nums[])/k.
// We will use a visited[] to keep hold of already used elements.
// If currSum + nums[i] > reqSum, we can only skip the ith element and go to the next element.
// If !visited[i] and currSum + nums[i] <= resSum, we have two choices, either to include it or not include it in the current subset.
// If we include it, we will make visited[i] = true so that the current element cannot be added to any other subset again.
// If we find that taking this choice gives us true, we will return true.
// Otherwise, we will exclude nums[i] from currSum by making visited[i] = false and go to the next element.
// If at any point we find currSum == reqSum, it means we found a subset with the required sum, so call backtrack for k-1 th subset from 0th index.
// If your k == 0, it means we found k subsets whose sum is reqSum.

class Solution {
public:
    
    bool rec(int i, int sum, int target, int k, vector<bool>& visited, vector<int>& nums)
    {
        
        if(k == 0)
            return true;
        
        if(sum == target)
            return rec(0, 0, target, k - 1, visited, nums);
        
        if(i >= nums.size())
            return false;
        
        for(int ind = i; ind < nums.size(); ind++)
        {
            if(visited[ind] == true || ((sum + nums[ind]) > target))
                continue;
            
            visited[ind] = true;
            
            if(rec(ind + 1, sum + nums[ind], target, k, visited, nums) ==  true)    
                return true;
            
            visited[ind] = false;
            
        }
        
        return false;
    }
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int tot_sum = 0;
        vector<bool> visited(nums.size(), false);
        
        for(auto num : nums)
            tot_sum += num;
        
        if(nums.size() < k)
            return false;
        
        if(tot_sum % k != 0)
            return false;
        
        int target = tot_sum / k;
        
        
        return rec(0, 0, target, k, visited, nums);
    }
};
