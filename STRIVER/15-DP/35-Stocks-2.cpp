//Method-1: Greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int profit = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(prices[i] > prices[i - 1]) //positive slope
                profit += prices[i] - prices[i - 1];
        }
        
        return profit;
        //2 - 1 + 3 - 2 + 4 - 3 + 5 - 4
        //= -1 + 5 = 4
    }
};

//Method-2 DP
//rec
class Solution {
private:
    int rec(int i, bool buy, vector<int>& prices)
    {
        //base case
        if(i == prices.size())
            return 0;
        
        int profit = INT_MIN;
        
        if(buy == true)
        {
            int buy_now = -prices[i] + rec(i + 1, false, prices);
            int buy_later =  0 + rec(i + 1, true, prices);
            
            profit = max(buy_now, buy_later);
        }
        
        else //sell
        {
            int sell_now = +prices[i] + rec(i + 1, true, prices);
            int sell_later =  0 + rec(i + 1, false, prices);
            
            profit = max(sell_now, sell_later);
        }
        
        return profit;
    }
    
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        return rec(0, true, prices);
    }
};


//memo
class Solution {
private:
    int rec(int i, int buy, vector<vector<int>>& dp, vector<int>& prices)
    {
        //base case
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int profit = INT_MIN;
        
        if(buy == 1)
        {
            int buy_now = -prices[i] + rec(i + 1, 0, dp, prices);
            int buy_later =  0 + rec(i + 1, 1, dp, prices);
            
            profit = max(buy_now, buy_later);
        }
        
        else //sell
        {
            int sell_now = +prices[i] + rec(i + 1, 1, dp, prices);
            int sell_later =  0 + rec(i + 1, 0, dp, prices);
            
            profit = max(sell_now, sell_later);
        }
        
        return dp[i][buy] = profit;
    }
    
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return rec(0, 1, dp, prices);
    }
};

//tabu
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        
        //rec: 0 to n
        //iter: n to 0
        
        dp[n][0] = dp[n][1] = 0;
        
        int profit = INT_MIN;
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= 1; j++)
            {
                profit = INT_MIN;
                
                if(j == 1)
                {
                    int buy_now = -prices[i] + dp[i + 1][0];
                    int buy_later =  0 + dp[i + 1][1];

                    profit = max(buy_now, buy_later);
                }
                
                else
                {
                    int sell_now = +prices[i] + dp[i + 1][1];
                    int sell_later =  0 + dp[i + 1][0];

                    profit = max(sell_now, sell_later);
                }
                
                dp[i][j] = profit;
            }
        }
        
        return dp[0][1];
    }
};

//space opt.
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();        
        //rec: 0 to n
        //iter: n to 0
        
        vector<int> nextIndex(2, 0);
        
        int profit = INT_MIN;
        
        for(int i = n - 1; i >= 0; i--)
        {
            vector<int> currIndex(2, 0);
            
            for(int j = 0; j <= 1; j++)
            {
                profit = INT_MIN;
                
                if(j == 1)
                {
                    int buy_now = -prices[i] + nextIndex[0];
                    int buy_later =  0 + nextIndex[1];

                    profit = max(buy_now, buy_later);
                }
                
                else
                {
                    int sell_now = +prices[i] + nextIndex[1];
                    int sell_later =  0 + nextIndex[0];

                    profit = max(sell_now, sell_later);
                }
                
                currIndex[j] = profit;
            }
            
            nextIndex = currIndex;
        }
        
        return nextIndex[1];
    }
};
