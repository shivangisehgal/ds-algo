//A bipartite graph is one, when colored using two colors, it can be done so such that no two adjacent nodes have the same color.
//TC: O(N + 2E)

class Solution {
    
    bool bfs(int start, vector<int>& color, vector<vector<int>>& graph)
    {
        queue<int> q;
        
        q.push(start);
        color[start] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
                        
            for(int neighbour : graph[node])
            {
                if(color[neighbour] == -1)
                {
                    q.push(neighbour);
                    color[neighbour] = !color[node];
                }
                
                else if(color[neighbour] == color[node])
                    return false;
            }
        }
        
        return true;
    }
    
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        //graph is the adjacency list
        
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(bfs(i, color, graph) == false)
                    return false;
            }
        }
        
        return true;
    }
};
