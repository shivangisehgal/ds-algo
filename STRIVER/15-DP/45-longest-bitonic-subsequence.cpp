//BITONIC SUBSEQUENCE: LIS, LDS OR (inc) -> (dec)


//Q. Minimum number of elements to be removed from array to make it a mountain (strictly bitonic) ARRAY.
//ans = total elements in array - elements in longest bitonic subsequence (provided, not a LIS or LDS)

class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {

      /**************LENGTH OF LONGEST BITONIC SUBSEQUENCE***************/
      
      int n = arr.size();
        
        vector<int> dp(n, 1);
        vector<int> dpRev(n, 1);
        
        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev <= i - 1; prev++)
            {
                if(arr[i] > arr[prev])
                {
                    dp[i] = max(1 + dp[prev], dp[i]);
                }
            }
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int prev = n - 1; prev >= i + 1; prev--)
            {
                if(arr[i] > arr[prev])
                {
                    dpRev[i] = max(1 + dpRev[prev], dpRev[i]);
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(dp[i] > 1 && dpRev[i] > 1) //question does not want onlt LIS or LDS.
                ans = max(ans, dp[i] + dpRev[i] - 1);
        }

      /**************LENGTH OF LONGEST BITONIC SUBSEQUENCE = ANS ***************/
        
        return n - ans;
    }
};
