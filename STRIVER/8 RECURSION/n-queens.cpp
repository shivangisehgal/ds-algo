//BRUTE
//Create a vector<string> which is an nxn matrix. Use backtracking to choose a place to put Q, for each column
//Make sure that place is safe to put Q by making a function which checks the edge cases.

// TC: Exponential in nature, since we are trying out all ways. Nearly O(N! * N) 
// SC: O(N^2)

class Solution {
public:
    
    bool isSafe(int row, int col, vector<string>& board, int n)
    {
        //a queen can attack in 8 directions
        //since we're calling this before inserting
        //that means, there won't be queen as of now that will be ahead of it in the board
        //ie, diagonal-up forward, diagonal-down forward, forward and down are not needed to be checked.
        //and since, queen is only being placed in the column once, we need not check for UP as well
        //so we only need to check whether there is a queen on any element on STRAGHT BACKWARD, DIAGONAL UP BACKWARD, DIAGONAL DOWN BACKWARD
        
        
        int dupRow = row;
        int dupCol = col;
        
        //STRAIGHT BACKWARD
        while(col > 0)
        {
            col--;
            
            if(board[row][col] == 'Q')
                return false;
        }
        
        col = dupCol;
        
        //DIAGONAL-UP BACKWARD
        while(row > 0 and col > 0)
        {
            row--;
            col--;
            if(board[row][col] == 'Q')
                return false;
        }
        
        
        row = dupRow;
        col = dupCol;
        
        while(row < n - 1 and col > 0)
        {
            row++;
            col--;
            if(board[row][col] == 'Q')
                return false;
        }
        
        return true;
    }
    
    
    void helper(int col, int n, vector<string>& board, vector<vector<string>>& ans)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                helper(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // vector of matrices of size n x n
        vector<string> board(n); //matrix of size n x n
        string s(n, '.'); //default value of each row
        
        for(int i = 0; i < n; i++)
        {
            board[i] = s; 
        }
        
        helper(0, n, board, ans);
        
        return ans;
        
    }
  
//OPTIMIZED
//TC: Exponential. since we are trying out all ways, to be precise it is O(N! * N).
//SC: O(N)
class Solution {
public:
    
    //we can create vector maps for marking left, upper left and lower left diagonals
    //through maths and observations
    //when mapped from 2D to a single array,
    //indices for the vectors would be:
    //for left -> (row)
    //for lower left diagonal -> all elements in the diagonal will have an index of (row + col)
    //for upper left diagonal -> all elements in the diagonal will have an index of (n - 1 + col - row)
    void helper(int col, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& lowerLeftDiagonal, vector<int>& upperLeftDiagonal)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(leftRow[row] == 0 and lowerLeftDiagonal[row + col] == 0 and upperLeftDiagonal[n - 1 + col - row] == 0)
            {
                leftRow[row] = 1; 
                lowerLeftDiagonal[row + col] = 1;
                upperLeftDiagonal[n - 1 + col - row] = 1;
                
                board[row][col] = 'Q';
                
                helper(col + 1, n, board, ans, leftRow, lowerLeftDiagonal, upperLeftDiagonal);
                
                board[row][col] = '.';
                
                leftRow[row] = 0; 
                lowerLeftDiagonal[row + col] = 0;
                upperLeftDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // vector of matrices of size n x n
        vector<string> board(n); //matrix of size n x n
        string s(n, '.'); //default value of each row
        
        for(int i = 0; i < n; i++)
        {
            board[i] = s; 
        }
        
        vector<int> leftRow(n, 0);
        vector<int> lowerLeftDiagonal(2 * n - 1, 0);
        vector<int> upperLeftDiagonal(2 * n - 1, 0);
        helper(0, n, board, ans, leftRow, lowerLeftDiagonal, upperLeftDiagonal);
        
        return ans;
        
    }
};
