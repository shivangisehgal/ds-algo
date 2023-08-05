//start point is variable and end point is also variable.
//so we need to run a loop and call this function for every element of last row.
//so the function caters to variable-fixed.

class Solution {
public:
    
    int rec(int row, int col, vector<vector<int>>&dp, vector<vector<int>>& matrix)
    {
        
        if(col < 0 || col >= matrix[0].size())
            return 1e9; //or INT_MAX;
        
        if(row == 0)
            return matrix[0][col];
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        //three directions asked, diagonally left, diagonally right, down
        //=> upr, upl, up
        
        int upr = matrix[row][col] + rec(row - 1, col + 1, dp, matrix);
        int upl = matrix[row][col] + rec(row - 1, col - 1, dp, matrix);
        int up = matrix[row][col] + rec(row - 1, col, dp, matrix);
        
        return dp[row][col] = min(up, min(upr, upl));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        int mini = 1e9;
        
        for(int j = 0; j < n; j++)
            mini = min(mini, rec(m - 1, j, dp, matrix));
        
        return mini;
    }
};

//space opt
class Solution {
public:


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> prevRow(n, 0);
        
        for (int col = 0; col < n; col++) 
        {
            prevRow[col] = matrix[0][col];
        }
        
        int mini = 1e9;
        
        for (int i = 1; i < m; i++) 
        {
            vector<int> currRow(n, 0);
            
            for (int j = 0; j < n; j++) 
            {
                int down = 1e9;
                int downleft = 1e9;
                int downright = 1e9;
                
                
                down = matrix[i][j] + prevRow[j];
                    
                if (j > 0)
                    downleft = matrix[i][j] + prevRow[j - 1];
                    
                if (j < n - 1)
                    downright = matrix[i][j] + prevRow[j + 1];
                
                currRow[j] = min(down, min(downright, downleft));
            }
            
            prevRow = currRow;
        }
        
        for (int col = 0; col < n; col++) 
        {
            mini = min(mini, prevRow[col]); 
        }
        
        return mini;
    }
};
