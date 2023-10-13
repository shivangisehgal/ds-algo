//rec
class Solution {
public:
    
    int rec(int n, vector<int>& cost)
    {
        if(n == 0 || n == 1)
            return cost[n];
        
        int minCost = cost[n] + min(rec(n - 1, cost), rec(n - 2, cost));
        
        return minCost;
    }
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        return min(rec(n - 1, cost), rec(n - 2, cost));
    }
};

//memo
class Solution {
public:
    
    int rec(int n, vector<int>& cost, vector<int>& dp)
    {
        if(n == 0 || n == 1)
            return cost[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        int minCost = cost[n] + min(rec(n - 1, cost, dp), rec(n - 2, cost, dp));
        
        return dp[n] = minCost;
    }
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        
        if(n == 1)
            return cost[0];
        
        vector<int> dp(n, -1);
      
        return min(rec(n - 1, cost, dp), rec(n - 2, cost, dp));
    }
};

//tabu
class Solution {
public:
    
    int rec(int n, vector<int>& cost, vector<int>& dp)
    {
        if(n == 0 || n == 1)
            return cost[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        int minCost = cost[n] + min(rec(n - 1, cost, dp), rec(n - 2, cost, dp));
        
        return dp[n] = minCost;
    }
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        
        if(n == 1)
            return cost[0];
        
        vector<int> dp(n, -1);
        
        for(int i = 0; i <= 1 && i < n; i++)
            dp[i] = cost[i];
            
        for(int i = 2; i < n; i++)
        {
            int minCost = cost[i] + min(dp[i - 1], dp[i - 2]);
            dp[i] = minCost;
        }
        
        return min(dp[n - 1], dp[n - 2]);
    }
};

//space opt

class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        
        if(n == 1)
            return cost[0];
        
        vector<int> dp(n, -1);
        
        for(int i = 0; i <= 1 && i < n; i++)
            dp[i] = cost[i];
            
        int curr;
        int prev1 = cost[0];
        int prev2 = cost[1];
        
        for(int i = 2; i < n; i++)
        {
            int minCost = cost[i] + min(prev2, prev1);
            curr = minCost;
            
            prev1 = prev2;
            prev2 = curr;
        }
        
        return min(prev2, prev1);
    }
};
