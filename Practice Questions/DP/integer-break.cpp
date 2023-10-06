//break integer n, into numbers such that their sum equal n, and return the pax product of the numbers.
class Solution {
public:
    
    int integerBreak(int n) {
        
        if(n <= 3)
            return (n - 1);
        
        vector<int> dp(n + 1, -1);
        
        for(int i = 1; i <= 3; i++)
            dp[i] = i;
        
        for(int i = 4; i <= n; i++)
        {
            int max_prod = i;
            
            for(int ind = 1; ind <= i - 1; ind++)
            {
                int x = dp[i - ind];
                max_prod = max(max_prod, ind * x);
            }
            
            dp[i] = max_prod;
        }
        
        return dp[n]; 
    }
};
