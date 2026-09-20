class Solution {
    public int maxProfit(int[] prices) {
        int maxi = 0;
        int mini = prices[0];

        for(int i = 0; i < prices.length; i++){
            if(prices[i] >= mini)
                maxi = Math.max(maxi, prices[i] - mini); //maxi, prices[i] - mini)
            else
                mini = prices[i];
        }

        return maxi;
    }
}