//memoization
//TC: O(N)
//SC: O(N) + O(N)

int helper(int n, vector<int>& dp)
{
        if(n == 0 || n == 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
}
    
int climbStairs(int n) 
{
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
}


//tabulation
//TC: O(N)
//SC: O(N) //no rec stack space

class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n + 1);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};

//space optimization
//TC: O(N)
//SC: O(1)

class Solution {
public:
    int climbStairs(int n) {
        
        int prev1 = 1;
        int prev2 = 1;
        
        int curr;
        
        for(int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};
