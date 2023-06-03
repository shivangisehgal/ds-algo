//Recurisvely solve for each empty element
//TC: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.
//SC: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.

class Solution {
public:
    
    bool isValid(char num, int r, int c, vector<vector<char>>& board)
    {
        for(int col = 0; col < 9; col++)
        {
            if(board[r][col] == num)
                return false;
        }
        
        for(int row = 0; row < 9; row++)
        {
            if(board[row][c] == num)
                return false;
        }
        
        int boxRow = 3 * (r / 3);
        int boxCol = 3 * (c / 3);
        
        for(int row = 0; row < 3; row++)
        {
            for(int col = 0; col < 3; col++)
            {
                if(board[boxRow + row][boxCol + col] == num)
                return false;
            }
        }
        
        
        return true;
    }
    
    bool helper(vector<vector<char>>& board)
    {
        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.')
                {
                    for(char num = '1'; num <= '9'; num++)
                    {
                        if(isValid(num, r, c, board))
                        {
                            board[r][c] = num;
                            
                            if(helper(board) == true) //call for and look next element
//return one instance type of recursion.
                                return true;
                            
                            board[r][c] = '.'; //since number that we filled up, did not lead to correct sudoku, we need to remove it and check for another number
                        }
                    }
                    
                    //none of the numbers(1-9) could be placed at the empty location, so return false
                    return false;
                }
            }
        }
        
        //if no element is empty
        return true;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        bool isValid = helper(board);
    }
};
