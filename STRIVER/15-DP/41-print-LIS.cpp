//LENGTH OF LIS
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

//PRINT LIS
//create a hash vector that stores the previous index of this element had they been in LIS.
//iterate through the indices stored in hash vector.

vector<int> printingLongestIncreasingSubsequence(vector<int> nums, int n) {

    vector<int> dp(n, 1);
    vector<int> hash(n);
	
	for(int i = 0; i < n; i++)
		hash[i] = i;

    int maxi = 0;
    int lastIndex = n - 1;

    for(int i = 0; i < n; i++)
    {
        for(int prev = 0; prev <= i - 1; prev++)
        {
            if(nums[prev] < nums[i])
			{
				if(1 + dp[prev] > dp[i])
				{
					hash[i] = prev;
					dp[i] = 1 + dp[prev];
				}
			}
        }
            
		if(dp[i] > maxi)
		{
			maxi = dp[i];
			lastIndex = i; //first index which including itself has max inc susbeq length.
		}
    }

	vector<int> ans;
	ans.push_back(nums[lastIndex]); //this will actually be the last element in the LIS.

	while(hash[lastIndex] != lastIndex)
	{
		lastIndex = hash[lastIndex];
		ans.push_back(nums[lastIndex]);
	}

	reverse(ans.begin(), ans.end());
	
	return ans;
}

