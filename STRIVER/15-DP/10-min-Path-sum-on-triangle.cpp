//the start is fixed but the end point is variable.
//so starting from n to 1, we would need to use a loop and call the (recursion) function for all elements of the last row.
//so do 1 to n recursion

//2
//3 4
//6 5 7
//4 1 8 3


//starting from 1 to n, (i, j) can go to 1. (i + 1, j) or 2. (i + 1, j + 1)

//memo
int rec(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& triangle)
{
    if(row == triangle.size() - 1)
        return triangle[row][col];
    
    if(dp[row][col] != -1)
        return dp[row][col];
    
    int down = triangle[row][col] + rec(row + 1, col, dp, triangle);
    int down_right = triangle[row][col] + rec(row + 1, col + 1, dp, triangle);
    
    return dp[row][col]  = min(down, down_right);
}


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        return rec(0, 0, dp, triangle);
    }
};

//tab
//tab loop is always opposite of memo

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int j = n - 1; j >= 0; j--)
            dp[n - 1][j] = triangle[n - 1][j];
        
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                int down = 0;
                int down_right = 0;
                
                down = triangle[i][j] + dp[i + 1][j];
                down_right = triangle[i][j] + dp[i + 1][j + 1];
                
                dp[i][j] = min(down, down_right);
            }
        }
        
        return dp[0][0];
    }
};

//space opt
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        vector<int> nextRow(n, 0);
    
        for(int j = n - 1; j >= 0; j--)
            nextRow[j] = triangle[n - 1][j];
        
        for(int i = n - 2; i >= 0; i--)
        {
            vector<int> currRow(n, 0);
            
            for(int j = i; j >= 0; j--)
            {
                int down = 0;
                int down_right = 0;
                
                down = triangle[i][j] + nextRow[j];
                down_right = triangle[i][j] + nextRow[j + 1];
                
                currRow[j] = min(down, down_right);
            }
            
            nextRow = currRow;
        }
        
        return nextRow[0];
    }
};
