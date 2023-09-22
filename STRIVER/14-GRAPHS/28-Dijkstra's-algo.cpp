//TC: O(ElogV) //where E = max edges in graph (= v * v - 1)
//M1 - using min heap

vector<int> dijkstra(vector<vector<int>> &edge, int n, int edges, int source)
{
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    minHeap.push({0, source});

    while(!minHeap.empty())
    {
        auto p = minHeap.top();
        minHeap.pop();

        int node = p.second;
        int parentDist = p.first;

        for(auto it : adj[node])
        {
            int neighbour = it.first;
            int wt = it.second;

            if(dist[neighbour] > parentDist + wt)
            {
                dist[neighbour] = parentDist + wt;
                minHeap.push({parentDist + wt, neighbour});
            } 
        }
    }
    
    return dist;
}

//M2 - using set
vector<int> dijkstra(vector<vector<int>> &edge, int n, int edges, int source)
{
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    set<pair<int,int>> orderedSet;

    orderedSet.insert({0, source});

    while(!orderedSet.empty())
    {
        auto it = *(orderedSet.begin());
        orderedSet.erase(it);

        int node = it.second;
        int parentDist = it.first;

        for(auto adjIt : adj[node])
        {
            int neighbour = adjIt.first;
            int wt = adjIt.second;

            if(dist[neighbour] > parentDist + wt)
            {
                if(dist[neighbour] != INT_MAX)
                    orderedSet.erase({dist[neighbour], neighbour});
            
                dist[neighbour] = parentDist + wt;
                orderedSet.insert({parentDist + wt, neighbour});
            } 
        }
    }
    
    return dist;
}
