class Solution {
    
     bool rec(int i, int j, int k, int m, int n, vector<vector<char>>& board, string word) {
         
        if (k == word.length()) 
        {
            return true;
        }
         
         if (i >= m || j >= n || j < 0 || i < 0) 
        {
            return false;
        }
        
        if (board[i][j] == '!' || board[i][j] != word[k]) 
        {
            return false;
        }
        
        char c = board[i][j];
        board[i][j] = '!';
         
        bool found = rec(i, j + 1, k + 1, m, n, board, word) ||
                     rec(i, j - 1, k + 1, m, n, board, word) ||
                     rec(i + 1, j, k + 1, m, n, board, word) ||
                     rec(i - 1, j, k + 1, m, n, board, word);
        //backtrack
        board[i][j] = c;
        
        return found;
     }
    
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        int k = 0;
        
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (board[i][j] == word[k]) {
                    if (rec(i, j, k, m, n, board, word))
                        return true;
                }
            }
        }
        
        return false;
    }
};
