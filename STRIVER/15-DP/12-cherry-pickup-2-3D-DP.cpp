//memo

class Solution {
public:
    int rec(int i, int j1, int j2, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid)
    {
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
            return -1e8; //or INT_MIN
        
        if(i == grid.size() - 1) 
        {
            if(j1 == j2)
                return grid[i][j1]; //or grid[i][j2];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        int maxi = 0;
        
        for(int a = -1; a <= 1; a++)
        {
            for(int b = -1; b <= 1; b++)
            {
                if(j1 == j2)
                    maxi = max(maxi, grid[i][j1] + rec(i + 1, j1 + a, j2 + b, dp, grid));
                else
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + rec(i + 1, j1 + a, j2 + b, dp, grid));
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        //dp[rows][cols][cols]
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        
        return rec(0, 0, cols - 1, dp, grid);
    }
};

//tabu
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        //dp[rows][cols][cols]
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        
        
        for(int j1 = 0; j1 < cols; j1++)
        {
            for(int j2 = 0; j2 < cols; j2++)
            {
                if(j1 == j2)
                    dp[rows - 1][j1][j2] = grid[rows - 1][j1]; 
                else
                dp[rows - 1][j1][j2] = grid[rows - 1][j1] + grid[rows - 1][j2]; 
            }
        }
        
        
        for(int i = rows - 2; i >= 0; i--)
        {
           for(int j1 = cols - 1; j1 >= 0; j1--)
            {
                for(int j2 = cols - 1; j2 >= 0; j2--)
                {
                    int maxi = -1e8;
                    int val;
                    
                    for(int a = -1; a <= 1; a++)
                    {
                        for(int b = -1; b <= 1; b++)
                        {
                            if(j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            
                            if(j1 + a < 0 || j1 + a >= cols || j2 + b < 0 || j2 + b >= cols)
                                val = -1e8;
                            else
                                val += dp[i + 1][j1 + a][j2 + b];
                            
                            maxi = max(maxi, val);
                        }
                    }
                    
                    dp[i][j1][j2] = maxi;
                }
            } 
        }
        
        return dp[0][0][cols - 1];
    }
};

//space opt
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        //dp[rows][cols][cols]
        vector<vector<int>> prevRow(cols, vector<int>(cols, -1));
        
        
        for(int j1 = 0; j1 < cols; j1++)
        {
            for(int j2 = 0; j2 < cols; j2++)
            {
                if(j1 == j2)
                    prevRow[j1][j2] = grid[rows - 1][j1]; 
                else
                    prevRow[j1][j2] = grid[rows - 1][j1] + grid[rows - 1][j2]; 
            }
        }
        
        
        for(int i = rows - 2; i >= 0; i--)
        {
           
            vector<vector<int>> currRow(cols, vector<int>(cols, -1));
            
            for(int j1 = cols - 1; j1 >= 0; j1--)
            {
                for(int j2 = cols - 1; j2 >= 0; j2--)
                {
                    int maxi = -1e8;
                    int val;
                    
                    for(int a = -1; a <= 1; a++)
                    {
                        for(int b = -1; b <= 1; b++)
                        {
                            if(j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            
                            if(j1 + a < 0 || j1 + a >= cols || j2 + b < 0 || j2 + b >= cols)
                                val = -1e8;
                            else
                                val += prevRow[j1 + a][j2 + b];
                            
                            maxi = max(maxi, val);
                        }
                    }
                    
                    currRow[j1][j2] = maxi;
                }
            }
            
            prevRow = currRow;
        }
        
        return prevRow[0][cols - 1];
    }
};
