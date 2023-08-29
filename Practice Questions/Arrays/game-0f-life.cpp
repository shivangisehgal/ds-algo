class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        //0 to 1 ka switch, 2
        //1 to 0 ka switch, -1
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                
                int liveNeighbors = 0;
                    
                for(int x = max(i - 1, 0); x <= min(i + 1, m - 1); x++) 
                {
                    for(int y = max(j - 1, 0); y <= min(j + 1, n - 1); y++) 
                    {
                        if(x != i || y != j) 
                        {
                            if(board[x][y] == 1 || board[x][y] == -1) 
                                    liveNeighbors++;
 
                        }
                    }
                }
                
                if(board[i][j] == 0 && liveNeighbors == 3) //dead
                    board[i][j] = 2;
                
                else if(board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
                    board[i][j] = -1;
            
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                
                else if(board[i][j] == -1)
                    board[i][j] = 0;
            }
        }
    }
};
