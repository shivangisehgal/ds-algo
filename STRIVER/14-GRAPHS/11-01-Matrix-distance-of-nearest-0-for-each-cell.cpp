//TC: O(N*M + N*M*4) ~= O(N * M)
//SC: 3* O(N * M)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> distance(m, vector<int>(n));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int dr[4] = {-1, 0, 0 , 1};
        int dc[4] = {0, -1, 1, 0};
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            int row = p.first.first;
            int col = p.first.second;
            int dist = p.second;
            
            for(int i = 0; i < 4; i++)
            {
                int r = row + dr[i];
                int c = col + dc[i];
                
                if(r >= 0 and c >= 0 and r < m and c < n and visited[r][c] == false)
                {
                    visited[r][c] = true;
                    
                    if(mat[r][c] == 0)
                    {
                        distance[r][c] = 0;
                    }
                    
                    else
                    {
                         distance[r][c] = dist + 1;
                         q.push({{r, c}, dist + 1});
                    }
                }
            }
        }
        
        
        return distance;
    }
};
