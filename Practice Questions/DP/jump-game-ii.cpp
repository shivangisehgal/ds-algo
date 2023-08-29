//rec

class Solution {
public:
    int rec(int i, int n, vector<int>& nums)
    {
        if(i >= n - 1)
            return 0;
        
        int ans = n + 1;
        
        for(int ind = 1; ind <= nums[i]; ind++)
        {
            ans = min(ans, 1 + rec(i + ind, n, nums));
        }
        
        return ans;
    }
    
    int jump(vector<int>& nums) {
        
        return rec(0, nums.size(), nums);
    }
};

//tabu
class Solution {
public:

    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, n + 1);
        
        dp[n - 1] = 0;
        
        for(int i = n - 2; i >= 0; i--)
        {
            for(int ind = 1; ind <= nums[i]; ind++)
            {
                if(i + ind > n - 1)
                    dp[i] = 1;
                
                else
                    dp[i] = min(dp[i], 1 + dp[i + ind]);
            }
            
        }
        
        return dp[0];
    }
};
