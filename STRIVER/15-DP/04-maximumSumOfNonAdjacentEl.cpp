int rec(int i, vector<int> &dp, vector<int> &nums)
{

    if (i < 0)
        return 0;

    if (i == 0)
        return nums[i]; 

    if (dp[i] != -1)
        return dp[i];

    // pick and skip
    int l = nums[i] + rec(i - 2, dp, nums);

    // not pick
    int r = rec(i - 1, dp, nums);

    return dp[i] = max(l, r);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size(), -1);

    for(int i = 0; i < nums.size(); i++)
        dp[i] = -1;
    
    return rec(nums.size() - 1, dp, nums);
}


//Tab
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, -1);

        for(int i = 0; i < n; i++)
            dp[i] = -1;
        
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            int l = nums[i];
            
            if(i > 1)
                l += dp[i - 2];
            
            int r = dp[i - 1];
            
            dp[i] = max(l, r);
        }
        
        return dp[n - 1];
    }
};

//space opt
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        int prev2 = 0;
        int prev = nums[0];
        int curr;
        
        for(int i = 1; i < n; i++)
        {
            int l = nums[i];
            
            if(i > 1)
                l += prev2;
            
            int r = prev;
            
            curr = max(l, r);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};
