//greedy won't work
//curr sum = min(left + prev sum, up element + prev sum)
//memo
class Solution {
public:
    
    int rec(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(row == 0 && col == 0)
        {
            return grid[0][0];
        }
        
        if(row < 0 || col < 0)
           return 1e9; // or INT_MAX;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int up = grid[row][col] + rec(row - 1, col, dp, grid);
        int left = grid[row][col] + rec(row, col - 1, dp, grid);
        
        return dp[row][col] = min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return rec(m - 1, n - 1, dp, grid);
    }
};

//tab
//greedy won't work
//curr sum = min(left + prev sum, up element + prev sum)

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j]; //dp[0][0] = grid[0][0]
                
                else
                {
                    int up = 1e9;
                    int left = 1e9;

                    if(i > 0)
                        up = grid[i][j] + dp[i - 1][j];

                    if(j > 0)
                        left = grid[i][j] + dp[i][j - 1];

                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

//space opt

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> prevRow(n, 0);
        
        
        for(int i = 0; i < m; i++)
        {
            vector<int> currRow(n, 0);
                
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    currRow[j] = grid[i][j]; //dp[0][0] = grid[0][0]
                
                else
                {
                    int up = 1e9;
                    int left = 1e9;

                    if(i > 0)
                        up = grid[i][j] + prevRow[j];

                    if(j > 0)
                        left = grid[i][j] + currRow[j - 1];

                    currRow[j] = min(up, left);
                }
            }
            
            prevRow = currRow;
        }
        
        return prevRow[n - 1];
    }
};
