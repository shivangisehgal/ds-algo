//rec
//TC: O(2^N)
//SC: O(N)

//memo
#include <bits/stdc++.h> 

//TC: O(2^N)
//SC: O(N)

int rec(int i, int maxWeight, vector<vector<int>>& dp, vector<int>& weight, vector<int>& value)
{
	//base case
	if(i == 0)
	{
		if(maxWeight >= weight[0])
			return value[0];
		else
			return 0;
	}

	if(dp[i][maxWeight] != -1)
		return dp[i][maxWeight];

	int not_pick = rec(i - 1, maxWeight, dp, weight, value);
	int pick = INT_MIN;

	if(weight[i] <= maxWeight)
		pick = value[i] + rec(i - 1, maxWeight - weight[i], dp, weight, value);
	
	return dp[i][maxWeight] = max(not_pick, pick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

	return rec(n - 1, maxWeight, dp, weight, value);
}

//tab
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

	for(int wt = 0; wt <= maxWeight; wt++)
	{
		if(weight[0] <= wt)
			dp[0][wt] = value[0];
	}

	for(int i = 1; i < n; i++)
	{
		for(int wt = 0; wt <= maxWeight; wt++)
		{
			int not_pick = dp[i - 1][wt];
			int pick = INT_MIN;

			if(weight[i] <= wt)
				pick = value[i] + dp[i - 1][wt - weight[i]];
			
			dp[i][wt] = max(not_pick, pick);
		}
	}

	return dp[n - 1][maxWeight];
}


//space opt.

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prevIndex(maxWeight + 1, 0);
	

	for(int wt = 0; wt <= maxWeight; wt++)
	{
		if(weight[0] <= wt)
			prevIndex[wt] = value[0];
	}

	for(int i = 1; i < n; i++)
	{
		vector<int> currIndex(maxWeight + 1, 0);
		
		for(int wt = 0; wt <= maxWeight; wt++)
		{
			int not_pick = prevIndex[wt];
			int pick = INT_MIN;

			if(weight[i] <= wt)
				pick = value[i] + prevIndex[wt - weight[i]];
			
			currIndex[wt] = max(not_pick, pick);
		}

		prevIndex = currIndex;
	}

	return prevIndex[maxWeight];
}
