//Refer handwritten notes

#include<stack>

void dfs(int node, stack<int>& topoSort, vector<int>& visited, vector<vector<pair<int, int>>>& adjList)
{
    if(visited[node] == 0)
    {
        visited[node] = 1;

        for(auto neighbour_wt : adjList[node])
        {
            dfs(neighbour_wt.first, topoSort, visited, adjList);
        }

        topoSort.push(node);
    }
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    //create a DAG
    vector<vector<pair<int, int>>> adjList(n);

    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adjList[u].push_back({v, wt});
    }

    stack<int> topoSort;
    vector<int> visited(n, 0);

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
            dfs(i, topoSort, visited, adjList);
    }

    //topo sort: 0 1 2

    vector<int> dist(n, INT_MAX);

    int source_node = 0; //NOTE: QUESTION STATES SOURCE NODE IS 0.
    
    dist[source_node] = 0;

    while(!topoSort.empty() && topoSort.top() != source_node)
        topoSort.pop(); //because we can't reach these nodes FROM source node

    while(!topoSort.empty())
    {
        int node = topoSort.top();
        topoSort.pop();

        for(auto neighbour_wt : adjList[node])
        {
            int neighbour = neighbour_wt.first;
            int wt = neighbour_wt.second;

            if(dist[node] == INT_MAX)
                continue;

            else if(dist[node] + wt < dist[neighbour])
                dist[neighbour] = dist[node] + wt;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(dist[i] == INT_MAX)
            dist[i] = -1;
    }

    return dist;
}
