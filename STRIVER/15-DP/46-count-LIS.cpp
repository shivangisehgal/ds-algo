class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, 1);
        vector<int> count(n,1);
        
        int maxi = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {            
            for(int prev = 0; prev <= i - 1; prev++)
            {
                if(nums[prev] < nums[i])
                {
                    if(1 + dp[prev] > dp[i])
                    {
                        count[i] = count[prev];
                        dp[i] = 1 + dp[prev];
                    }
                    
                    else if(dp[i] == 1 + dp[prev])
                        count[i] += count[prev];
                }
                    
                
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                ans = count[i];
            }
            
            else if(dp[i] == maxi)
                ans += count[i];
        }
        
        return ans;
    }
};
