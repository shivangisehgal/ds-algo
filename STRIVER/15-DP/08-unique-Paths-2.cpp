//memo
class Solution {
public:
     int rec(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid)
    {
         
        if(m < 0 || n < 0)
            return 0;
         
        if(obstacleGrid[m][n] == 1) 
            return 0;  //contribution by obstacle will always be 0
        
        if(m == 0 && n == 0)
            return 1;
         
        if(dp[m][n] != -1)
            return dp[m][n];
         
        int up = rec(m - 1, n, dp, obstacleGrid);
        int left = rec(m, n - 1, dp, obstacleGrid);
        
        
        return dp[m][n] = (up + left);
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, - 1));
        
        return rec(m - 1, n - 1, dp, obstacleGrid);
    }
};

//tab
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = 1;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                
                else
                {
                    if(i > 0)
                        dp[i][j] += dp[i - 1][j];
                    
                     if(j > 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }
        
        
        return dp[m - 1][n - 1];
    }
};


//space opt
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> prevRow(n, 0);
        
        prevRow[0] = 1;
        
        for(int i = 0; i < m; i++)
        {
            vector<int> currRow(n, 0);
            
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    currRow[j] = 0; //not necessary, can use continue
                
                else
                {
                    currRow[j] += prevRow[j];
                    
                     if(j > 0)
                        currRow[j] += currRow[j - 1];
                }
            }
            
            prevRow = currRow;
        }
        
        
        return prevRow[n - 1];
    }
};
