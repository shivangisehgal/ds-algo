//Q. return length of longest common subarray.
//if a[i] and b[j] not equal, length of comm subaray till i in nums1 and j in nums2 = 0;
//if yes, check if previous were equal, add that + 1.

//Do space opt. on ur own
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int maxi = 0;
        
        /*--------------------MODIFIED DP ARRAY OF LCS--------------------*/
        
         vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        for(int i = 0; i <= n1; i++)
            dp[i][0] = 0;
            
        for(int i = 0; i <= n2; i++)
            dp[0][i] = 0;
        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                if(nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxi = max(dp[i][j], maxi);
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return maxi;
    }
};
