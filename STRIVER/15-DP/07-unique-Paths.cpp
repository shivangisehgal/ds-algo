//memo
class Solution {
public:
    int rec(int m, int n, vector<vector<int>>& dp)
    {
        if(m == 0 && n == 0)
            return 1;
        
        if(m < 0 || n < 0)
            return 0;

        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = (rec(m - 1, n, dp) + rec(m, n - 1, dp));
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return rec(m - 1, n - 1, dp);
    }
};

//tab
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, 0)); //note, dp should be initialized to 0
        
        dp[0][0] = 1;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i > 0)
                    dp[i][j] += dp[i - 1][j];
                
                if(j > 0)
                     dp[i][j] += dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

//space opt
class Solution {
public:
    int rec(int m, int n, vector<vector<int>>& dp)
    {
        if(m == 0 && n == 0)
            return 1;
        
        if(m < 0 || n < 0)
            return 0;
        
        return dp[m][n] = (rec(m - 1, n, dp) + rec(m, n - 1, dp));
    }
    
    int uniquePaths(int m, int n) {
        
        vector<int> prevRow(n, 0); //note, dp should be initialized to 0
        
        prevRow[0] = 1;
        
        for(int i = 0; i < m; i++)
        {
            vector<int> currRow(n, 0);
            
            for(int j = 0; j < n; j++)
            {
                currRow[j] += prevRow[j];
                
                if(j > 0)
                     currRow[j] += currRow[j - 1];
            }
            
            prevRow = currRow;
        }
        
        return prevRow[n - 1];
    }
};
