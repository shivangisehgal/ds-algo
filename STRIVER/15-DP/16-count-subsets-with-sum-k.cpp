//recursion
int rec(int i, int k, vector<int>& arr)
{
	if(i == 0)
	{
		if(arr[0] == k || k == 0)
			return 1;

		return 0;
	}

	int not_pick = 0;
	int pick = 0;

	not_pick = rec(i - 1, k, arr);
	
	if(arr[i] <= k)
		pick = rec(i - 1, k - arr[i], arr);
  
	int m = 1e9 + 7;
	return (not_pick + pick) % m;
}

int findWays(vector<int> &arr, int k) 
{
    int n = arr.size();
    int m = 1e9 + 7;
    return rec(n - 1, k, arr) % m;
}


int rec(int i, int k, vector<vector<int>>& dp, vector<int>& arr)
{
	if(i == 0)
	{
		if(arr[0] == k || k == 0)
			return 1;
		else
		return 0;
	}

	if(dp[i][k] != -1)
		return dp[i][k];

	int not_pick = 0;
	int pick = 0;

	not_pick = rec(i - 1, k, dp, arr);
	
	if(arr[i] <= k)
		pick = rec(i - 1, k - arr[i], dp, arr);
	
	int m = 1e9 + 7; 
	return dp[i][k] = (not_pick + pick) % m;
}

int findWays(vector<int> &arr, int k) 
{
    int n = arr.size();
	  int m = 1e9 + 7;
	vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return rec(n - 1, k, dp, arr) % m;
}


// space opt.
int findWays(vector<int> &arr, int k) 
{
    int n = arr.size();
	int m = 1e9 + 7;
	
	vector<int> prevIndex(k + 1, 0);
	vector<int> currIndex(k + 1, 0);


	prevIndex[0] = 1;
	currIndex[0] = 1;

	if(arr[0] <= k)
		prevIndex[arr[0]] = 1;
		currIndex[arr[0]] = 1;

	for(int i = 1; i < n; i++)
	{
		for(int target = 0; target <= k; target++)
		{
			int not_pick = 0;
			int pick = 0;

			not_pick = prevIndex[target];

			if(arr[i] <= target)
				pick = prevIndex[target - arr[i]];
			
			currIndex[target] = (not_pick + pick) % m;
		}

		prevIndex = currIndex;

	}

    return prevIndex[k] % m;
}
