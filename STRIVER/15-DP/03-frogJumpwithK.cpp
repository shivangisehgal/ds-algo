//memo
int rec(int i, vector<int> &dp, vector<int> &h, int k)
{
    if(i == 0)
        return 0; //no energy needed
    
    if(dp[i] != -1)
        return dp[i];

    int l = rec(i - 1, dp, h, k) + abs(h[i] - h[i - 1]);

    int r = INT_MAX;

    for(int ind = 2; ind <= k; ind++)
    {
        if(i - ind >= 0)
            r = min(r, rec(i - ind, dp, h, k) + abs(h[i] - h[i - ind]));
    }
    
    return dp[i] = min(l, r);
}

int minimizeCost(int n, int k, vector<int> &height){

    // Write your code here.
    vector<int> dp(n, -1);

    for(int i = 0; i < n; i++)
        dp[i] = -1;
    
    return rec(n - 1, dp, height, k);
}


//tab
int minimizeCost(int n, int k, vector<int> &h){

    // Write your code here.
    vector<int> dp(n, -1);

    for(int i = 0; i < n; i++)
        dp[i] = -1;
    
    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int l = dp[i - 1] + abs(h[i] - h[i - 1]);

        int r = INT_MAX;

        for(int ind = 2; ind <= k; ind++)
        {
            if(i - ind >= 0)
                r = min(r, dp[i - ind] + abs(h[i] - h[i - ind]));
        }
        
        dp[i] = min(l, r);
    }

    return dp[n - 1];
}
