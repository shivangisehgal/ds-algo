class Solution {
public:
    
    int minKadane(vector<int>& nums, int n)
    {
        int currSum = 0;
        
        int minSum = INT_MAX;
        
        
        for(int i = 0; i < n; i++)
        {
            if(currSum > 0)
                currSum = nums[i];
            
            else
                currSum += nums[i];
            
            minSum = min(minSum, currSum);
        }
        
        return minSum;
    }
    
    int maxKadane(vector<int>& nums, int n)
    {
        int currSum = 0;
        
        int maxSum = INT_MIN;
        
        
        for(int i = 0; i < n; i++)
        {
            if(currSum < 0)
                currSum = nums[i];
            
            else
                currSum += nums[i];
            
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
    
    
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int totSum = 0;
        int minSubarraySum = minKadane(nums, n);
        int maxSubarraySum = maxKadane(nums, n);
        
        for(int i = 0; i < n; i++)
        {
            totSum += nums[i];
        }
        
        return totSum == minSubarraySum ? maxSubarraySum : max(totSum - minSubarraySum, maxSubarraySum);
        
    }
};
