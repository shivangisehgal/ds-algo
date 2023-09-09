//on gfg - 8 directions, on leetcode - 4 directions
//count components in matrix => perform bfs/dfs traversal on the matrix (consider all 8 directions)

//BFS (gfg)
class Solution {
  public:
  
  void bfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid)
  {
      
    int n = grid.size();
    int m = grid[0].size();
    
      queue<pair<int, int>> q;
      
      visited[i][j] = true;
      q.push({i, j});

     while(!q.empty())
     {
        auto v = q.front();
        q.pop();

        int row = v.first;
        int col = v.second;

        for(int r = max(0, row - 1); r <= min(n - 1, row + 1); r++)
        {
            for(int c = max(0, col - 1); c <= min(m - 1, col + 1); c++)
            {
                if(visited[r][c] == false && grid[r][c] == '1')
                    {
                        visited[r][c] = true;
                        q.push({r, c});
                    }
            }
        }
     }

  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {

    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visited[i][j] == false && grid[i][j] == '1')
            {
                count++;
                
                bfs(i, j, visited, grid);
            }
        }
    }

    return count;
        
    }
}


//DFS (LC)
class Solution {
    
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid, int n, int m)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == true || grid[i][j] == '0')
            return;
        
        
        visited[i][j] = true;
        
         dfs(i, j + 1, visited, grid, n, m);
         dfs(i, j - 1, visited, grid, n, m);
         dfs(i - 1, j, visited, grid, n, m);
         dfs(i + 1, j, visited, grid, n, m);
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visited[i][j] == false && grid[i][j] == '1')
                {
                    count++;

                    dfs(i, j, visited, grid, n, m);
                }
            }
        }

        return count;
    }
};
