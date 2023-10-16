//DFS is a depth first approach, it will explore all paths, and it might not be an efficient way, when we have to determine the minimum time
//use bfs, because that gives us level-wise, and only level-wise will give us the minimum time.
//TC: O(N * M) + O(4 * O * M)
//SC: O(N * M)
class Solution {
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int level = 0;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        
        int dr[4] = {-1, 0, 0, 1};
        int dc[4] = {0, -1, 1, 0};
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visited[i][j] == false && grid[i][j] == 2)
                {  
                    visited[i][j] = true;
                    q.push({{i, j}, 0});  
                }
            }
        }
        
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            
            level = f.second;
            
            int row = f.first.first;
            int col = f.first.second;
            
            for(int k = 0; k < 4; k++)
            {
                int r = row + dr[k];
                int c = col + dc[k];
                
                if(r >= 0 && c >= 0 && r <= n - 1 && c <= m - 1)
                {
                    if(visited[r][c] == false && grid[r][c] == 1)
                    {
                        visited[r][c] = true;
                        grid[r][c] = 2;

                        q.push({{r, c}, level + 1});
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return level;
    }
};
