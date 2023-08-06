//return the number of ways you can make given sum.

class Solution {
public:
    int rec(int i, int amount, vector<vector<int>>& dp, vector<int>& coins)
    {
        //base case
        if(amount == 0)
            return 1;
        
        if(i == 0)
        {
            if(amount % coins[0] == 0)
                return 1;
            
            return 0;
        }
            
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        int not_pick = rec(i - 1, amount, dp, coins);
        int pick = 0;
        
        if(coins[i] <= amount)
            pick = rec(i, amount - coins[i], dp, coins);
        
        return dp[i][amount] = not_pick + pick;
    }
    
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        return rec(n - 1, amount, dp, coins);
    }
};

//tabu
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
        for(int amt = 0; amt <= amount; amt++)
        {
            if(amt % coins[0] == 0)
                dp[0][amt] = 1;
        }
        
        for(int i = 0; i < n; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int amt = 1; amt <= amount; amt++)
            {
                int not_pick = dp[i - 1][amt];
                int pick = 0;

                if(coins[i] <= amt)
                    pick = dp[i][amt - coins[i]];
                
                dp[i][amt] = not_pick + pick;
            }
        }
        
        return dp[n - 1][amount];
    }
};

//space opt
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<int> prevIndex(amount + 1, 0);
        vector<int> currIndex(amount + 1, 0);
        
        for(int amt = 0; amt <= amount; amt++)
        {
            if(amt % coins[0] == 0)
            {
                prevIndex[amt] = 1;
                currIndex[amt] = 1;
            }
        }
        
        prevIndex[0] = 1;
        currIndex[0] = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int amt = 1; amt <= amount; amt++)
            {
                int not_pick = prevIndex[amt];
                int pick = 0;

                if(coins[i] <= amt)
                    pick = currIndex[amt - coins[i]];
                
                currIndex[amt] = not_pick + pick;
            }
            
            prevIndex = currIndex;
        }
        
        return prevIndex[amount];
    }
};
