//Replace set of all O's that is surronded by X's on all sides.

//All sets which have a boundary O won't be converted, rest will be.

//DFS
class Solution {

    
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        
        if(!visited[i][j] && board[i][j] == 'O')
        {
            visited[i][j] = true;

            dfs(i + 1, j, board, visited);
            dfs(i, j + 1, board, visited);
            dfs(i - 1, j, board, visited);
            dfs(i, j - 1, board, visited);
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();        
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
            
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O' && visited[0][j] == false)
            {
                    dfs(0, j, board, visited);
            }
            
            if(board[m - 1][j] == 'O' && visited[m - 1][j] == false)
            {
                    dfs(m - 1, j, board, visited);
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O' && visited[i][0] == false)
            {
                    dfs(i, 0, board, visited);
            }
            
            if(board[i][n - 1] == 'O' && visited[i][n - 1] == false)
            {
                    dfs(i, n - 1, board, visited);
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && visited[i][j] == false)
                   board[i][j] = 'X'; 
            }
        }
    }
};


//DFS
class Solution {
    
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();        
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        queue<pair<int, int>> q;
        
        int dr[4] = {-1, 0, 0, 1};
        int dc[4] = {0, -1, 1, 0};
        
    
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O' && visited[0][j] == false)
            {
                    visited[0][j] = true;
                    q.push({0, j});
            }
            
            if(board[m - 1][j] == 'O' && visited[m - 1][j] == false)
            {
                    visited[m - 1][j] = true;
                    q.push({m - 1, j});
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O' && visited[i][0] == false)
            {
                    visited[i][0] = true;
                    q.push({i, 0});
            }
            
            if(board[i][n - 1] == 'O' && visited[i][n - 1] == false)
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
                
                if(r >= 0 and c >= 0 and r < m and c < n and board[r][c] == 'O' and visited[r][c] == false)
                {
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
            
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && visited[i][j] == false)
                   board[i][j] = 'X'; 
            }
        }
        
        
    }
};
