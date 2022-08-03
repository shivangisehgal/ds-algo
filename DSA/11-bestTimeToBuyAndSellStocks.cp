//BRUTE
//Find max(prices[j] - prices[i]) for every j > i
//TC: O(N^2), SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxprofit = 0;
        for (int i = 0; i < prices.size() - 1; i++) 
        {
            for (int j = i + 1; j < prices.size(); j++) 
            {
                int profit = prices[j] - prices[i];
                
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }
};


//OPTIMAL 
//One Pass
//TC: O(N), SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        
        int minPrice = prices[0];
        int maxProfit = 0;
        int profit = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(prices[i] < minPrice)
                minPrice = prices[i]; //smallest valley
            
            profit = prices[i] - minPrice; 
            
            maxProfit = max(maxProfit, profit); //largest peak
        }
        
        return maxProfit;
    }
};

//FOLLOW UP: Try to solve it using Kadane's algorithm
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
//Hint: What if it was an array of difference of prices between a pair of consecutive days..
