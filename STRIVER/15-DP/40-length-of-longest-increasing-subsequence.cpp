//NOTE THE LAST APPROACH.

//LIS Recursion - striver (0 to n)
class Solution {
public:
    int rec(int i, int prev_ind, vector<vector<int>>& dp, vector<int>& nums)
    {
        if(i == nums.size())
            return 0;
        
        if(dp[i][prev_ind + 1] != -1)
            return dp[i][prev_ind + 1];
        //pick
        if(prev_ind == -1|| nums[i] > nums[prev_ind])
        {
            return dp[i][prev_ind + 1] = max(1 + rec(i + 1, i, dp, nums), rec(i + 1, prev_ind, dp, nums)) ;
        }
        
        else
            return dp[i][prev_ind + 1] = rec(i + 1, prev_ind, dp, nums);
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int prev_ind = -1; 
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(0, prev_ind, dp, nums);
    }
};

//LIS RECURSION - Mine (n to 0)
class Solution {
public:
    int rec(int i, int prev_ind, vector<vector<int>>& dp, vector<int>& nums)
    {
        if(i < 0)
            return 0;
        
        if(dp[i][prev_ind] != -1)
            return dp[i][prev_ind];
        //pick
        if(prev_ind == nums.size() || nums[i] < nums[prev_ind])
        {
            return dp[i][prev_ind] = max(1 + rec(i - 1, i, dp, nums), rec(i - 1, prev_ind, dp, nums)) ;
        }
        
        else
            return dp[i][prev_ind] = rec(i - 1, prev_ind, dp, nums);
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int prev_ind = n; //10^4 + 1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(n - 1, prev_ind, dp, nums);
    }
};

//Tabu - TC: O(N^2) | SC: O(N^2)
class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
            
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = n - 1; i >= 0; i--)
        {
           for(int prev_ind = i - 1; prev_ind >= -1; prev_ind--)
           {
               
                int not_take = dp[i + 1][prev_ind + 1] ;
               
                int valid = 0;
               
                int take = 0;
                
                if(prev_ind == -1 || nums[i] > nums[prev_ind])
                {
                    take = 1 + dp[i + 1][i + 1]; 
                    valid = max(not_take, take);
                }
               
                //prev index is i only, but since there is shfite of index.


                dp[i][prev_ind + 1] = max(not_take, valid);
           }
            
        }
        
        return dp[0][-1 + 1];
    }
};

//space opt. -> TC: O(N^2) | SC: 2 * O(N)

//Tabu with TC: TC: O(N^2) | SC: O(N) - WILL BE REQUIRED IN CASE WE NEED TO PRINT THE LI SUBSEQUENCE.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int maxi = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev <= i - 1; prev++)
            {
                if(nums[prev] < nums[i])
                    dp[i] = max(1 + dp[prev], dp[i]);
                
            }
            
            maxi = max(maxi, dp[i]);
        }
        
        return maxi;
    }
};
