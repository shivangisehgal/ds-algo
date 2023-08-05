//let subsets have a sum S1 and S2
//=> S2 = S - S1
    
// abs(S1 - S2), min can be 0
// abs(S1 - S + S1) => abs(2S1 - S), min be 0
    
//range of S1 can be from 0 to S, 
// dp array obtained for subset sums tells you whether it is possible to have a subste whose sum is = (1 to target)
    
//from the dp array obtained for subset sums (where target is S, select that value of S1 which minimizes abs(2S1 - S)

int minSubsetSumDifference(vector<int>& nums, int n)
{
	int sum = 0;
        
        for(int i = 0; i < n; i++)
            sum += nums[i];
        
        int k = sum;
        int s1 = 0;
        int mini = 1e9;
        
        //dp[N + 1][N + 1] => dp[ind][target]
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        //base cases
        //1. if target = 0, for all elements, answer = true

        for(int i = 0; i < n; i++)
            dp[i][0] = true;

        //2. if i = 0, if target = arr[0], answer = true;
        if(k >= nums[0])
            dp[0][nums[0]] = true; 

        for(int i = 1; i < n; i++)
        {
            for(int target = 0; target <= k; target++)
            {
                bool not_take = dp[i - 1][target];
                bool take = false;

                if(target >= nums[i])
                    take = dp[i - 1][target - nums[i]];

                dp[i][target] = not_take || take;
            }
        }
        
        //from target to 1, check if dp[i] is valid, if yes, break.
        for(int target = 0; target <= k; target++)
        {
            if(dp[n - 1][target])
            {
                s1 = target;
                mini = min(mini, abs(s1 - (k - s1)));
            }
        }

        return mini;
}

