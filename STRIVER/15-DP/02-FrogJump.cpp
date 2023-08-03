//recursion
int rec(int i, vector<int> &h)
{
    if(i == 0)
        return 0; //no energy needed
    
    int l = rec(i - 1, h) + abs(h[i] - h[i - 1]);

    int r = INT_MAX;

    if(i > 1)
        r = rec(i - 2, h) + abs(h[i] - h[i - 2]);
    
    return min(l, r);
}


int frogJump(int n, vector<int> &heights)
{
    return rec(n - 1, heights);
}

//memoization
//Top-Down from n to 1 or n - 1 to 0
int rec(int i, vector<int> &dp, vector<int> &h)
{
    if(i == 0)
        return 0; //no energy needed
    
    if(dp[i] != -1)
        return dp[i];

    int l = rec(i - 1, dp, h) + abs(h[i] - h[i - 1]);

    int r = INT_MAX;

    if(i > 1)
        r = rec(i - 2, dp, h) + abs(h[i] - h[i - 2]);
    
    return dp[i] = min(l, r);
}


int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);

    for(int i = 0; i < n; i++)
        dp[i] = -1;
    
    return rec(n - 1, dp, heights);
}

//tab
int frogJump(int n, vector<int> &h)
{
    vector<int> dp(n, -1);

    for(int i = 0; i < n; i++)
        dp[i] = -1;
    
    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int l = dp[i - 1] + abs(h[i] - h[i - 1]);

        int r = INT_MAX;

        if(i > 1)
            r = dp[i - 2] + abs(h[i] - h[i - 2]);
        
        dp[i] = min(l, r);
    }

    return dp[n - 1];
}

//space opt
int frogJump(int n, vector<int> &h)
{

    int prev2 = 0;
    int prev = 0;
    int curr;

    for(int i = 1; i < n; i++)
    {
        int l = prev + abs(h[i] - h[i - 1]);

        int r = INT_MAX;

        if(i > 1)
            r = prev2 + abs(h[i] - h[i - 2]);
        
        curr = min(l, r);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}
