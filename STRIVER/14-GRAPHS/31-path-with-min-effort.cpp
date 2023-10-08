//TC: O(4MN * LOG(MN))
//SC: O(MN)

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        
        int source_row = 0;
        int source_col = 0;

        int dest_row = m - 1;
        int dest_col = n - 1;

        int dr[4] = {-1, 0, 0, 1};
        int dc[4] = {0, -1, 1, 0};

        
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX)); 
        effort[source_row][source_col] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({0, {source_row, source_col}});
        
        while(!minHeap.empty())
        {
            auto f = minHeap.top();
            minHeap.pop();

            int row = f.second.first;
            int col = f.second.second;
            
            int dist = f.first;

            for(int i = 0; i < 4; i++)
            {
                int r = row + dr[i];
                int c = col + dc[i];

                if(r >= 0 && c >= 0 && r < m && c < n)
                {
                    int wt = abs(heights[row][col] - heights[r][c]);
                    
                    if(max(wt, dist) < effort[r][c])
                    {
                        effort[r][c] = max(wt, dist);
                        minHeap.push({max(wt, dist), {r, c}});
                    }
                }
            }
        }

      return effort[dest_row][dest_col];
    }
};
