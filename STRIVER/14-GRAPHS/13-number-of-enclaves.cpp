//count all 1s which are not connect to boundary

class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        
        int m = board.size();        
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        queue<pair<int, int>> q;
        
        int dr[4] = {-1, 0, 0, 1};
        int dc[4] = {0, -1, 1, 0};
        
    
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 1 && visited[0][j] == false)
            {
                    visited[0][j] = true;
                    q.push({0, j});
            }
            
            if(board[m - 1][j] == 1 && visited[m - 1][j] == false)
            {
                    visited[m - 1][j] = true;
                    q.push({m - 1, j});
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 1 && visited[i][0] == false)
            {
                    visited[i][0] = true;
                    q.push({i, 0});
            }
            
            if(board[i][n - 1] == 1 && visited[i][n - 1] == false)
            {
                    visited[i][n - 1] = true;
                    q.push({i, n - 1});
            }
        }
        
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            int row = p.first;
            int col = p.second;
            
            for(int i = 0; i < 4; i++)
            {
                int r = row + dr[i];
                int c = col + dc[i];
                
                if(r >= 0 and c >= 0 and r < m and c < n and board[r][c] == 1 and visited[r][c] == false)
                {
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
            
        }
        
        int count = 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1 && visited[i][j] == false)
                   count++;
            }
        }
        
        return count;
    }
};
