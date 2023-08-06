//given a rod of length n, and an array of length n containing costs associated to each length (1 to 5)
//return the maximum cost obtaining by cutting the cost into sections.
//n = 5 -> 0, 5 | 1, 4 | 2, 3 | 1, 2, 2 | 1, 1, 3 etc.

int rec(int i, int length, vector<vector<int>>& dp, vector<int> &price)
{
	//base case
	if(i == 0)
	{
		int k = length / (i + 1);
		return k * price[i];
	}

	if(dp[i][length] != -1)
		return dp[i][length];

	int not_pick = rec(i - 1, length, dp, price);
	int pick = -1e8;

	if(i + 1 <= length)
		pick = price[i] + rec(i, length - i - 1, dp, price);
	
	return dp[i][length] = max(not_pick, pick);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int>(n + 1, -1));

	return rec(n - 1, n, dp, price);
}
