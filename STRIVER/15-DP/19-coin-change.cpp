//memo
//TC:
//SC: 
class Solution {
public:
    
    int rec(int i, int amount, vector<vector<int>>& dp, vector<int>& coins)
    {
        //base case
        if(i == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9; //or INT_MAX;
        }
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        int not_pick = rec(i - 1, amount, dp, coins);
        int pick = INT_MAX;
        
        if(coins[i] <= amount)
        {
            pick = 1 + rec(i, amount - coins[i], dp, coins);
        }
        
        return dp[i][amount] = min(not_pick, pick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        int ans = rec(n - 1, amount, dp, coins);
        
        if(ans >= 1e9 || ans == -1)
            return -1;
        
        return ans;
    }
};

//tab
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        //base case -> i will be fixed = 0
        //1. target % coins[0] ---> target would/ would not have changed.
        
        for(int amt = 0; amt <= amount; amt++)
        {
            if(amt % coins[0] == 0)
                dp[0][amt] = amt / coins[0];
            else
                dp[0][amt] = 1e9;
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int amt = 0; amt <= amount; amt++)
            {
                 int not_pick = dp[i - 1][amt];
                 int pick = INT_MAX;
                
                 if(coins[i] <= amt)
                    pick = 1 + dp[i][amt - coins[i]];
                
                dp[i][amt] = min(not_pick, pick);
            }
        }
        
        if(dp[n - 1][amount] >= 1e9)
            return -1;
        
        return dp[n - 1][amount];
    }
};

//space opt
class Solution {
public:

    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<int> prevIndex(amount + 1, 0);
        vector<int> currIndex(amount + 1, 0);
        //base case -> i will be fixed = 0
        //1. target % coins[0] ---> target would/ would not have changed.
        
        for(int amt = 0; amt <= amount; amt++)
        {
            if(amt % coins[0] == 0)
            {
                prevIndex[amt] = amt / coins[0];
                currIndex[amt] = amt / coins[0];
            }
            else
            {
                prevIndex[amt] = 1e9;
                currIndex[amt] = 1e9;
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            
            for(int amt = 0; amt <= amount; amt++)
            {
                 int not_pick = prevIndex[amt];
                 int pick = INT_MAX;
                
                 if(coins[i] <= amt)
                    pick = 1 + currIndex[amt - coins[i]];
                
                currIndex[amt] = min(not_pick, pick);
            }
            
            prevIndex = currIndex;
        }
        
        if(prevIndex[amount] >= 1e9)
            return -1;
        
        return prevIndex[amount];
    }
};
