//memo
class Solution {
public:
    int rec(int i, int buy, int maxtrans, vector<vector<vector<int>>>& dp, vector<int>& prices)
    {
        if(maxtrans == 0)
            return 0;
        
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy][maxtrans] != -1)
            return dp[i][buy][maxtrans];
        
        int profit = INT_MIN;
        
        if(buy == 1)
        {
            int buy_now = -prices[i] + rec(i + 1, 0, maxtrans, dp, prices);
            int buy_later =  0 + rec(i + 1, 1, maxtrans, dp, prices);
            
            profit = max(buy_now, buy_later);
        }
        
        else //sell
        {
            int sell_now = +prices[i] + rec(i + 1, 1, maxtrans - 1, dp, prices); //selling done, decrease max transaction
            int sell_later =  0 + rec(i + 1, 0, maxtrans, dp, prices);
            
            profit = max(sell_now, sell_later);
        }
        
        return dp[i][buy][maxtrans] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        //dp[n][2][3]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return rec(0, 1, 2, dp, prices);
    }
};

//tabu
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        //dp[n][2][3]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

      
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= 1; j++)
            {
                for(int k = 1; k <= 2; k++)
                {
                    int profit = INT_MIN;
        
                    if(j == 1)
                    {
                        int buy_now = -prices[i] + dp[i + 1][0][k];
                        int buy_later =  0 + dp[i + 1][1][k];

                        profit = max(buy_now, buy_later);
                    }

                    else //sell
                    {
                        int sell_now = +prices[i] + dp[i + 1][1][k - 1]; //selling done, decrease max transaction
                        int sell_later =  0 + dp[i + 1][0][k];

                        profit = max(sell_now, sell_later);
                    }
                    
                    dp[i][j][k] = profit;
                }
            }
        }
        
        return dp[0][1][2];
    }
};

//space opt
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        //dp[n][2][3]
        
        vector<vector<int>> nextIndex(2, vector<int>(3, 0));
        vector<vector<int>> currIndex(2, vector<int>(3, 0));
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= 1; j++)
            {
                for(int k = 1; k <= 2; k++)
                {
                    int profit = INT_MIN;
        
                    if(j == 1)
                    {
                        int buy_now = -prices[i] + nextIndex[0][k];
                        int buy_later =  0 + nextIndex[1][k];

                        profit = max(buy_now, buy_later);
                    }

                    else //sell
                    {
                        int sell_now = +prices[i] + nextIndex[1][k - 1]; //selling done, decrease max transaction
                        int sell_later =  0 + nextIndex[0][k];

                        profit = max(sell_now, sell_later);
                    }
                    
                    currIndex[j][k] = profit;
                }
                
                
                nextIndex = currIndex;
            }
        }
         
        return nextIndex[1][2];
    }
};
