//Simply implying that a graph has a cycle if are re-visiting a vertex, is wrong.
//While backtracking, we are bound re-visit the parent of the vertex (refer handwritten notes)
//So, pass a parent variable as well, once we encounter a neighbour that has already been visited and it is no the parent of the vertex
//This means, we have detected a cycle!

//TC: O(N + 2E) + O(N) as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.
//SC: O(N)

bool dfs(int vertex, int parent, vector<bool> visited, vector<vector<int>>& adjList)
{

    visited[vertex] = true;

    for(int neighbour : adjList[vertex])
    {
            if(visited[neighbour] == false)
            {
                if(dfs(neighbour, vertex, visited, adjList) == true)
                    return true;
            }
            
            else if(neighbour != parent)
                return true;
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
            if(dfs(i, 0, visited, adjList) == true)
                return "Yes";
        }
    }

    return "No";
}
