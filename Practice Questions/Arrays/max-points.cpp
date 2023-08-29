//min subarray sum of size n - k

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        
        int sum = 0;
        
         for (int i = 0; i < n - k; i++)
            sum += cardPoints[i];

        int minSum = sum;
        
        for (int i = n - k; i < n; i++)
        {
            sum += cardPoints[i] - cardPoints[i - (n - k)];
            minSum = min(minSum, sum);
        }
        
        sum = 0;
        
        for(int i = 0; i < n; i++)
            sum += cardPoints[i];
        
        return (sum - minSum);
    }
};
