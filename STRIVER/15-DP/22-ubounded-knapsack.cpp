//there is infite supply of each item now

//memo
int rec(int i, int maxWeight, vector<vector<int>>& dp, vector<int> &weight, vector<int> &profit)
{
    //base case
    if(i == 0)
    {
        if(maxWeight >= weight[0])
		{
            int k = maxWeight / weight[0];
            return k * profit[0];
        }
		else
			return 0;
    }

    if(dp[i][maxWeight] != -1)
        return dp[i][maxWeight];

    int not_pick = rec(i - 1, maxWeight, dp, weight, profit);
    int pick = -1e8;

    if(weight[i] <= maxWeight)
        pick = profit[i] + rec(i, maxWeight - weight[i], dp, weight, profit);
    
    return dp[i][maxWeight] = max(not_pick, pick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<vector<int>> dp(n , vector<int>(w + 1, -1));

    return rec(n - 1, w, dp, weight, profit);
}

//tabu

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<vector<int>> dp(n , vector<int>(w + 1, 0));

    for(int wt = 0; wt <= w; wt++)
    {
        if(wt >= weight[0])
        {
            int k = wt / weight[0];
            dp[0][wt] = k * profit[0];
        }
    }

    for(int i = 1; i < n; i++)
    {
        for(int wt = 0; wt <= w; wt++)
        {
            int not_pick = dp[i - 1][wt];
            int pick = -1e8;

            if(weight[i] <= wt)
                pick = profit[i] + dp[i][wt - weight[i]];
            
            dp[i][wt] = max(not_pick, pick);
        }
    }

    return dp[n - 1][w];
}


//space opt.
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<int> prevIndex(w + 1, 0);
    vector<int> currIndex(w + 1, 0);

    for(int wt = 0; wt <= w; wt++)
    {
        if(wt >= weight[0])
        {
            int k = wt / weight[0];
            prevIndex[wt] = k * profit[0];
            currIndex[wt] = k * profit[0];
        }
    }

    for(int i = 1; i < n; i++)
    {
        for(int wt = 0; wt <= w; wt++)
        {
            int not_pick = prevIndex[wt];
            int pick = -1e8;

            if(weight[i] <= wt)
                pick = profit[i] + currIndex[wt - weight[i]];
            
            currIndex[wt] = max(not_pick, pick);
        }

        prevIndex = currIndex;
    }

    return prevIndex[w];
}
