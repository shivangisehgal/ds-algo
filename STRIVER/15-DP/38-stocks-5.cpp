//Buu-Sell stocks with cooldown. - SPACE OPT IMPORTANT

class Solution {
private:
    int rec(int i, bool buy, vector<int>& prices)
    {
        //base case
        if(i >= prices.size())
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
            int sell_now = +prices[i] + rec(i + 2, true, prices);
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
        if(i >= prices.size())
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
            int sell_now = +prices[i] + rec(i + 2, 1, dp, prices);
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
        
        vector<vector<int>> dp(n + 2, vector<int>(2, -1));
        
        //rec: 0 to n
        //iter: n to 0
        
        dp[n + 1][0] = dp[n + 1][1] = dp[n][0] = dp[n][1] = 0;
        
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
                
                    int sell_now = +prices[i] + dp[i + 2][1];
                    
                    int sell_later =  0 + dp[i + 1][0];

                    profit = max(sell_now, sell_later);
                }
                
                dp[i][j] = profit;
            }
        }
        
        return dp[0][1];
    }
};
//another way of writing tabu
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        
        //rec: 0 to n
        //iter: n to 0
        
        dp[n + 1][0] = dp[n + 1][1] = dp[n][0] = dp[n][1] = 0;
                
        for(int i = n - 1; i >= 0; i--)
        {
                
            int buy_now = -prices[i] + dp[i + 1][0];
            int buy_later =  0 + dp[i + 1][1];

            dp[i][1] = max(buy_now, buy_later);

            int sell_now = +prices[i] + dp[i + 2][1];
                    
            int sell_later =  0 + dp[i + 1][0];

            dp[i][0] = max(sell_now, sell_later);
        }
        
        return dp[0][1];
    }
};


//space opt.
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        
        //rec: 0 to n
        //iter: n to 0
        
        vector<int> next2Index(2, 0);
        vector<int> nextIndex(2, 0);
        vector<int> currIndex(2, 0);
                
        for(int i = n - 1; i >= 0; i--)
        {
                
            int buy_now = -prices[i] + nextIndex[0];
            int buy_later =  0 + nextIndex[1];

            currIndex[1] = max(buy_now, buy_later);

            int sell_now = +prices[i] + next2Index[1];
                    
            int sell_later =  0 + nextIndex[0];

            currIndex[0] = max(sell_now, sell_later);
            
            
            next2Index = nextIndex;
            nextIndex = currIndex;
        }
        
        return nextIndex[1];
    }
};

