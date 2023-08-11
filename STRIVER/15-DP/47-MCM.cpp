//Partition DP, refer notes

int rec(int i, int j, int* arr, int n)
{
    if(i == j)
        return 0;
    
    int mini = 1e9;

    for(int k = i; k <= j - 1; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j];

        steps += rec(i, k, arr, n) + rec(k + 1, j, arr, n);

        mini = min(mini, steps);
    }

    return mini;
}


int matrixChainMultiplication(int* arr, int n) {

    //SIZE OF ARR IS GIVEN AS n + 1
    int N = n + 1;
    
    return rec(1, N - 1, arr, N);
}

//memo
#include<bits/stdc++.h>

int rec(int i, int j, vector<vector<int>>& dp, int* arr, int n)
{
    if(i == j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;

    for(int k = i; k <= j - 1; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j];

        steps += rec(i, k, dp, arr, n) + rec(k + 1, j, dp, arr, n);

        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}


int matrixChainMultiplication(int* arr, int n) {

    //SIZE OF ARR IS GIVEN AS n + 1
    int N = n + 1;
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return rec(1, N - 1, dp, arr, N);
}

//tabu
#include<bits/stdc++.h>


int matrixChainMultiplication(int* arr, int n) {

    //SIZE OF ARR IS GIVEN AS n + 1
    int N = n + 1;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    int mini = 1e9;
    //dp[i][i] = 0

    for(int i = N - 1; i >= 1; i--)
    {
        for(int j = i + 1; j <= N - 1; j++)
        {
            mini = 1e9;
            
            for(int k = i; k <= j - 1; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j];
                steps += dp[i][k] + dp[k + 1][j];

                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }
    
    return dp[1][N - 1];
}
