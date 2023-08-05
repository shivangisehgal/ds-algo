bool rec(int n, int k, vector<int> &arr)
{
    if(k == 0)
        return true;
    
    if(n == 0)
        return (arr[0] == k);
    
    bool not_take = rec(n - 1, k, arr);
    
    if(not_take == true)
        return true;
    
    bool take = false;
    
    if(k >= arr[n])
        take = rec(n - 1, k - arr[n], arr);
    
    return (not_take || take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return rec(n - 1, k, arr);
}

//memo
#include <bits/stdc++.h> 

bool rec(int i, int k, vector<vector<int>> &dp, vector<int> &arr)
{
    if(k == 0)
        return true;
    
    if(i == 0)
        return (arr[0] == k);
    
    if(dp[i][k] != -1)
        return dp[i][k];

    bool not_take = rec(i - 1, k, dp, arr);
    
    bool take = false;
    
    if(k >= arr[i])
        take = rec(i - 1, k - arr[i], dp, arr);
    
    return dp[i][k] = (take || not_take);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {


    //dp[N + 1][N + 1] => dp[ind][target]
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return rec(n - 1, k, dp, arr);
}

//tabu
bool subsetSumToK(int n, int k, vector<int> &arr) {


    //dp[N + 1][N + 1] => dp[ind][target]
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    //base cases
    //1. if target = 0, for all elements, answer = true

    for(int i = 0; i < n; i++)
        dp[i][0] = true;
    
    //2. if i = 0, if target = arr[0], answer = true;
    if(k >= arr[0])
        dp[0][arr[0]] = true; 
    
    for(int i = 1; i < n; i++)
    {
        for(int target = 0; target <= k; target++)
        {
            bool not_take = dp[i - 1][target];
            bool take = false;

            if(target >= arr[i])
                take = dp[i - 1][target - arr[i]];

            dp[i][target] = not_take || take;
        }
    }

    return dp[n - 1][k];
}

//space opt
bool subsetSumToK(int n, int k, vector<int> &arr) {


    //dp[N + 1][N + 1] => dp[ind][target]
    
    vector<bool> prevIndex(k + 1, false);
    vector<bool> currIndex(k + 1, false);

    //base cases
    //1. if target = 0, for all elements, answer = true => For All rows, first element is true

    prevIndex[0] = currIndex[0] = true;
    
    //2. if i = 0, if target = arr[0], answer = true;
    if(k >= arr[0])
        prevIndex[arr[0]] = true; 
    
    for(int i = 1; i < n; i++)
    {
        for(int target = 0; target <= k; target++)
        {
            bool not_take = prevIndex[target];
            bool take = false;

            if(target >= arr[i])
                take = prevIndex[target - arr[i]];

            currIndex[target] = not_take || take;
        }

        prevIndex = currIndex;
    }

    return prevIndex[k];
}
