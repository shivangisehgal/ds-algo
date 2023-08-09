//similar to stocks-3, just max 2 has been changed to max k.
//tabu
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        int profit;
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= 1; j++)
            {
                for(int maxtrans = 1; maxtrans <= k; maxtrans++)
                {
                    if(j == 1) //buy
                    {
                        int buy_now = -prices[i] + dp[i + 1][0][maxtrans];
                        int buy_later = 0 + dp[i + 1][1][maxtrans];
                        
                        profit = max(buy_now, buy_later);
                    }
                    
                    else
                    {
                        int sell_now = +prices[i] + dp[i + 1][1][maxtrans - 1];
                        int sell_later = 0 + dp[i + 1][0][maxtrans];
                        
                        profit = max(sell_now, sell_later);
                    }
                    
                    dp[i][j][maxtrans] = profit;
                }
            }
        }
        
        return dp[0][1][k];
    }
};

//space opt
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> nextIndex(2, vector<int>(k + 1, 0));
        vector<vector<int>> currIndex(2, vector<int>(k + 1, 0));
        
        int profit;
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= 1; j++)
            {
                for(int maxtrans = 1; maxtrans <= k; maxtrans++)
                {
                    if(j == 1) //buy
                    {
                        int buy_now = -prices[i] + nextIndex[0][maxtrans];
                        int buy_later = 0 + nextIndex[1][maxtrans];
                        
                        profit = max(buy_now, buy_later);
                    }
                    
                    else
                    {
                        int sell_now = +prices[i] + nextIndex[1][maxtrans - 1];
                        int sell_later = 0 + nextIndex[0][maxtrans];
                        
                        profit = max(sell_now, sell_later);
                    }
                    
                    currIndex[j][maxtrans] = profit;
                }
            }
            
            nextIndex = currIndex;
        }
        
        return nextIndex[1][k];
    }
};
