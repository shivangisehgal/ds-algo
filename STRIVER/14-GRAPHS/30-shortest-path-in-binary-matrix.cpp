//CN - 4 DIR.
//LC - 8 DIR.

//Brute: Recursion
//TC: O(4*M*N)

int rec(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>>& visited, int m, int n, int dr, int dc)
{
    if(i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] == 0 || visited[i][j] == true)
        return -1;
    

    if(i == dr && j == dc)
        return 0;

    visited[i][j] = true;
    
    int ans = INT_MAX;

    int u = rec(i - 1, j, matrix, visited, m, n, dr, dc);
    if(u != -1)
        ans = min(ans, u);

    int d = rec(i + 1, j, matrix, visited, m, n, dr, dc);
    if(d != -1)
        ans = min(ans, d);

    int l = rec(i, j - 1, matrix, visited, m, n, dr, dc);
    if(l != -1)
        ans = min(ans, l);

    int r = rec(i, j + 1, matrix, visited, m, n, dr, dc);
    if(r != -1)
        ans = min(ans, r);

    visited[i][j] = false;

    if(ans == INT_MAX)
        return -1;

    return (1 + ans);

}

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
    // Write your code here
    int i = src.first;
    int j = src.second;

    int dr = dest.first;
    int dc = dest.second;

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false)); 

    return rec(i, j, matrix, visited, m, n, dr, dc);
}


//BFS
//Use a distance matrix
//TC: O(4*M*N)
#include<bits/stdc++.h>

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
    // Write your code here
   
    int source_row = src.first;
    int source_col = src.second;

    int dest_row = dest.first;
    int dest_col = dest.second;

    if(matrix[source_row][source_col] == 0)
        return -1;

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); 
    dist[source_row][source_col] = 0;

    int dr[4] = {-1, 0, 0, 1};
    int dc[4] = {0, -1, 1, 0};

    queue<pair<int, int>> q;
    q.push({source_row, source_col});

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        int row = p.first;
        int col = p.second;

        if(row == dest_row && col == dest_col)
            return dist[row][col];

        for(int i = 0; i < 4; i++)
        {
            int r = row + dr[i];
            int c = col + dc[i];

            if(r >= 0 && c >= 0 && r < m && c < n && matrix[r][c] != 0)
            {
                if(1 + dist[row][col] < dist[r][c])
                {
                    dist[r][c] = 1 + dist[row][col];
                    q.push({r, c});
                }
            }
        }
    }

    if(dist[dest_row][dest_col] == INT_MAX)
        return -1;
    else
        return dist[dest_row][dest_col];
}

//LC
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int source_row = 0;
        int source_col = 0;
        
        int m = grid.size();
        int n = grid[0].size();

        int dest_row = m - 1;
        int dest_col = n - 1;

        if(grid[source_row][source_col] == 1) //can only travel on 1s
            return -1;
        
        if(grid[dest_row][dest_col] == 1) //can only travel on 1s
            return -1;


        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); 
        dist[source_row][source_col] = 1;

        queue<pair<int, int>> q;
        q.push({source_row, source_col});

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();

            int row = p.first;
            int col = p.second;

            if(row == dest_row && col == dest_col)
                return dist[row][col];
            
            for(int r = max(0, row - 1); r <= min(m - 1, row + 1); r++)
            {
                for(int c = max(0, col - 1); c <= min(n - 1, col + 1); c++)
                {
                    if(grid[r][c] == 0)
                    {
                        if(1 + dist[row][col] < dist[r][c])
                        {
                            dist[r][c] = 1 + dist[row][col];
                            q.push({r, c});
                        }
                    }
                }
            }
            
        }

        if(dist[dest_row][dest_col] == INT_MAX)
            return -1;
        else
            return dist[dest_row][dest_col];
        
    }
};
