//BRUTE
//CALCULATE ALL PRICE DIFFERENCES, AND THEN CALCULATE MAX PROFIT
//TC: O(N^2) //SC: O(1)

//OPTIMAL
//TC: O(N) //SC: O(1)
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
