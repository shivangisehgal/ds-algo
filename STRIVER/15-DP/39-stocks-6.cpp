//fee charged, either during buy or sell
//memo
class Solution {
private:
    int rec(int i, int buy, vector<vector<int>>& dp, int fee, vector<int>& prices)
    {
        //base case
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int profit = INT_MIN;
        
        if(buy == 1)
        {
            int buy_now = -prices[i] + rec(i + 1, 0, dp, fee, prices);
            int buy_later =  0 + rec(i + 1, 1, dp, fee, prices);
            
            profit = max(buy_now, buy_later);
        }
        
        else //sell
        {
            int sell_now = +prices[i] - fee + rec(i + 1, 1, dp, fee, prices);
            int sell_later =  0 + rec(i + 1, 0, dp, fee, prices);
            
            profit = max(sell_now, sell_later);
        }
        
        return dp[i][buy] = profit;
    }
    
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return rec(0, 1, dp, fee, prices);
    }
};

//tabu
class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        //rec: 0 to n
        //iter: n to 0
                
        for(int i = n - 1; i >= 0; i--)
        {
            
                int buy_now = -prices[i] + dp[i + 1][0];
                int buy_later =  0 + dp[i + 1][1];

                dp[i][1] = max(buy_now, buy_later);

                int sell_now = +prices[i] - fee + dp[i + 1][1];
                int sell_later =  0 + dp[i + 1][0];

                dp[i][0] = max(sell_now, sell_later);

        }
        
        return dp[0][1];
    }
};

//space opt.
class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<int> nextIndex(2, 0);
        vector<int> currIndex(2, 0);
        
        //rec: 0 to n
        //iter: n to 0
                
        for(int i = n - 1; i >= 0; i--)
        {
            
                int buy_now = -prices[i] + nextIndex[0];
                int buy_later =  0 + nextIndex[1];

                currIndex[1] = max(buy_now, buy_later);

                int sell_now = +prices[i] - fee + nextIndex[1];
                int sell_later =  0 + nextIndex[0];

                currIndex[0] = max(sell_now, sell_later);
            
                nextIndex = currIndex;
        }
        
        return nextIndex[1];
    }
};
