simple bfs

vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
    vector<vector<int>> adjList(n);

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> dist(n, INT_MAX);

    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int neighbour : adjList[node])
        {
            if (dist[neighbour] == INT_MAX) 
            { 
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
         if(dist[i] == INT_MAX) 
            dist[i] = -1;
    }

    return dist;
}
