#include <queue>
bool bfs(int vertex, vector<bool> visited, vector<vector<int>>& adjList)
{

    visited[vertex] = true;

    queue<pair<int, int>> q;
    q.push({vertex, 0});

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        int node = p.first;
        int parent = p.second;

        for(auto neighbour : adjList[node])
        {
            if(visited[neighbour] == false)
            {
                visited[neighbour] = true;
                q.push({neighbour, node});
            }

            else if(neighbour != parent)
                return true;
        }
    }

    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adjList(n + 1);
    
    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            if(bfs(i, visited, adjList) == true)
                return "Yes";
        }
        
    }
    return "No";
}
