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
