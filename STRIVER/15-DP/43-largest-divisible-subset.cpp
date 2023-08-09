//[1 16 8 4]
//we require subsets and either ans[i] % ans[j] or vice versa should be true.
//better would be that each ans[j] % ans[j - 1] == 0. automatically would satisfy all. 
//and since we do not require subsequence, we can sort the array first, in this way, we'll have an increasing subsequence, now we only need to check for condition
//nums[i] % nums[prev] == 0

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> dp(n, 1);
        vector<int> hash(n);
        
        for(int i = 0; i < n; i++)
            hash[i] = i;
        //dp[n][j] = 0
       int maxlen = 0;
       int lastIndex = n - 1;
        
       for(int i = 0; i < n; i++)
       {
           for(int prev = 0; prev <= i - 1; prev++)
           {
               if(nums[i] % nums[prev] == 0)
               {
                   if(1 + dp[prev] > dp[i])
                   {
                       dp[i] = 1 + dp[prev];
                       hash[i] = prev;
                   }
               }
           }
           
           if(dp[i] > maxlen)
           {
               maxlen = dp[i];
               lastIndex = i;
           }
       }
        
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        
        return ans;
    }
};
