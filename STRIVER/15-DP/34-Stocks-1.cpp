//for every selling on ith day, you should buy it on the minimum price from 0th to (i - 1)th day

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        
        for(int i = 0; i < prices.size(); i++)
        {
            int minPrice = min(minPrice, prices[i]);
            
            int profit = prices[i] - minPrice;
            
            maxProfit  = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
};
